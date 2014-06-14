#pragma once
#include "DataGenerator.h"
#include "DataGenerator.cpp"

template <class dataType>
class AscendingNumbersDataGenerator :
	public DataGenerator < dataType >
{
public:
	AscendingNumbersDataGenerator();
	~AscendingNumbersDataGenerator();
	DataArray<dataType> generate() { return DataGenerator::generate() };
};

