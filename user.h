#ifndef USER_H
#define USER_H
#include "mylist.h"
#include <iostream>
#include <string>

using namespace std;

class User {
	private:
	string name_;
	int id_;
	int age_;
	int zip_;
	MyList<int>* friends_;
	
	public:
	User();
	User(string name, int age, int zip, int id);
	~User();
	
	string getName();
	void setName(string name);
	
	int getAge();
	void setAge(int age);
	
	int getZip();
	void setZip(int zip);
	
	int getId();
	void setId(int id);
	
	MyList<int>* friends();
};

#endif
