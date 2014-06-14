#include "stdafx.h"
#include "BubbleSorter.h"

template<class sortType>
BubbleSorter<sortType>::BubbleSorter()
{

}

template<class sortType>
BubbleSorter<sortType>::~BubbleSorter()
{

}

template<class sortType>
void BubbleSorter<sortType>::sort(DataArray<sortType>& data)
{
	/*
	Vergleiche:
		worst case = average case = best case:
			1 + 2 + 3 + 4 + ... + (n - 1)
			= (n-1)*n / 2
	Schreibvorgänge:
		worst case: Die Folge ist rückwärts sortiert
			Auf jeden einzelnen Vergleich folgt ein swap.
			Für jeden swap werden 3 schreibvorgänge benötigt.
			(n-1)*n / 2 * 3
		best case: Die Folge ist schon sortiert
			Es muss nichts getauscht werden
			0
		average case:
			O(n^2)
	*/
	this->resetPerformenceCounters();
	unsigned int len = data.getLength();

	if (len == 0)
	{
		return;
	}

	for (unsigned int i = len - 1; i > 0; i--)
	{
		for (unsigned int j = 0; j < i; j++)
		{
			this->countCompares(1);
			if (data[j] > data[j + 1])
			{
				this->swap(data[j], data[j + 1]);
			}
		}
	}
}