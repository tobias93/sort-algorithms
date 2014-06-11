#pragma once

#include "stdafx.h"
#include "Sorter.h"

//---- Konstruktor / Destruktor -----------------------------------------------

template<class sortType>
Sorter<sortType>::Sorter()
{
	this->resetPerformenceCounters();
}

//---- Protected --------------------------------------------------------------

/*
 * Hilfsfunktion zum Tauschen zweier Variablen
 */
template<class sortType>
void Sorter<sortType>::swap(sortType& element1, sortType& element2)
{
	sortType tmp = element1;
	element1 = element2;
	element2 = tmp;
	this->countWrites(3);
}

/*
 * Setzt die Zählervariablen für die Anzahl der Vergleiche und die Anzahl der Schreibzugriffe auf 0
 */
template<class sortType>
void Sorter<sortType>::resetPerformenceCounters()
{
	this->numberOfCompares = 0;
	this->numberOfWrites = 0;
	this->startTime = clock();
}

/*
 * Erhöht die Anzahl der Vergleiche um count
 */
template<class sortType>
void Sorter<sortType>::countCompares(unsigned int count)
{
	this->numberOfCompares += count;
}

/*
 * Erhöht die Anzahl der Schreibzugriffe um count
 */
template<class sortType>
void Sorter<sortType>::countWrites(unsigned int count)
{
	this->numberOfWrites += count;
}

//---- Getter / Setter (public) -----------------------------------------------------------------

template<class sortType>
unsigned int Sorter<sortType>::getNumberOfCompares() const
{
	return this->numberOfCompares;
}

template<class sortType>
unsigned int Sorter<sortType>::getNumberOfWrites() const
{
	return this->numberOfWrites;
}

template<class sortType>
double Sorter<sortType>::getTime() const
{
	return (double)(clock() - this->startTime) / CLOCKS_PER_SEC;
}
