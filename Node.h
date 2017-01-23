#pragma once
template <typename T> 
class Node {
private:
	T value;
	Node<T>* next;
public:
	Node(T value) :
		next(NULL), value(value) {}
	~Node() {}
};