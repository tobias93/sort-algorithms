#include "stdafx.h"
#include "NamedLinkedList.h"
#include <string>

//-----------------------------------------------------------------
//-------- NamedLinkedList::Listelement ---------------------------
//-----------------------------------------------------------------

//---- Konstruktor / Destruktor -----------------------------------

template<class dataType>
NamedLinkedList<dataType>::listElement::listElement()
{
	this->name = NULL;
	this->next = NULL;
}

template<class dataType>
NamedLinkedList<dataType>::listElement::~listElement()
{
	delete (this->name);
}

//---- Getter / Setter --------------------------------------------

template<class dataType>
dataType NamedLinkedList<dataType>::listElement::getData() const
{
	return this->data;
}

template<class dataType>
void NamedLinkedList<dataType>::listElement::setData(const dataType& data)
{
	this->data = data;
}

template<class dataType>
char* NamedLinkedList<dataType>::listElement::getName() const
{
	return this->name;
}

template<class dataType>
void NamedLinkedList<dataType>::listElement::setName(char* name)
{
	delete this->name;

	if (name == NULL)
	{
		this->name = NULL;
	}
	else
	{
		this->name = _strdup(name);
	}
}

template<class dataType>
typename NamedLinkedList<dataType>::listElement* NamedLinkedList<dataType>::listElement::getNext() const
{
	return this->next;
}

template<class dataType>
void NamedLinkedList<dataType>::listElement::setNext(typename NamedLinkedList<dataType>::listElement* next)
{
	this->next = next;
}

//-----------------------------------------------------------------
//-------- NamedLinkedList ----------------------------------------
//-----------------------------------------------------------------

//---- Konstruktor / Destruktor -----------------------------------

template<class dataType>
NamedLinkedList<dataType>::NamedLinkedList()
{
	this->first = NULL;
	this->current = NULL;
}


template<class dataType>
NamedLinkedList<dataType>::~NamedLinkedList()
{
	typename NamedLinkedList<dataType>::listElement* current = this->first;
	while (current != NULL)
	{
		typename NamedLinkedList<dataType>::listElement* tmp = current->getNext();
		delete current;
		current = tmp;
	}
}

//---- Methoden ---------------------------------------------------

template<class dataType>
void NamedLinkedList<dataType>::addElement(const dataType& element, char* name)
{
	typename NamedLinkedList<dataType>::listElement* wrapper = new typename NamedLinkedList<dataType>::listElement();
	wrapper->setName(name);
	wrapper->setData(element);
	wrapper->setNext(this->first);
	this->first = wrapper;
}

template<class dataType>
void NamedLinkedList<dataType>::iteratorInit()
{
	this->current = this->first;
}

template<class dataType>
void NamedLinkedList<dataType>::iteratorNext()
{
	this->current = this->current->getNext();
}

template<class dataType>
bool NamedLinkedList<dataType>::iteratorIsFinished()
{
	return this->current == NULL;
}

template<class dataType>
dataType NamedLinkedList<dataType>::getCurrentElement() const
{
	if (this->current == NULL)
	{
		throw 1;
	}
	else
	{
		return this->current->getData();
	}
}

template<class dataType>
char* NamedLinkedList<dataType>::getCurrentElementName() const
{
	if (this->current == NULL)
	{
		throw 1;
	}
	else
	{
		return this->current->getName();
	}
}
