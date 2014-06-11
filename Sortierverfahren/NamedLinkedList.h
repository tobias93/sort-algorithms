#pragma once
template<class dataType>
class NamedLinkedList
{
private:
	class listElement
	{
	private:
		dataType data;
		char* name;
		typename NamedLinkedList<dataType>::listElement* next;
	public:
		listElement();
		~listElement();
		dataType getData() const;
		void setData(const dataType&);
		char* getName() const;
		void setName(char*);
		typename NamedLinkedList<dataType>::listElement* getNext() const;
		void setNext(typename NamedLinkedList<dataType>::listElement*);
	};
	typename NamedLinkedList<dataType>::listElement* first;
	typename NamedLinkedList<dataType>::listElement* current;
public:
	NamedLinkedList();
	~NamedLinkedList();
	void addElement(const dataType& element, char* name);
	void iteratorInit();
	void iteratorNext();
	bool iteratorIsFinished();
	dataType getCurrentElement() const;
	char* getCurrentElementName() const;

};

