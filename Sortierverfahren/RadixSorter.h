#pragma once
#include "Sorter.h"
#include "Sorter.cpp"

template<class sortType>
class RadixSorter :
	public Sorter < sortType >
{
private:
	unsigned int base;
	char maxKeyLength;
	unsigned int getDigit(unsigned int number, char digitPosition);
public:
	RadixSorter();
	~RadixSorter();
	unsigned int getBase() const;
	void setBase(unsigned int);
	char getMaxKeyLength() const;
	void setMaxKeyLength(char);
	void sort(DataArray<sortType>&);
	void configureInteractive(ostream&, istream&);
};

