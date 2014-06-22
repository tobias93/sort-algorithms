#include "stdafx.h"
#include "RadixSorter.h"
#include <math.h>

//---- Private --------------------------------------------

template<class sortType>
unsigned int RadixSorter<sortType>::getDigit(unsigned int number, char digitPosition)
{
	number = number / (unsigned int)pow(this->getBase(), digitPosition);
	return number % this->getBase();
}

//---- Konstruktor / Destruktor ---------------------------

template<class sortType>
RadixSorter<sortType>::RadixSorter()
{
	this->setBase(2);
}


template<class sortType>
RadixSorter<sortType>::~RadixSorter()
{
}

//---- Getter / Setter ------------------------------------

template<class sortType>
unsigned int RadixSorter<sortType>::getBase() const
{
	return this->base;
}

template<class sortType>
void RadixSorter<sortType>::setBase(unsigned int base)
{
	if (base == 0 || base == 1)
	{
		throw "Base must not be 0 or 1";
	}
	this->base = base;
}

template<class sortType>
char RadixSorter<sortType>::getMaxKeyLength() const
{
	return this->maxKeyLength;
}

template<class sortType>
void RadixSorter<sortType>::setMaxKeyLength(char maxKeyLength)
{
	if (maxKeyLength == 0)
	{
		throw "MaxKeyLength must not be 0.";
	}
	this->maxKeyLength = maxKeyLength;
}

//---- Methoden -------------------------------------------

template<class sortType>
void RadixSorter<sortType>::sort(DataArray<sortType>& data_)
{
	sortType* sortedData = (sortType*)malloc(sizeof(sortType) * data_.getLength());
	unsigned int* buckets = (unsigned int*)malloc(this->getBase() * sizeof(unsigned int));

	for (char sortDigitPosition = 0; sortDigitPosition < this->getMaxKeyLength(); sortDigitPosition++)
	{
		//init buckets
		std::fill<unsigned int*, unsigned int>(buckets, &buckets[this->getBase()], 0);

		//fill buckets
		for (unsigned int i = 0; i < data_.getLength(); i++)
		{
			unsigned int key = this->getDigit((unsigned int)data_[i], sortDigitPosition);
			buckets[key]++;
		}

		//sum up buckets
		for (unsigned int i = 1; i < this->getBase(); i++)
		{
			buckets[i] = buckets[i - 1] + buckets[i];
		}

		//use buckets to order the data.
		for (unsigned int i = data_.getLength() - 1; i < data_.getLength(); i--)
		{
			unsigned int key = this->getDigit((unsigned int)data_[i], sortDigitPosition);
			buckets[key]--;
			unsigned int newPosition = buckets[key];
			sortedData[newPosition] = data_[i];
			this->countWrites(1);
		}
		data_.setData(sortedData, data_.getLength());
		this->countWrites(data_.getLength());
	}

	delete sortedData;
	delete buckets;
}

template<class sortType>
void RadixSorter<sortType>::configureInteractive(ostream& cout, istream& cin)
{
	unsigned int base = 2;
	char maxKeyLength = 1;

	cout << "Base: ";
	cin >> base;
	this->setBase(base);
	cout << "Maximal keylength: ";
	cin >> maxKeyLength;
	this->setMaxKeyLength(maxKeyLength);
}