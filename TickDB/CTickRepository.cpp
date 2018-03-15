
#include "CTickRepository.h"
#include <fstream>
#include <string.h>
#include "Util.h"
//-----------------------------------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------------------------------

CTickRepository::CTickRepository(const std::string& filename, 
								const bool bOptimizePrint, 
								const bool bOptimizeProduct)
	: _bOptimizePrint (bOptimizePrint)
	, _bOptimizeProduct (bOptimizeProduct)
	
{
	loadFile(filename);
}

//-----------------------------------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------------------------------

CTickRepository::~CTickRepository()
{
}

//-----------------------------------------------------------------------------------------------------------
	//
//-----------------------------------------------------------------------------------------------------------
void
CTickRepository::loadTickRecord(const std::string& line)
{
	//get all fields in an array:
	std::vector <std::string> fields = Util::split((const_cast <char*> (line.c_str())), " ,;\n");
	
	//first is always ts
	if (fields.size() >= 2)
	{
		time_t ts = strtoull(fields[0].c_str(), NULL, 10);

		if (!fields[1].empty()) //symbol is not empty
		{
			std::unordered_map <std::string, CTickRecord>::iterator itr = _tickRecords.find(fields[1]);
			if (itr == _tickRecords.end())
			{
				_tickRecords.insert(std::make_pair(fields[1], CTickRecord(_bOptimizePrint, _bOptimizeProduct)));
			}

			CTickRecord& cTickRecord = _tickRecords[fields[1]];
			size_t i = 2;//from fieldname and value
			size_t size = fields.size();
			while (i < size)
			{
				if (i + 1 < size)
					cTickRecord.addRecord(ts, fields[i], fields[i + 1]);
				else
					cTickRecord.addRecord(ts, fields[i], "0.0"); //if no value is specified
				i += 2;
			}
		
		}
	}
}


//-----------------------------------------------------------------------------------------------------------
	//
//-----------------------------------------------------------------------------------------------------------
void
CTickRepository::loadFile(const std::string& fieldListFilename)
{
	//open ifstream
	std::ifstream inFile(fieldListFilename);
	if (!inFile)
	{
		//throw exception
	}
	std::string line;
	while (std::getline (inFile, line))
	{
		//read line (csv delimited)
		loadTickRecord(line);
	}
	
}


//-----------------------------------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------------------------------
void
CTickRepository::print(const std::string& symbol, 
						time_t startts, 
						time_t endts)
{
	//starts with logN lookup for symbol to record for timestamps
	std::unordered_map <std::string, CTickRecord>::const_iterator itr = _tickRecords.find(symbol);
	if (itr != _tickRecords.end())
	{
		itr->second.printRecords(startts, endts);
	}
}

//-----------------------------------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------------------------------
void 
CTickRepository::product(const std::string& symbol,
	time_t startts,
	time_t endts,
	const std::string& field1,
	const std::string& field2)
{
	//starts with logN lookup for symbol to record for timestamps
	std::unordered_map <std::string, CTickRecord>::iterator itr = _tickRecords.find(symbol);
	if (itr != _tickRecords.end())
	{
		itr->second.printProduct(startts, endts, field1, field2);
	}

}
