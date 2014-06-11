#pragma once
#include "DataGenerator.h"
#include "DataGenerator.cpp"

template <class dataType>
class RandomRangeDataGenerator :
	public DataGenerator < dataType >
{
private:
	dataType min;
	dataType max;
public:
	RandomRangeDataGenerator();
	~RandomRangeDataGenerator();
	dataType getMin() const;
	void setMin(dataType);
	dataType getMax() const;
	void setMax(dataType);
	DataArray<dataType> generate() { return DataGenerator::generate() };
	void configureInteractive(ostream&, istream&);
};

