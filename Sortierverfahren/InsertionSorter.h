#pragma once
#include "Sorter.h"

template<class sortType>
class InsertionSorter :
	public Sorter<sortType>
{
public:
	InsertionSorter();
	~InsertionSorter();
	virtual void sort(DataArray<sortType>&);
};

