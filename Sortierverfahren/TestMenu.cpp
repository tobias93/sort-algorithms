#include "stdafx.h"
#include "TestMenu.h"
#include <string>

TestMenu::TestMenu()
{
}


TestMenu::~TestMenu()
{
}

//---- Protected: Implement the content of the menu ----------------

char** TestMenu::getEntries(unsigned int& entriesCount) const
{
	entriesCount = 5;
	char** entries = (char**)malloc(entriesCount * sizeof(char*));
	entries[0] = _strdup("Lorem");
	entries[1] = _strdup("Ipsum");
	entries[2] = _strdup("Dolor");
	entries[3] = _strdup("Sit");
	entries[4] = _strdup("Amet.");
	return entries;
}

int TestMenu::getResultForSelectedIndex(unsigned int selectedIndex) const
{
	return selectedIndex;
}

int TestMenu::getResultForWrongInput() const
{
	return -1;
}

char* TestMenu::getTitle() const
{
	return "Select an Option:";
}