// Sortierverfahren.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

#include "NamedLinkedList.h"
#include "NamedLinkedList.cpp"
#include "AddDataSetQuestionMenu.h"
#include "DataGeneratorMenu.h"
#include "DataGeneratorMenu.cpp"
#include "SortAlgorithmMenu.h"
#include "SortAlgorithmMenu.cpp"
#include "AddSorterQuestionMenu.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//prepare menus
	DataGeneratorMenu<int> dataGenerationMenu;
	AddDataSetQuestionMenu moreDataSetsMenu;
	SortAlgorithmMenu<int> sorterMenu;
	AddSorterQuestionMenu moreSortersMenu;
	
	//create datasets
	NamedLinkedList< DataArray<int> > dataSets;
	do
	{
		//Select a data generator
		DataGenerator<int>* generator = dataGenerationMenu.executeForceValid(cout, cin);
		generator->configureInteractive(cout, cin);

		//generate data
		cout << "Generating data..." << endl;
		DataArray<int> dataSet = generator->generate();
		char* dataSetName = dataGenerationMenu.getLastSelectedEntry();
		dataSets.addElement(dataSet, dataSetName);
		cout << "Finished" << endl;
		if (dataSet.getLength() < 100)
		{
			cout << dataSet << endl;
		}
		delete generator;
	} while (moreDataSetsMenu.executeForceValid(cout, cin));

	//select sort algorithms
	NamedLinkedList< Sorter<int>* > sorters;
	do
	{
		//Select a sorter, configure & store it.
		Sorter<int>* sorter = sorterMenu.executeForceValid(cout, cin);
		sorter->configureInteractive(cout, cin);
		char* sorterName = sorterMenu.getLastSelectedEntry();
		sorters.addElement(sorter, sorterName);
	} while (moreSortersMenu.executeForceValid(cout, cin));

	//sort data...
	cout << endl << endl;//<< setprecision(8);

	for (dataSets.iteratorInit(); !dataSets.iteratorIsFinished(); dataSets.iteratorNext())
	{
		for (sorters.iteratorInit(); !sorters.iteratorIsFinished(); sorters.iteratorNext())
		{
			Sorter<int>* sorter = sorters.getCurrentElement();
			DataArray<int> data = dataSets.getCurrentElement();
			cout << endl << sorters.getCurrentElementName() << " / " << dataSets.getCurrentElementName() << '(' << data.getLength() << ')' << endl;
			sorter->sort(data);
			double time = sorter->getTime();
			cout << "\tCompares: " << sorter->getNumberOfCompares() << endl;
			cout << "\tWrites: " << sorter->getNumberOfWrites() << endl;
			cout << "\tTime: " << time << "s" << endl;
			if (data.getLength() < 100)
			{
				cout << data << endl;
			}
		}
	}

	//clean up memory
	for (sorters.iteratorInit(); !sorters.iteratorIsFinished(); sorters.iteratorNext())
	{
		delete sorters.getCurrentElement();
	}
	return 0;
}

