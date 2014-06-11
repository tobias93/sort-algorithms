#include "stdafx.h"
#include "RandomRangeDataGenerator.h"
#include <stdlib.h>
#include <time.h>

//---- Konstruktor / Destruktor ------------------------------------------------------------

template <class dataType>
RandomRangeDataGenerator<dataType>::RandomRangeDataGenerator()
{
}


template <class dataType>
RandomRangeDataGenerator<dataType>::~RandomRangeDataGenerator()
{
}

//---- Getter / Setter ------------------------------------------------------------------------

template <class dataType>
dataType RandomRangeDataGenerator<dataType>::getMin() const
{
	return this->min;
}

template <class dataType>
void RandomRangeDataGenerator<dataType>::setMin(dataType min)
{
	this->min = min;
}

template <class dataType>
dataType RandomRangeDataGenerator<dataType>::getMax() const
{
	return this->max;
}

template <class dataType>
void RandomRangeDataGenerator<dataType>::setMax(dataType max)
{
	this->max = max;
}

//---- Methoden -------------------------------------------------------------------------------

template <class dataType>
void RandomRangeDataGenerator<dataType>::configureInteractive(ostream& cout, istream& cin)
{
	DataGenerator::configureInteractive(cout, cin);
	
	dataType min;
	dataType max;

	cout << "Minimum random number: ";
	cin >> min;

	cout << "Maximum random number: ";
	cin >> max;

	this->setMin(min);
	this->setMax(max);
}

DataArray<int> RandomRangeDataGenerator<int>::generate()
{
	//validate:  min <= max
	if (this->getMin() > this->getMax())
	{
		throw "Min must be <= Max.";
	}

	//Init Random number generator
	time_t t;
	time(&t);
	srand((unsigned int)t);

	//allocate memory
	DataArray<int> data;
	data.allocateData(this->getCount());

	//fill array with random numbers
	for (unsigned int i = 0; i < this->getCount(); i++)
	{
		data[i] = (rand() % (this->getMax() - this->getMin() + 1)) + this->getMin();
	}
	return data;
}