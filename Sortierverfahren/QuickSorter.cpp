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
	
	/*
	Laufzeitverhalten:
	
	--> Die beiden Schleifen, die jeweils das n�chste Element suchen,
		das gr��er / kleiner als das Pivotelement ist, arbeiten pro Rekursionsschritt
		insgesammt alle Elemente der aktuellen Teilfolge ab.
	--> Die Laufzeite einer "Rekursionsebene" entspricht immer der Anzahl der Elemente in der Rekursionsebene.

	Worst case: Die Liste ist vorw�rts oder r�ckw�rts sortiert.
			--> Das Pivotelement ist immer das kleinste / gr��te Element der betrachteten Teilfolge.
			--> Eine Teilfolge mit n Elementen wird immer in eine Folge mit 0 und eine Folge mit n-1 Elementen aufgeteilt.
			--> Rekursionstiefe betr�gt n, in jeder Ebene wird die Anzahl der Elemente um 1 kleiner.
			--> Laufzeit = n + (n-1) + (n-2) + ... 2 + 1 = (n+1)*n / 2
			--> O(n^2)
	Average case = Best case: Die Liste wird in zwei gleichgro�e Teilfolgen aufgeteilt.
			--> Rekursionstiefe: log2(n)
			--> Gr��e der i-ten Rekursionsebene: n - 2^i + 1
			--> Es ist jedoch einfacher, die Laufzeit nach oben abzusch�tzen,
				indem man vernachl�ssigt, dass die Pivotelemente nicht teil der 
				n�chsten Rekursionsebene sind. Dann sind alle Rekursionsebenen in der Summe genau
				so gro� 
			--> Damit muss nur noch die Gr��e einer Rekursionsebene (n) mit der Anzahl der Rekursionsebenen 
				multipliziert werden, also:
				log2(n) * n
	*/
	
	if (len <= 1)
	{
		return;
	}

	sortType pivotElement = data[0];
	unsigned int l = 0;			//Alle Elemente i < l sind kleiner als das Pivotelement.
	unsigned int r = len - 1;	//Alle Elemente i > r sind gr��er als das Pivotelement.

	do
	{
		//Das n�chste Element von links suchen, das gr��er als das Pivotelement ist.
		while (data[l] <= pivotElement && l <= r)
		{
			this->countCompares(1);
			l++;
		}
		this->countCompares(1);

		//Das n�chste Element von rechts suchen, das kleiner als das Pivotelement ist.
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

	//Das Pivotelement durch einen Tausch zwischen 
	//den linken ( < pivot ) und den rechten (> pivot) Bereich bringen.
	this->swap(data[0], data[r]);

	//Die linke H�lfte mit quicksort sortieren.
	this->sortRecursive(data, r);

	//Die rechte H�lfte mit quicksort sortieren.
	this->sortRecursive(&data[r + 1], len - r - 1);
}
