#pragma once
#include <string>
#include <unordered_map>
#include "CTickRecord.h"

struct tickIndex
{

};


//tickdb is the container of all symbol and related records
class CTickRepository
{
public:
	CTickRepository(const std::string& filename, const bool bOptimizePrint,	const bool bOptimizeProduct);
	~CTickRepository();

	void print(const std::string& symbol, time_t startts, time_t endts);
	void product(const std::string& symbol, time_t startts, time_t endts, const std::string& field1, const std::string& field2);
private:
	void loadTickRecord(const std::string& line);
	void loadFile(const std::string& fieldListFilename);

	std::unordered_map <std::string, CTickRecord> _tickRecords;
	
	
	const bool _bOptimizePrint;
	const bool _bOptimizeProduct;
};

