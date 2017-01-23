#pragma once
#include "LinkedListInterface.h"
#include "Node.h"

using namespace std;

template <typename T> class LinkedList : public LinkedListInterface<T> {
private:	
	Node<T>* head;
	int length;
public:
	LinkedList() : head(NULL), length(0) {}
	~LinkedList() {}
	void insertHead(T);
	void insertTail(T);
	void insertAfter(T, T);
	void remove(T);
	void clear();
	T at(int);
	int size();
};