#ifndef USER_H
#define USER_H
#include "mylist.h"
#include <iostream>
#include <string>

using namespace std;

class User {
	private:
	string name_;
	int age_;
	int zip_;
	MyList<int>* friends_;
	
	public:
	User();
	~User();
	
	string getName();
	void setName(string name);
	
	int getAge();
	void setAge(int age);
	
	int getZip();
	void setZip(int zip);
	
	MyList<int>* friends();
};

#endif
