#include "stdafx.h"
#include "InsertionSorter.h"


template<class sortType>
InsertionSorter<sortType>::InsertionSorter()
{
}


template<class sortType>
InsertionSorter<sortType>::~InsertionSorter()
{
}

template<class sortType>
void InsertionSorter<sortType>::sort(DataArray<sortType>& data)
{
	/*
	Laufzeitverhalten:
		Vergleiche:
			Best case: Liste ist bereits sortiert
				n - 1
			Average case:
				n(n+1)/4 - 1/2
			Worst case: Liste ist rückwärts sortiert.
				1 + 2 + 3 + ... + (n - 1)
				= n*(n-1) / 2
		Schreibzugriffe:
			Best case: Liste ist bereits sortiert.
				0
			Average case:
				(1 + 2 + 3 + ... + (n - 1)) / 2 * 3
				= n*(n-1) / 4 * 3
			Worst case: Liste ist rückwärts sortiert.
				(1 + 2 + 3 + ... + (n - 1)) * 3
				= n*(n-1) / 2 * 3
		*/

	this->resetPerformenceCounters();
	unsigned int len = data.getLength();
	for (unsigned int pos = 1; pos < len; pos++)
	{
		//insert the element data[pos] into the correctly sorted range data[0] - data[pos - t]
		unsigned int i = pos;
		bool insertedCorrectly = false;
		while (!insertedCorrectly && i >= 1)
		{
			this->countCompares(1);
			if (data[i] < data[i - 1])
			{
				this->swap(data[i], data[i - 1]);
				i--;
			}
			else
			{
				insertedCorrectly = true;
			}
		}
	}
}