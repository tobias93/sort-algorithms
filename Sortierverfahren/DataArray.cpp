#pragma once
#include "stdafx.h"
#include "DataArray.h"

//---- Private ----------------------------------------------------

template <class dataType>
void DataArray<dataType>::init()
{
	this->data = NULL;
	this->length = 0;
}

template <class dataType>
void DataArray<dataType>::copy(const DataArray<dataType>& dataArray)
{
	this->setData(dataArray.getData(), dataArray.getLength());
}

//---- Konstruktor / Dekonstruktor --------------------------------

//std-constructor
template <class dataType>
DataArray<dataType>::DataArray()
{
	this->init();
}

//copy-constructor
template <class dataType>
DataArray<dataType>::DataArray(const DataArray<dataType>& dataArray)
{
	this->init();
	this->copy(dataArray);
}

//destructor
template <class dataType>
DataArray<dataType>::~DataArray()
{
	delete this->data;
}

//---- Getter / Setter ------------------------------------------

//returns the number of stored data-elements
template <class dataType>
unsigned int DataArray<dataType>::getLength() const
{
	return this->length;
}

//returns the stored data
template <class dataType>
dataType* DataArray<dataType>::getData() const
{
	return this->data;
}

//copies the given data into the dataArray
template <class dataType>
void DataArray<dataType>::setData(dataType* data, unsigned int length)
{
	this->allocateData(length);
	for (unsigned int i = 0; i < length; i++)
	{
		this->data[i] = data[i];
	}
}

//---- Methoden ---------------------------------------------------------

//allocates memory for n data-elements
template <class dataType>
void DataArray<dataType>::allocateData(unsigned int length)
{
	delete this->data;
	this->length = length;

	if (length == 0)
	{
		this->data = NULL;
	}
	else
	{
		this->data = (dataType*)malloc(sizeof(dataType*) * length);
	}
}

//---- Operatoren -------------------------------------------------------

//operator <<
template<class dataType>
std::ostream& operator<<(std::ostream& cout, const DataArray<dataType>& data)
{
	cout << '[';
	for (unsigned int i = 0; i < data.getLength(); i++)
	{
		cout << '\t' << data.getData()[i];
	}
	cout << "\t]";
	return cout;
}

//operator =
template <class dataType>
void DataArray<dataType>::operator=(const DataArray<dataType>& dataArray)
{
	this->copy(dataArray);
}

//operator []
template <class dataType>
dataType& DataArray<dataType>::operator[](unsigned int element)
{
	return this->getData()[element];
}
