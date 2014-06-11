#pragma once

#include "stdafx.h"
#include "DataGenerator.h"


template <class dataType>
DataGenerator<dataType>::DataGenerator()
{
	this->setCount(0);
}


template <class dataType>
DataGenerator<dataType>::~DataGenerator()
{
}

//---- Getter / Setter ----------------------------------------

template <class dataType>
void DataGenerator<dataType>::setCount(unsigned int count)
{
	this->count = count;
}

template <class dataType>
unsigned int DataGenerator<dataType>::getCount() const
{
	return this->count;
}

//---- Methoden ---------------------------------------------

template <class dataType>
DataArray<dataType> DataGenerator<dataType>::generate()
{
	throw "This data type is not supportet by this DataGenerator";
}


template <class dataType>
void DataGenerator<dataType>::configureInteractive(ostream& cout, istream& cin)
{
	unsigned int number;
	cout << "Number of Elements to sort: ";
	cin >> number;
	this->setCount(number);
}
