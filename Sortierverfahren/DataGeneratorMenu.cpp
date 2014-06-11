#include "stdafx.h"
#include "DataGeneratorMenu.h"

#include "RandomDataGenerator.h"
#include "RandomDataGenerator.cpp"
#include "RandomRangeDataGenerator.h"
#include "RandomRangeDataGenerator.cpp"

//---- Konstruktor / Dekonstruktor ------------------------------------

template <class dataType>
DataGeneratorMenu<dataType>::DataGeneratorMenu()
{
}

template <class dataType>
DataGeneratorMenu<dataType>::~DataGeneratorMenu()
{
}

//---- Protecte (Menu implementation) ---------------------------------

template <class dataType>
char** DataGeneratorMenu<dataType>::getEntries(unsigned int& entriesCount) const
{
	entriesCount = 2;
	char** menu = (char**)malloc(entriesCount * sizeof(char*));
	menu[0] = _strdup("Random numbers");
	menu[1] = _strdup("Random numbers between a and b");
	return menu;
}

template <class dataType>
DataGenerator<dataType>* DataGeneratorMenu<dataType>::getResultForSelectedIndex(unsigned int selectedIndex) const
{
	switch (selectedIndex)
	{
	case 0:
		return new RandomDataGenerator<dataType>();
		break;
	case 1:
		return new RandomRangeDataGenerator<dataType>();
		break;
	default:
		throw 0;
	}
}

template <class dataType>
DataGenerator<dataType>* DataGeneratorMenu<dataType>::getResultForWrongInput() const
{
	return new RandomDataGenerator<dataType>();
}

template <class dataType>
char* DataGeneratorMenu<dataType>::getTitle() const
{
	return "Select the type of data you want to sort:";
}