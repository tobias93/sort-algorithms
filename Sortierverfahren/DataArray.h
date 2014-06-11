#pragma once
#include <ostream>
template <class dataType>
class DataArray
{
private:
	unsigned int length;
	dataType* data;
	void init();
	void copy(const DataArray<dataType>&);
public:
	DataArray();
	DataArray(const DataArray<dataType>&);
	~DataArray();
	unsigned int getLength() const;
	dataType* getData() const;
	void setData(dataType* data, unsigned int length);
	void allocateData(unsigned int length);
	void operator=(const DataArray<dataType>&);
	dataType& operator[](unsigned int);
};

template<class dataType>
std::ostream& operator<<(std::ostream& cout, const DataArray<dataType>& data);