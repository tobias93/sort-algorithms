#pragma once
#include "Menu.h"
#include "Menu.cpp"

class TestMenu :
	public Menu < int >
{
protected:
	char** getEntries(unsigned int& entriesCount) const;
	int getResultForSelectedIndex(unsigned int selectedIndex) const;
	int getResultForWrongInput() const;
	char* getTitle() const;
public:
	TestMenu();
	~TestMenu();
};

