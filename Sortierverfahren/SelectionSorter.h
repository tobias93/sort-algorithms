#pragma once
#include "Sorter.h"
#include "Sorter.cpp"

template<class sortType>
class SelectionSorter :
	public Sorter<sortType>
{
public:
	SelectionSorter();
	~SelectionSorter();
	void sort(DataArray<sortType>&);
};

