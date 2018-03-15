
#include "CTickRecord.h"
#include <string>
#include <stdexcept>
#include "Util.h"
#include <sstream>

#define OPTIMIZEPRINTFOR	100
//for each symbol caches 100 ts and related field-values as string
//1000 symbols will have 100000 entries (cached)
//--------------------------------------------------------------------------------------------------
CTickRecord::CTickRecord(const bool bOptimizePrint , const bool bOptimizeProduct)
	: _bOptimizePrint (bOptimizePrint)
	, _bOptimizeProduct(bOptimizeProduct)
	, _tsToAllFieldsIndex(0)
{
	_tsToAllFieldValueString.reserve((bOptimizePrint == true ? OPTIMIZEPRINTFOR : 1));
	
}


//--------------------------------------------------------------------------------------------------
CTickRecord::~CTickRecord()
{
}



//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
void 
CTickRecord::addRecord(const time_t ts, 
				const std::string& fieldName, 
				const std::string& value)
{
	//no point adding anything if the value is not convertible to double
	double dblvalue(0.0);
	if (!Util::strtod(value, dblvalue)) //no point in inserting an empty field name and value if coverting the field value failed
		return;

//----------------------------------------------------------------------------------------------------
	//add a new record
//----------------------------------------------------------------------------------------------------
	std::map <time_t, IDTOFIELDS >::iterator itr = _tsToFields.find(ts);
	if (itr == _tsToFields.end())
	{
		//new record
		
		if (_bOptimizePrint)
		{
			//cache for all fields for a given timestamp
			_tsToAllFieldValueString.push_back("\n" + fieldName + "\t:\t" + value);
		}

		CFieldList<std::string, double> newList;
		newList.addField(fieldName, dblvalue);
		_tsToFields.insert(std::make_pair(ts, std::make_pair(_tsToAllFieldsIndex++, newList))); // a pair for id to fieldlist and then a pair from timestamp to id-fieldlist record
		
	}
	else
	{
//----------------------------------------------------------------------------------------------------
	//update existing record
//----------------------------------------------------------------------------------------------------

		//record already present: update 
		//itr contains a valid record and a new field needs to be added
		IDTOFIELDS& idtofields = itr->second;
		idtofields.second.addField(fieldName, dblvalue);
		//use the id to update the 
		if (_bOptimizePrint)
		{
			//update cache for all fields
			std::string& str = _tsToAllFieldValueString[(int)idtofields.first];
			str += "\n" + fieldName + "\t:\t" + value ;
		}
	}
	
}



//----------------------------------------------------------------------------------------------------
//print from start to end timestamps. the start timestamp might not be present.
//this is the reason we have to use std::map instead of a hash map so that we can get an upper bound on start timestamp.
//cannot get that on unordered_map

//we could have used 2 vectors (1 vector for keys and other parallel vector for values)
//however, lookup for upper bound would still be log n. using vectors is more cache friendly due to contiguos locations

//if we have already cached (-Oprint) the field name  and values as a string, then we directly print that string 
//just iterate over the timestamps, look up the id in the cache to get the list of fields/values as a string. (not fieldlist iteration). Only the iteration of the timestamps (O(n))

//else we have to use printAll of FieldList class that will iterare over all the fields and print their name value ( O(n) for field/value printing, total O(n^2) due to iteration of timestamps and fields)
//----------------------------------------------------------------------------------------------------

