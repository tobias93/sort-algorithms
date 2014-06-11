#pragma once
#include "Menu.h"
#include "Menu.cpp"
#include "Sorter.h"
#include "Sorter.cpp"

template<class sortType>
class SortAlgorithmMenu :
	public Menu<Sorter<sortType>* >
{
protected:
	char** getEntries(unsigned int& entriesCount) const;
	Sorter<sortType>* getResultForSelectedIndex(unsigned int selectedIndex) const;
	Sorter<sortType>* getResultForWrongInput() const;
	char* getTitle() const;
public:
	SortAlgorithmMenu();
	~SortAlgorithmMenu();
};

