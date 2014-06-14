#pragma once
#include <iostream>
#include "DataArray.h"
#include "DataArray.cpp"

using namespace std;

template <class dataType>
class DataGenerator
{
private:
	unsigned int count;
public:
	DataGenerator();
	virtual ~DataGenerator();
	void setCount(unsigned int);
	unsigned int getCount() const;
	virtual DataArray<dataType> generate();
	virtual void configureInteractive(ostream&, istream&);
};

