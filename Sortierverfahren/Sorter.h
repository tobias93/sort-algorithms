#pragma once
#include <iostream>
#include "DataArray.h"
#include "DataArray.cpp"
#include <time.h>

using namespace  std;

template<class sortType>
class Sorter
{
private:
	unsigned int numberOfCompares;
	unsigned int numberOfWrites;
	clock_t startTime;
protected:
	void swap(sortType&, sortType&);
	void resetPerformenceCounters();
	void countCompares(unsigned int count = 1);
	void countWrites(unsigned int count = 1);
public:
	Sorter();
	unsigned int getNumberOfCompares() const;
	unsigned int getNumberOfWrites() const;
	double getTime() const;
	virtual void sort(DataArray<sortType>&) = 0;
	virtual void configureInteractive(ostream&, istream&) {};
};