#include "stdafx.h"
#include "SelectionSorter.h"


template<class sortType>
SelectionSorter<sortType>::SelectionSorter()
{
}


template<class sortType>
SelectionSorter<sortType>::~SelectionSorter()
{
}


template<class sortType>
void SelectionSorter<sortType>::sort(DataArray<sortType>& data)
{
	/*
	Laufzeit:
		Vergleiche:
			Best case = average case = worst case:
				(n-1) + (n-2) + (n-3) + ... + 2 + 1
				= n*(n - 1) / 2
		Schreibvorgänge:
			Best case = average case = worst case:
				n - 1
	*/
	this->resetPerformenceCounters();

	if (data.getLength() == 0)
	{
		return;
	}

	for (unsigned int i = 0; i < data.getLength() - 1; i++)
	{

		//find the minimum in the range data[i] - data[maxIndex]
		unsigned int minimumPosition = i;
		for (unsigned int j = i + 1; j < data.getLength(); j++)
		{
			this->countCompares(1);
			if (data[j] < data[minimumPosition])
			{
				minimumPosition = j;
			}
		}
		//swap
		this->swap(data[i], data[minimumPosition]);
	}
}