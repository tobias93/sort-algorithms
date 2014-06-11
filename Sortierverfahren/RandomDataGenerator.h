#pragma once
#include "DataGenerator.h"
#include "DataGenerator.cpp"

template <class dataType>
class RandomDataGenerator :
	public DataGenerator < dataType >
{
public:
	RandomDataGenerator();
	~RandomDataGenerator();
	DataArray<dataType> generate() { return DataGenerator::generate() };
};
