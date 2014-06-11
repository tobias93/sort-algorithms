#pragma once

#include "stdafx.h"
#include "Menu.h"

//---- Private ----------------------------------------
template<class returnType>
void Menu<returnType>::deletePufferedEntries()
{
	if (this->entryPufferFilled)
	{
		for (unsigned int i = 0; i < this->pufferedEntryCount; i++)
		{
			delete this->pufferedEntries[i];
		}
		delete this->pufferedEntries;
		this->pufferedEntries = NULL;
		this->pufferedEntryCount = 0;
		this->entryPufferFilled = false;
	}
}

template<class returnType>
char** Menu<returnType>::getEntriesAndPufferIt(unsigned int& count)
{
	this->deletePufferedEntries();
	char** entries = this->getEntries(count);
	this->pufferedEntryCount = count;
	this->pufferedEntries = entries;
	this->entryPufferFilled = true;
	return entries;
}

template<class returnType>
unsigned int Menu<returnType>::getPufferedEntryCount()
{
	if (this->entryPufferFilled)
	{
		return this->pufferedEntryCount;
	}
	else
	{
		unsigned int count = 0;
		this->getEntriesAndPufferIt(count);
		return count;
	}
}

template<class returnType>
char** Menu<returnType>::getPufferedEntries()
{
	if (this->entryPufferFilled)
	{
		return this->pufferedEntries;
	}
	else
	{
		unsigned int count = 0;
		return this->getEntriesAndPufferIt(count);
	}
}

//---- Konstruktor / Destruktor ----------------------
template<class returnType>
Menu<returnType>::Menu()
{
	this->pufferedEntryCount = 0;
	this->pufferedEntries = NULL;
	this->entryPufferFilled = false;
	this->lastSelectedIndex = 0;
	this->lastInputWasWrong = true;
}


template<class returnType>
Menu<returnType>::~Menu()
{
	this->deletePufferedEntries();
}

//---- Getter / Setter ------------------------

template<class returnType>
char* Menu<returnType>::getLastSelectedEntry()
{
	if (this->lastInputWasWrong)
	{
		return NULL;
	}
	else
	{
		char** entries = this->getPufferedEntries();
		return entries[this->lastSelectedIndex];
	}
}

//---- Methoden -------------------------------

template<class returnType>
void Menu<returnType>::display(ostream& cout)
{
	char* title = this->getTitle();
	unsigned int count = 0;
	char** entries = this->getEntriesAndPufferIt(count);
	this->lastInputWasWrong = true;

	cout << title << endl;

	for (unsigned int i = 0; i < count; i++)
	{
		cout << " [" << i << "] " << entries[i] << endl;
	}
}

template<class returnType>
returnType Menu<returnType>::input(istream& cin, bool& wrongInput)
{
	unsigned int count = this->getPufferedEntryCount();
	unsigned int input = 0;
	cin >> input;
	if (input < count)
	{
		wrongInput = false;
		this->lastSelectedIndex = input;
		this->lastInputWasWrong = false;
		return this->getResultForSelectedIndex(input);
	}
	else
	{
		wrongInput = true;
		this->lastInputWasWrong = true;
		return this->getResultForWrongInput();
	}
}

template<class returnType>
returnType Menu<returnType>::input(istream& cin)
{
	bool wrongInput = false;
	return this->input(cin, wrongInput);
}

template<class returnType>
returnType Menu<returnType>::inputForceValid(istream& cin)
{
	bool wrongInput = true;
	returnType result = this->getResultForWrongInput();
	while (wrongInput)
	{
		result = this->input(cin, wrongInput);
	}
	return result;
}

template<class returnType>
returnType Menu<returnType>::execute(ostream& cout, istream& cin, bool& wrongInput)
{
	this->display(cout);
	return this->input(cin, wrongInput);
}

template<class returnType>
returnType Menu<returnType>::execute(ostream& cout, istream& cin)
{
	this->display(cout);
	return this->input(cin);
}

template<class returnType>
returnType Menu<returnType>::executeForceValid(ostream& cout, istream& cin)
{
	this->display(cout);
	return this->inputForceValid(cin);
}