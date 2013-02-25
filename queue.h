#ifndef QUEUE_H
#define QUEUE_H

#include "llist.h"

template <typename T>
class Queue : private LList<T> {
	public:
		Queue();
		~Queue();
		int size() const;
		void push_back(const T& value); //enqueue
		void pop_front();  // dequeue
		T& front();
		T& back();
		bool empty() const;
};

template <typename T>
Queue<T>::Queue() {};

template <typename T>
Queue<T>::~Queue() {
	LList<T>::clear();
};

template <typename T>
int Queue<T>::size() const {
	LList<T>::size();
}

template <typename T>
void Queue<T>::push_back(const T& value) {
	LList<T>::push_back(value);
}

template <typename T>
void Queue<T>::pop_front() {
	if(size() == 0) {
		cout << "ERROR: Trying to pop empty queue." << endl;
		return;
	}
	LList<T>::pop_front();
}

template <typename T>
T& Queue<T>::front() {
	LList<T>::at(0);
}

template <typename T>
T& Queue<T>::back() {
	LList<T>::at(size() - 1);
}

template <typename T>
bool Queue<T>::empty() const {
	LList<T>::empty();
}

#endif
