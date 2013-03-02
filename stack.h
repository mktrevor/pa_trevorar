#ifndef STACK_H
#define STACK_H

#include "llist.h"

template <typename T>
class Stack : private LList<T> {
	public:
		Stack();
		~Stack();
		int size() const;
		void push_front(const T& val);
		void pop_front();
		T& front();
		T& back();
		bool empty() const;
};

template <typename T>
Stack<T>::Stack() {};

template <typename T>
Stack<T>::~Stack() {
	LList<T>::clear();
};

template <typename T>
int Stack<T>::size() const {
	return LList<T>::size();
}

template <typename T>
void Stack<T>::push_front(const T& val) {
	insert(0, val);
}

template <typename T>
void Stack<T>::pop_front() {
	if(size() == 0) {
		cout << "ERROR: Trying to pop empty stack." << endl;
		return;
	}
	LList<T>::pop_front();
	return;
}

template <typename T>
T& Stack<T>::front() {
	return LList<T>::peek_front();
}

template <typename T>
T& Stack<T>::back() {
	return LList<T>::peek_back();
}

template <typename T>
bool Stack<T>::empty() const {
	return LList<T>::empty();
}

#endif
