#pragma once
#include <stdbool.h>
#include "Menu.h"
#include "Menu.cpp"

class AddDataSetQuestionMenu:
	public Menu<bool>
{
protected:
	char** getEntries(unsigned int& entriesCount) const;
	bool getResultForSelectedIndex(unsigned int selectedIndex) const;
	bool getResultForWrongInput() const;
	char* getTitle() const;
public:
	AddDataSetQuestionMenu();
	~AddDataSetQuestionMenu();
};

