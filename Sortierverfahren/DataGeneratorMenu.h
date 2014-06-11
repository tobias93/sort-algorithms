#pragma once

#include "Menu.h"
#include "Menu.cpp"
#include "DataGenerator.h"
#include "DataGenerator.cpp"

template <class dataType>
class DataGeneratorMenu :
	public Menu< DataGenerator<dataType>* >
{
private:
	char** getEntries(unsigned int& entriesCount) const;
	DataGenerator<dataType>* getResultForSelectedIndex(unsigned int selectedIndex) const;
	DataGenerator<dataType>* getResultForWrongInput() const;
	char* getTitle() const;
public:
	DataGeneratorMenu();
	~DataGeneratorMenu();
};

