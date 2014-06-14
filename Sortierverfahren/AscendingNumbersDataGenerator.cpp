#include "stdafx.h"
#include "AscendingNumbersDataGenerator.h"


template <class dataType>
AscendingNumbersDataGenerator<dataType>::AscendingNumbersDataGenerator()
{
}


template <class dataType>
AscendingNumbersDataGenerator<dataType>::~AscendingNumbersDataGenerator()
{
}

DataArray<int> AscendingNumbersDataGenerator<int>::generate()
{
	DataArray<int> data;
	data.allocateData(this->getCount());
	for (unsigned int i = 0; i < this->getCount(); i++)
	{
		data[i] = i;
	}
	return data;
}