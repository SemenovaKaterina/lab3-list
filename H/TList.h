#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Item //��������� � ���������� � �������� �����
{
	T Data; //��������. �������� �� x ����� ������������ � ������
	Item* next; //�������� ����

	Item(T x = 0, Item* n = NULL)
	{
		Data = x;
		next = n;
	}
};


template <class T>
class TList
{
	Item<T>* first;  //������ �� 1-� �������
public:
	TList();
	~TList();

	bool IsEmpty(); //�������� �� �������
	Item<T>* Search(T x);
	void PrintL();
	T ViewFirst();
	void InsertHead(Item<T>*);
	void InsertEnd(Item<T>*);
	void InsertPointer(Item<T>*, Item <T>* p);

	T ClrHead();
	T ClrEnd();
	T ClrPointer(Item <T>* p);
};

template <class T>
T TList<T>::ViewFirst()
{
	if (first)
	{
		return first->Data;
	}
	else throw - 1;
}

template <class T>
TList<T>::TList()
{
	first = NULL;
}

template <class T>
TList<T>::~TList()
{
	if (first != NULL)
	{
		Item<T>* temp = first;
		for (Item<T>* cur = first->next; cur != NULL; cur = cur->next)
		{
			delete temp;
			temp = cur;
		}
		delete temp;
		first = NULL;
	}
}

template <class ValType>
bool TList<ValType>::IsEmpty()
{
	if (first != NULL) return false;
	else return true;
}

template <class T>
Item<T>* TList<T>::Search(T x)
{
	if (first)
	{
		Item<T>* temp = first;
		while ((temp != NULL) && (temp->Data != x)) temp = temp->next;
		return temp;
	}
	else return 0;
}

template <class T>
void TList<T>::InsertHead(Item<T>* x)
{
	if (x != NULL)
	{
		x->next = first;
		first = x;
	}
	else throw 0;
}

template <class T>
void TList<T>::InsertEnd(Item<T>* x)
{
	if (x)
	{
		if (first)
		{
			Item<T>* point = first;
			while (point->next != 0) point = point->next;
			point->next = x;
		}
		else first = x;
		x->next = 0;
	}
	else throw 0;
}

template <class T>
void TList<T>::InsertPointer(Item<T>* x, Item<T>* n)
{
	if ((n) && (x))
	{
		n->next = x->next;
		x->next = n;
	}
	else throw 0;
}


template <class T>
void TList <T> ::PrintL() // ������
{
	Item <T> * temp = first;
	while (temp)
	{
		cout << temp->Data << endl;
		temp = temp->next;
	}
}

template <class T>
T TList<T>::ClrHead()
{
	if (first != NULL)
	{
		Item<T>* temp = first;
		first = first->next;
		return temp->Data;
	}
	return 0;
}

template <class T>
T TList <T> ::ClrEnd()
{
	if (first != NULL)
	{
		if (first->next != NULL)
		{
			Item<T>* temp = first;
			while (temp->next->next) temp = temp->next;
			delete temp->next;
			temp->next = 0;
		}
		else
			return first->Data;

	}

}

template <class T>
T TList <T> ::ClrPointer(Item <T> * p)
{
	if (p)
	{
		Item<T>* temp = p->next;
		p->next = p->next->next;
		return temp->Data;
	}
	else
		throw 1;
}