#pragma once
#include "Sorter.h"
#include "Sorter.cpp"
#include "DataArray.h"
#include "DataArray.cpp"

template<class sortType>
class MergeSorter:
	public Sorter<sortType>
{
private:
	void sortRecursive(sortType* data, unsigned int len);
public:
	MergeSorter();
	~MergeSorter();
	void sort(DataArray<sortType>&);
};

