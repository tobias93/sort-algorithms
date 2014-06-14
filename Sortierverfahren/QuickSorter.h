#pragma once
#include "Sorter.h"
#include "Sorter.cpp"

template<class sortType>
class QuickSorter :
	public Sorter < sortType >
{
private:
	void sortRecursive(sortType* data, unsigned int len);
public:
	QuickSorter();
	~QuickSorter();
	void sort(DataArray<sortType>&);
};

