#include "stdafx.h"
#include "DescendingNumbersDataGenerator.h"


template <class dataType>
DescendingNumbersDataGenerator<dataType>::DescendingNumbersDataGenerator()
{
}


template <class dataType>
DescendingNumbersDataGenerator<dataType>::~DescendingNumbersDataGenerator()
{
}

DataArray<int> DescendingNumbersDataGenerator<int>::generate() {
	DataArray<int> data;
	data.allocateData(this->getCount());
	for (unsigned int i = 0; i < this->getCount(); i++)
	{
		data[i] = this->getCount() - i - 1;
	}
	return data;
}
