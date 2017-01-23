#include "LinkedList.h"
#include <stdexcept>
#include <cassert>

using namespace std;

template <typename T>
void LinkedList<T>::insertHead(T value) {
	if (head == NULL) {
		head = new Node<T>(value);
	}
	else {
		Node<T>* temp = head;
		head = new Node<T>(value);
		head->next = temp;
	}
	length++;
}

template <typename T>
void LinkedList<T>::insertTail(T value) {
	if (head == NULL) {
		head = new Node<T>(value);
	}
	else {
		Node<T>* cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = new Node<T>(value);
	}
	length++;
}

template <typename T>
void LinkedList<T>::insertAfter(T value, T insertionNode) {
	if (head->value == insertionNode) {
		Node<T>* after = head->next;
		head->next = new Node<T>(value);
		head->next->next = after;
	}
	else {
		Node<T>* cur = head;
		while (cur->next->value != insertionNode) {
			cur = cur->next;
		}
		Node<T>* after = cur->next;
		cur->next = new Node<T>(value);
		cur->next->next = after;
	}
	length++;
}

template <typename T>
void LinkedList<T>::remove(T value) {
	if (head->value == value) {
		Node<T>* cur = head;
		head = head->next;
		delete cur;
	}
	else {
		Node<T>* cur = head;
		int count = 1;
		while (cur->next->value != value && ++count < length) {
			cur = cur->next;
		}
		if (count >= length) return;
		Node<T>* temp = cur->next;
		cur->next = temp->next;
		delete temp;
	}
	length--;
}

template <typename T>
void LinkedList<T>::clear() {
	Node<T>* cur = head;
	Node<T>* temp;
	while (cur->next != NULL) {
		temp = cur;
		cur = cur->next;
		delete temp;
		length--;
	}
	assert(length = 0);
}

template <typename T>
T LinkedList<T>::at(int index) {
	int count = 0;
	Node<T>* cur = head;
	try {
		while (count < index) {
			cur = cur->next;
		}
	}
	catch (string s) {
		throw std::out_of_range("Out Of Range");
	}
	return cur->value;
}

template<typename T>
int LinkedList<T>::size()
{
	return length;
}
