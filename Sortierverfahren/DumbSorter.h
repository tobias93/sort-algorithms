#pragma once
#include "Sorter.h"

template<class sortType>
class DumbSorter :
	public Sorter < sortType >
{
public:
	DumbSorter();
	~DumbSorter();
	void sort(DataArray<sortType>&);
};

