#include "stdafx.h"
#include "BucketSorter.h"


//---- Konstruktor / Destruktor -------------------------------------------------------------

template <class sortType>
BucketSorter<sortType>::BucketSorter()
{
}


template <class sortType>
BucketSorter<sortType>::~BucketSorter()
{
}

//---- Getter / Setter ----------------------------------------------------------------------

template <class sortType>
unsigned int BucketSorter<sortType>::getBucketSize() const
{
	return this->bucketSize;
}

template <class sortType>
void BucketSorter<sortType>::setBucketSize(unsigned int bucketSize)
{
	this->bucketSize = bucketSize;
}

//---- Methoden -----------------------------------------------------------------------------

template <class sortType>
void BucketSorter<sortType>::configureInteractive(ostream& cout, istream& cin)
{
	unsigned int bucketSize = 0;
	cout << "Bucket size = ";
	cin >> bucketSize;
	this->setBucketSize(bucketSize);
	cout << "Ok, your keys need to be \"0 <= key <= " << bucketSize - 1 << "\"." << endl;
}

template <class sortType>
void BucketSorter<sortType>::sort(DataArray<sortType>& data)
{
	
	/*
	Laufzeitverhalten:
		Bestcase = averagecase = worstcase:
			n: number of elements in the list
			N: bucket size
			O(n + N)
	*/

	this->resetPerformenceCounters();

	unsigned int bucketSize = this->getBucketSize();

	//Buckets initialisieren (std::fill: Alle auf 0 setzen)
	unsigned int* buckets = (unsigned int*)malloc(sizeof(unsigned int) * bucketSize);
	std::fill<unsigned int*, unsigned int>(buckets, &buckets[bucketSize], 0);

	//Die Elemente mit den entsprechenden Schlüsseln zählen
	for (unsigned int i = 0; i < data.getLength(); i++)
	{
		unsigned int key = (unsigned int)data[i];
		if (key >= bucketSize)
		{
			throw "There is no Bucket for an element in the list.";
		}
		buckets[key]++;
	}

	//Die Position des jeweils letzten Elements jedes Buckets berechnen
	for (unsigned int i = 1; i < bucketSize; i++)
	{
		buckets[i] = buckets[i] + buckets[i - 1];
	}

	//Platz für die sortierten daten...
	sortType* sortedData = (sortType*)malloc(sizeof(sortType) * data.getLength());

	//Die Daten sortiert in das neue Array schreiben.
	//Dadurch, dass die daten rückwärs abgearbeitet werden, ist der Algorithmus stabil.
	for (unsigned int i = data.getLength() - 1; i < data.getLength(); i--)
	{
		unsigned int key = (unsigned int)data[i];
		buckets[key]--;
		unsigned int position = buckets[key];
		sortedData[position] = data[i];
		this->countWrites(1);
	}

	data.setData(sortedData, data.getLength());

	//Free memory
	delete buckets;
	delete sortedData;
}