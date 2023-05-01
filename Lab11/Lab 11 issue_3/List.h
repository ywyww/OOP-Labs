#pragma once
#include <iostream>
#include <fstream>

using namespace std;
template <class dataType>
class List;

template <class dataType>
class Node;

template <class dataType>
class Node
{
	friend class List<dataType>;

public:
	Node();
	Node(dataType);
	Node(const Node<dataType>& node) {
		this->data = node.data;
		this->ptrNext = node.ptrNext;
	}
	~Node();

	dataType getData();
	void setData(dataType);
	Node* getPtr();
	void setPtr(Node<dataType>*);
private:
	dataType data;
public:
	Node* ptrNext;
};

template <class dataType>
class List
{
public:
	List();
	List(dataType);
	List(const List<dataType>&);
	~List();

	dataType& operator[](int);

	List<dataType>& operator=(const List<dataType>&);
	size_t operator()();

	friend List<dataType>& operator*(List<dataType>& sList, List<dataType>& fList)
	{
		List<dataType> tmpList;
		int maxSize = fList.size > sList.size ? fList.size : sList.size;
		int minSize = fList.size <= sList.size ? fList.size : sList.size;

		for (int i = 0; i < minSize; i++)
		{
			dataType a = fList[i];
			dataType b = sList[i];
			tmpList.push(a * b);
		}

		return tmpList;
	}
	friend std::ostream& operator<<(std::ostream& out, const List<dataType>& tList)
	{
		Node<dataType>* curr = tList.head;
		for (int i = 0; i < tList.size; i++)
		{
			out << curr->getData() << " ";
			curr = curr->getPtr();
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, List<dataType>& tList)
	{
		dataType a;
		in >> a;
		tList.push(a);
		return in;
	}

	void push(dataType);
	Node<dataType>* getHead();
	void erase(int pos);


private:
	Node<dataType>* head;
	size_t size;
};

template <class dataType>
Node<dataType>::Node()
{
	// data = 0;
	ptrNext = nullptr;
}
template <class dataType>
Node<dataType>::Node(dataType data)
{
	this->data = data;
	ptrNext = nullptr;
}
template <class dataType>
Node<dataType>::~Node()
{
}
template <class dataType>
dataType Node<dataType>::getData()
{
	return data;
}
template <class dataType>
void Node<dataType>::setData(dataType data) {
	this->data = data;
}

template <class dataType>
Node<dataType>* Node<dataType>::getPtr()
{
	return ptrNext;
}

template <class dataType>
void Node<dataType>::setPtr(Node<dataType>* node) {
	this->ptrNext = node->ptrNext();
}

/// <summary>
/// Node* head;
/// </summary>
template <class dataType>
List<dataType>::List()
{
	head = nullptr;
	size = 0;
}
template <class dataType>
List<dataType>::List(dataType data)
{
	head = new Node<dataType>(data);
	size = 1;
}
template <class dataType>
List<dataType>::List(const List<dataType>& tList)
{
	Node<dataType>* curr = tList.head;
	while (curr != nullptr)
	{
		dataType a = curr->data;
		this->push(a);
		curr = curr->ptrNext;
	}
}
template <class dataType>
List<dataType>::~List()
{
	if (head != nullptr)
	{
		while (head != nullptr) {
			Node<dataType>* nodePtr = head->getPtr();
			delete head;
			head = nodePtr;
		}
	}
	size = 0;
}
template <class dataType>
void List<dataType>::push(dataType data)
{
	if (head == nullptr)
	{
		head = new Node<dataType>(data);
	}
	else
	{
		Node<dataType>* curr = head;
		while (curr->ptrNext != nullptr)
		{
			curr = curr->ptrNext;
		}
		curr->ptrNext = new Node<dataType>(data);
	}
	size++;
}
template <class dataType>
dataType& List<dataType>::operator[](int indx)
{
	Node<dataType>* curr = head;
	for (int i = 0; i < indx; i++)
	{
		curr = curr->ptrNext;
	}
	return curr->data;
}
template <class dataType>
size_t List<dataType>::operator()()
{
	return size;
}

template <class dataType>
List<dataType>& List<dataType>::operator=(const List<dataType>& tList)
{
	Node<dataType>* curr = tList.head;
	while (curr != nullptr)
	{
		dataType a = curr->data;
		this->push(a);
		curr = curr->ptrNext;
	}
	return *this;
}

template <class dataType>
Node<dataType>* List<dataType>::getHead() {
	return head;
}

template <class dataType>
void List<dataType>::erase(int pos) {
	int c;
	if (pos > size) { cout << "Îøèáêà 1"; }
	if (pos == 1 && pos == size) { c = 0; }
	else if (pos == 1) { c = 1; }
	else if (pos == size) { c = 2; }
	else if (pos > 1 && pos < size) c = 3;
	else exit(2);
	Node<dataType>* nodePtr = head;

	switch (c) {
	case 0:
	{
		delete nodePtr; nodePtr = NULL;
		head = NULL;
		break;
	}
	case 1:
	{
		head = nodePtr->getPtr();
		delete nodePtr; nodePtr = NULL;
		break;
	}
	case 2:
	{
		while (nodePtr->getPtr()->getPtr() != NULL) {
			nodePtr = nodePtr->getPtr();
		}
		Node<dataType>* ptr1 = nodePtr->getPtr();
		delete ptr1;
		break;
	}
	case 3:
	{
		for (int i = 1; i < pos - 1; i++) {
			nodePtr = nodePtr->getPtr();
		}
		Node<dataType>* ptr1 = nodePtr->ptrNext->ptrNext;
		Node<dataType>* tempNode = nodePtr->ptrNext;
		delete tempNode;
		nodePtr->ptrNext = ptr1;

	}
	}
	size--;
}