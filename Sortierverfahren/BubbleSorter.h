#pragma once
#include "Sorter.h"

template<class sortType>
class BubbleSorter :
	public Sorter<sortType>
{
public:
	BubbleSorter();
	~BubbleSorter();
	virtual void sort(DataArray<sortType>&);
};