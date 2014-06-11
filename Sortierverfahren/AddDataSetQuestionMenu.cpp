#include "stdafx.h"
#include "AddDataSetQuestionMenu.h"


AddDataSetQuestionMenu::AddDataSetQuestionMenu()
{
}


AddDataSetQuestionMenu::~AddDataSetQuestionMenu()
{
}

//---- Protected: Menu implementation -----------------------------------------------

char** AddDataSetQuestionMenu::getEntries(unsigned int& entriesCount) const
{
	entriesCount = 2;
	char** entries = (char**)malloc(entriesCount * sizeof(char*));
	entries[0] = _strdup("Yes, add another dataset.");
	entries[1] = _strdup("No, let me choose how to sort the datasets.");
	return entries;
}

bool AddDataSetQuestionMenu::getResultForSelectedIndex(unsigned int selectedIndex) const
{
	return selectedIndex == 0;
}

bool AddDataSetQuestionMenu::getResultForWrongInput() const
{
	return false;
}

char* AddDataSetQuestionMenu::getTitle() const
{
	return "Would you like to create even more datasets?";
}