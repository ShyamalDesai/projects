#pragma once
#include <string>
#include <vector>
#include <map>
#include "CFieldList.h"

//The tick record stores a hash map of field names and values (the key is name (a string :-( ) and value is a double)

//_tsToAllFieldValueString: This DS is used to store a string of all fields and values as a string for a given time stamp
//this helps us print out all the field value as 1 string. This is used when optimizing the print command 

//the id is the index into the array where a corresponding continuous string of all fields and their values is stored
//this string of field value is only stored if we need to optimize the printing of the name value pairs
typedef std::pair<uint32_t, CFieldList <std::string, double> > IDTOFIELDS;



class CTickRecord
{
public:
	CTickRecord(const bool bOptimizePrint = false, const bool bOptimizeProduct = false);
	~CTickRecord();

	void addRecord(const time_t ts, const std::string& fieldName, const std::string& value);
	void printRecords(const time_t start, const time_t end) const ;
	void printProduct(const time_t start, const time_t end, const std::string& fieldName1,	const std::string& fieldName2) ;

private:
	std::string _symbol;
	bool _bOptimizePrint;
	bool _bOptimizeProduct;

	//store all field-values for a given timestamp as 1 string (to ease pringing
	std::vector<std::string> _tsToAllFieldValueString;

	//a map for ts to [cacheid for all field-values, CFieldList class that has a hash for field name to value]
	std::map <time_t, IDTOFIELDS> _tsToFields;

	//timestamp to a map with key of Timestamp+field1+field2 to the product of field1 and field2
	//if there are 10 fields, then to cache all products between fields we will need (10 2) = 10!/(10-2)!*2! = 45 entries per timestamp
	//it will exponentially increase if the number of fields increase
  
	//so we can cache the most likely fields like price and size and cache it and then whenever a new product is requested between 2 fields
	//the most recently used cache should have a good algo to purge older records when we reach a particular size: NOT IMPLEMENTED
	//THE KEY is a combination of Timestamp/Field1/Field2: 
	std::unordered_map <std::string, double> _tsF1F2ToFieldProduct;

	int _tsToAllFieldsIndex;
};

