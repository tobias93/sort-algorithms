#pragma once
#include "DataGenerator.h"
#include "DataGenerator.cpp"

template <class dataType>
class DescendingNumbersDataGenerator :
	public DataGenerator < dataType >
{
public:
	DescendingNumbersDataGenerator();
	~DescendingNumbersDataGenerator();
	DataArray<dataType> generate() { return DataGenerator::generate() };
};

