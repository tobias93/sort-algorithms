#include "stdafx.h"
#include "RandomDataGenerator.h"
#include <stdlib.h>
#include <time.h>

//---- Konstruktor / Dekonstruktor --------------------------------

template <class dataType>
RandomDataGenerator<dataType>::RandomDataGenerator()
{
}


template <class dataType>
RandomDataGenerator<dataType>::~RandomDataGenerator()
{
}

//---- Methoden ---------------------------------------------------

DataArray<int> RandomDataGenerator<int>::generate()
{
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
		data[i] = rand();
	}
	return data;
}
