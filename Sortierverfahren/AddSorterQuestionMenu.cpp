#include "stdafx.h"
#include "AddSorterQuestionMenu.h"

//---- Konstruktor / Destruktor --------------------------------------

AddSorterQuestionMenu::AddSorterQuestionMenu()
{
}


AddSorterQuestionMenu::~AddSorterQuestionMenu()
{
}

//---- Protected: Menu implementation --------------------------------

char** AddSorterQuestionMenu::getEntries(unsigned int& entriesCount) const
{
	entriesCount = 2;
	char** entries = (char**)malloc(entriesCount * sizeof(char*));
	entries[0] = _strdup("Yes, add another sort algorithm.");
	entries[1] = _strdup("No, please start sorting now.");
	return entries;
}

bool AddSorterQuestionMenu::getResultForSelectedIndex(unsigned int selectedIndex) const
{
	return selectedIndex == 0;
}

bool AddSorterQuestionMenu::getResultForWrongInput() const
{
	return false;
}

char* AddSorterQuestionMenu::getTitle() const
{
	return "Would you like to add even more sort algorithms?";
}