#pragma once
#include "Menu.h"
#include "Menu.cpp"
#include <stdbool.h>

class AddSorterQuestionMenu :
	public Menu < bool >
{
protected:
	char** getEntries(unsigned int& entriesCount) const;
	bool getResultForSelectedIndex(unsigned int selectedIndex) const;
	bool getResultForWrongInput() const;
	char* getTitle() const;
public:
	AddSorterQuestionMenu();
	~AddSorterQuestionMenu();
};

