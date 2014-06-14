#pragma once
#include <iostream>
#include <stdbool.h>

using namespace std;

template<class returnType>
class Menu
{
private:
	unsigned int pufferedEntryCount;
	char** pufferedEntries;
	bool entryPufferFilled;
	unsigned int lastSelectedIndex;
	bool lastInputWasWrong;

	char** getEntriesAndPufferIt(unsigned int& count);
	unsigned int getPufferedEntryCount();
	char** getPufferedEntries();
	void deletePufferedEntries();
protected:
	virtual char** getEntries(unsigned int& entriesCount) const = 0;
	virtual returnType getResultForSelectedIndex(unsigned int selectedIndex) const = 0;
	virtual returnType getResultForWrongInput() const = 0;
	virtual char* getTitle() const = 0;
public:
	//Konstruktor / Destruktor
	Menu();
	virtual ~Menu();

	//Methoden
	void display(ostream&);
	char* getLastSelectedEntry();
	returnType input(istream&, bool& wrongInput);
	returnType input(istream&);
	returnType inputForceValid(istream&);
	returnType execute(ostream&, istream&, bool& wrongInput);
	returnType execute(ostream&, istream&);
	returnType executeForceValid(ostream&, istream&);
};

