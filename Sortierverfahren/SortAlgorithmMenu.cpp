#include "stdafx.h"
#include "SortAlgorithmMenu.h"
#include <string>
#include "BubbleSorter.h"
#include "BubbleSorter.cpp"
#include "DumbSorter.h"
#include "DumbSorter.cpp"
#include "InsertionSorter.h"
#include "InsertionSorter.cpp"
#include "SelectionSorter.h"
#include "SelectionSorter.cpp"
#include "MergeSorter.h"
#include "MergeSorter.cpp"
#include "QuickSorter.h"
#include "QuickSorter.cpp"
#include "BucketSorter.h"
#include "BucketSorter.cpp"
#include "RadixSorter.h"
#include "RadixSorter.cpp"


template<class sortType>
SortAlgorithmMenu<sortType>::SortAlgorithmMenu()
{
}

template<class sortType>
SortAlgorithmMenu<sortType>::~SortAlgorithmMenu()
{
}

//---- Protected -----------------------------------

template<class sortType>
char** SortAlgorithmMenu<sortType>::getEntries(unsigned int& entriesCount) const
{
	entriesCount = 7;
	char** menu = (char**)malloc(entriesCount * sizeof(char*));
	menu[0] = _strdup("Bubble Sort");
	menu[1] = _strdup("Insertion Sort");
	menu[2] = _strdup("Selection Sort");
	menu[3] = _strdup("Merge Sort");
	menu[4] = _strdup("Quick Sort");
	menu[5] = _strdup("Bucket Sort");
	menu[6] = _strdup("Radix Sort");
	return menu;
}

template<class sortType>
Sorter<sortType>* SortAlgorithmMenu<sortType>::getResultForSelectedIndex(unsigned int selectedIndex) const
{
	switch (selectedIndex)
	{
	case 0:
		return new BubbleSorter<sortType>();
		break;
	case 1:
		return new InsertionSorter<sortType>();
		break;
	case 2:
		return new SelectionSorter<sortType>();
		break;
	case 3:
		return new MergeSorter<sortType>();
		break;
	case 4:
		return new QuickSorter<sortType>();
		break;
	case 5:
		return new BucketSorter<sortType>();
		break;
	case 6:
		return new RadixSorter<sortType>();
		break;
	default:
		throw 0;
	}
}

template<class sortType>
Sorter<sortType>* SortAlgorithmMenu<sortType>::getResultForWrongInput() const
{
	return new DumbSorter<sortType>();
}

template<class sortType>
char* SortAlgorithmMenu<sortType>::getTitle() const
{
	return "Select an algorithm:";
}