void 
CTickRecord::printRecords(const time_t start, 
			const time_t end) const
{
///----------------------------input validation
	//if end is 0, then we should print everything from start onwards
	if (start == 0 && end == 0)
		return;
	if (end > 0 && start > end)
	{
		return;
	}

///----------------------------input validation


///---------------------logN lookup for start : can be 2LogN if start not found (using upper bound)
	std::map <time_t, IDTOFIELDS >::const_iterator citr = _tsToFields.find(start); //logN lookup
	if (citr == _tsToFields.end())
	{
		citr = _tsToFields.upper_bound(start);
	}
///---------------------logN lookup for start : can be 2LogN if start not found (using upper bound)

//-----------------------------(N iterations for start timestamp till end)
	while (citr != _tsToFields.end()) //N iterations
	{
		if (end != 0 && citr->first > end)
			break;
//-------------------const lookup O(1) making it overall O(NlogN)
		if (_bOptimizePrint) 
		{
			std::cout << std::endl <<"Timestamp\t" << citr->first << std::endl;
			std::cout << _tsToAllFieldValueString[citr->second.first].c_str();
			std::cout << std::endl << "-------------------------------------" << std::endl;
//-------------------const lookup O(1) making it overall O(NlogN)
		}
		else
		{
//-----------------------------N iterations again making it overall O(n^2)
			const IDTOFIELDS& idtoFields = citr->second;
			std::cout << "Timestamp\t" << citr->first << std::endl;
			idtoFields.second.printAll();
			std::cout << "-------------------------------------" << std::endl;
		}
		++citr;
//-----------------------------N iterations again making it overall O(n^2)
	}
}

//------------------------------------------------------------------------------------------------
//
//overall complexity is NLogN
void
CTickRecord::printProduct(const time_t start,
							const time_t end,
							const std::string& fieldName1,
							const std::string& fieldName2)
{
	///----------------------------input validation
	if (start == 0 && end == 0)
		return;

	if (end > 0 && start > end)
		return;

	if (fieldName1.empty() || fieldName2.empty())
		return;

	///----------------------------input validation

	///---------------------logN lookup for start : can be 2LogN if start not found (using upper bound)
	std::map <time_t, IDTOFIELDS >::iterator citr = _tsToFields.find(start);	//log N lookup
	if (citr == _tsToFields.end())
	{
		citr = _tsToFields.upper_bound(start);
	}
	///---------------------logN lookup for start : can be 2LogN if start not found (using upper bound)
	double sum = 0.0;
	//-----------------------------(N iterations for start timestamp till end)
	while (citr != _tsToFields.end())
	{
		if (end != 0 && citr->first > end)
			break;

		std::stringstream key;
		std::cout << "Timestamp\t" << citr->first << std::endl;
		if (_bOptimizeProduct)//can save 1 lookup
		{
			key << citr->first << fieldName1 << fieldName1;
			std::unordered_map <std::string, double>::iterator cacheItr = _tsF1F2ToFieldProduct.find(key.str());
			if (cacheItr != _tsF1F2ToFieldProduct.end())
			{
				std::cout << "product of " << fieldName1.c_str() << " and " << fieldName2.c_str() << " is " << cacheItr->second;
				sum += (cacheItr->second);
				std::cout << std::endl << "-------------------------------------" << std::endl;
				continue;
			}
		}

		IDTOFIELDS& idtoFields = citr->second;
		
		double value1 = 1.0;
		double value2 = 1.0;

		//------------------------------------------------log N lookup
		idtoFields.second.getValue(fieldName1, value1);
		idtoFields.second.getValue(fieldName2, value2);

		//------------------------------------------------log N lookup
		double product = 0;
		if (value1 != 1 && value2 != 1)
			product = value1 * value2;

		std::cout << "product of " << fieldName1.c_str() << " and " << fieldName2.c_str() << " is " << product;
		sum += (product);

		if (_bOptimizeProduct) //key is already calculated, so we can update the cache
			_tsF1F2ToFieldProduct.insert(std::make_pair(key.str(), product));
		
		std::cout << std::endl << "-------------------------------------" << std::endl;
		++citr;
	}
	//-----------------------------(N iterations for start timestamp till end)

	std::cout << " The sum of product of " << fieldName1.c_str() << " and " << fieldName2.c_str() << " for start ts " << start << " and end ts " << end << " is " << sum << std::endl;
	std::cout << std::endl << "-------------------------------------" << std::endl;
	
}
