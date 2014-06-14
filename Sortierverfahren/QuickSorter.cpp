#include "stdafx.h"
#include "QuickSorter.h"

template <class sortType>
QuickSorter<sortType>::QuickSorter()
{
}


template <class sortType>
QuickSorter<sortType>::~QuickSorter()
{
}

template<class sortType>
void QuickSorter<sortType>::sort(DataArray<sortType>& data)
{
	this->resetPerformenceCounters();
	this->sortRecursive(data.getData(), data.getLength());
}

template<class sortType>
void QuickSorter<sortType>::sortRecursive(sortType* data, unsigned int len)
{
	if (len <= 1)
	{
		return;
	}

	sortType pivotElement = data[0];
	unsigned int l = 0;			//Alle Elemente i < l sind kleiner als das Pivotelement.
	unsigned int r = len - 1;	//Alle Elemente i > r sind größer als das Pivotelement.

	do
	{
		//Das nächste Element von links suchen, das größer als das Pivotelement ist.
		while (data[l] <= pivotElement && l <= r)
		{
			this->countCompares(1);
			l++;
		}
		this->countCompares(1);

		//Das nächste Element von rechts suchen, das kleiner als das Pivotelement ist.
		while (data[r] >= pivotElement && r >= l)
		{
			this->countCompares(1);
			r--;
		}
		this->countCompares(1);

		if (l < r)
		{
			this->swap(data[l], data[r]);
			l++;
			r--;
		}
	} while (l <= r);

	//Das Pivotelement durch einen Tausch zwischen den linken ( < pivot ) und den rechten (> pivot) Bereich bringen.
	this->swap(data[0], data[r]);

	//Die linke Hälfte mit quicksort sortieren.
	this->sortRecursive(data, r);

	//Die rechte Hälfte mit quicksort sortieren.
	this->sortRecursive(&data[r + 1], len - r - 1);
}
