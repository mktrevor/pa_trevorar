#ifndef LLIST_H
#define LLIST_H

#include <iostream>

using namespace std;

template <typename T>
struct Item {
  T val;
  Item<T> *next;
};

template <typename T>
class LList {
 public:
  LList();
  ~LList();
  bool empty() const;
  int size() const;
  void push_back(const T& new_val);
  void pop_front();
  T& peek_front() const;
  T& peek_back() const;
  T& at(int loc) const;
  T& operator[](int loc) const;
  bool remove(const T& val);
  void insert(int loc, int val);
  void clear();
 private:
  Item<T> *getNodeAt(int loc) const;

 private:
  Item<T> *head_;
  Item<T> *tail_;
  int size_;
};

// Write the constructor here
template <typename T>
LList<T>::LList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}




// Write the destructor here
template <typename T>
LList<T>::~LList()
{
	clear();
}





template <typename T>
bool LList<T>::empty() const
{
	return head_ == NULL;
}

template <typename T>
int LList<T>::size() const
{
	return size_;
}

template <typename T>
Item<T>* LList<T>::getNodeAt(int loc) const
{
	Item<T>* temp = head_;
	for(int i = 0; i < loc; i++) {
		temp = temp->next;
	}
	return temp;
}

template <typename T>
void LList<T>::push_back(const T& new_val)
{
	 Item<T>* newItem = new Item<T>;
	 newItem->val = new_val;
	 newItem->next = NULL;
	 
	 if(head_ == NULL) {
	 	head_ = newItem;
	 	tail_ = newItem;
	 	size_++;
	 	return;
	 }
	 
	 Item<T>* temp = tail_;
	 temp->next = newItem;
	 tail_ = newItem;
	 size_++;
} 

template <typename T>
void LList<T>::pop_front()
{
	Item<T>* temp = head_->next;
	delete head_;
	head_ = temp;
	size_--;
	return;
}

template <typename T>
T& LList<T>::peek_front() const
{
	return head_->val;
}

template <typename T>
T& LList<T>::peek_back() const
{
	return tail_->val;
}

template <typename T>
bool LList<T>::remove(const T& val)
{
	if(head_->val == val) {
		delete head_;
		size_--;
		return 1;
	}
	
	Item<T>* temp = head_->next;
	Item<T>* trailer = head_;
		
	while(temp != tail_) {	
		if(temp->val == val) {
			trailer->next = temp->next;
			delete temp;
			size_--;
			return 1;
		}
		trailer = temp;
		temp = temp->next;
	}
	return 0;
}

template <typename T>
T& LList<T>::at(int loc) const
{
	return getNodeAt(loc)->val;
}

template <typename T>
T& LList<T>::operator[](int loc) const
{
	return at(loc);
}

template <typename T>
void LList<T>::insert(int loc, int val){

	if(loc > size_) {
		cout << "Error: Trying to insert outside of list." << endl;
		return;
	}

	Item<T>* temp = head_;
	Item<T>* trailer;
	
	Item<T>* newItem = new Item<T>;
	newItem->val = val;
	newItem->next = NULL;
	
	if(loc == 0) {
		if(head_ == NULL) {
			head_ = newItem;
			size_++;
			return;
		}
		newItem->next = temp;
		head_ = newItem;
		size_++;
		return;
	}
	
	for(int i = 0; i < loc; i++) {
		trailer = temp;
		temp = temp->next;
	}
	newItem->next = temp;
	trailer->next = newItem;
	
	size_++;
	
	return;
};

template <typename T>
void LList<T>::clear()
{
  while(head_ != NULL){
    Item<T> *temp = head_->next;
    delete head_;
    head_ = temp;
  }
}

#endif
