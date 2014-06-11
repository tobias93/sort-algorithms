#include "stdafx.h"
#include "MergeSorter.h"


template<class sortType>
MergeSorter<sortType>::MergeSorter()
{
}


template<class sortType>
MergeSorter<sortType>::~MergeSorter()
{
}

template<class sortType>
void MergeSorter<sortType>::sort(DataArray<sortType>& data)
{
	this->resetPerformenceCounters();
	this->sortRecursive(data.getData(), data.getLength());
}

template<class sortType>
void MergeSorter<sortType>::sortRecursive(sortType* data, unsigned int len)
{
	/*
	Laufzeitverhalten:
		Vergleiche:
			O(n * log(n))
		Schreibzugriffe:
			Best case = average case = worst case:
				2n * log(n)
	*/
	
	if (len <= 1)
	{
		return;
	}

	//split data[] into 2 segments and use mergesort to sort each segment recursively
	unsigned int len_1st_half = len / 2;
	unsigned int len_2nd_half = len - len_1st_half;

	this->sortRecursive(data, len_1st_half);
	this->sortRecursive(&data[len_1st_half], len_2nd_half);

	//merge the sorted segments
	//     copy the segments to their own arrays
	sortType* data_1st_half = (sortType*)malloc(sizeof(sortType) * len_1st_half);
	sortType* data_2nd_half = (sortType*)malloc(sizeof(sortType) * len_2nd_half);
	memcpy(data_1st_half, data, sizeof(sortType) * len_1st_half);
	memcpy(data_2nd_half, &data[len_1st_half], sizeof(sortType) * len_2nd_half);
	this->countWrites(len);

	//     merge them back to the data array    
	unsigned int position_1st_half = 0;
	unsigned int position_2nd_half = 0;
	unsigned int position = 0;
	while (position_1st_half < len_1st_half && position_2nd_half < len_2nd_half)
	{
		this->countCompares(1);
		if (data_1st_half[position_1st_half] <= data_2nd_half[position_2nd_half])
		{
			data[position] = data_1st_half[position_1st_half];
			position_1st_half++;
		}
		else
		{
			data[position] = data_2nd_half[position_2nd_half];
			position_2nd_half++;
		}
		position++;
		this->countWrites(1);
	}

	//     copy back what is left over
	if (position_1st_half < len_1st_half)
	{
		memcpy(&data[position], &data_1st_half[position_1st_half], sizeof(sortType) * (len_1st_half - position_1st_half));
		this->countWrites(len_1st_half - position_1st_half);
	}
	else if (position_2nd_half < len_2nd_half)
	{
		memcpy(&data[position], &data_2nd_half[position_2nd_half], sizeof(sortType) * (len_2nd_half - position_2nd_half));
		this->countWrites(len_2nd_half - position_2nd_half);
	}

	//free memory
	delete(data_1st_half);
	delete(data_2nd_half);
}