#pragma once
#include "Sorter.h"
#include "Sorter.cpp"

/*
	Every sortType should overload the "operator unsigned int". 
	This should return the key of the to-be-sortet dataelement.
*/

template <class sortType>
class BucketSorter :
	public Sorter < sortType >
{
private:
	unsigned int bucketSize;
public:
	BucketSorter();
	~BucketSorter();
	unsigned int getBucketSize() const;
	void setBucketSize(unsigned int);
	void sort(DataArray<sortType>&);
	void configureInteractive(ostream&, istream&);
};