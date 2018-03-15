#pragma once

#include <unordered_map>
#include <iostream>
/**
*	The FieldList class should be a singleton that loads all the field names from a file
*   and indexes it, so that the application can use an id instead of the field name
*
*/
//enum FieldType { CHAR=0, STRING, UINT16T, INT16T, INT32T, UINT32T, INT64T, UINT64T, DOUBLE};

template <typename KEY, typename VALUE>
class CFieldList
{
public:
	CFieldList(const bool bOptimizeProduct = false) 
	: _bOptimizeProduct(bOptimizeProduct)
	{}
	~CFieldList() {}

	//void addField(KEY name, VALUE&& value);
	void addField(KEY name, VALUE value);
	bool getValue(const KEY key, VALUE& value) const ;
	void printAll() const;

private:
	std::unordered_map <KEY, VALUE> _fieldNameValue;
	//cache of products makes more sense here
	std::unordered_map< std::string, std::unordered_map <std::string, double> > _fieldProductCache;
	const bool _bOptimizeProduct;
};


//void addField(KEY name, VALUE&& value);
template <typename KEY, typename VALUE>
void
CFieldList<KEY, VALUE>::addField(KEY name, VALUE value)
{
	_fieldNameValue[name] = value;
}


template <typename KEY, typename VALUE>
bool
CFieldList<KEY, VALUE>::getValue(const KEY key, VALUE& value) const
{
	bool bRet(false);

	typename std::unordered_map <KEY, VALUE>::const_iterator citr = _fieldNameValue.find(key);
	if (citr != _fieldNameValue.cend())
	{
		value = citr->second;
		bRet = true;
	}
	return bRet;
}


template <typename KEY, typename VALUE>
void
CFieldList<KEY, VALUE>::printAll() const 
{
	typename std::unordered_map <KEY, VALUE>::const_iterator begin = _fieldNameValue.cbegin();
	typename std::unordered_map <KEY, VALUE>::const_iterator end = _fieldNameValue.cend();
	typename std::unordered_map <KEY, VALUE>::const_iterator citr;
	for (citr = begin; citr != end; ++citr)
	{
		std::cout << citr->first << "\t:\t" << citr->second << std::endl;
	}
}
