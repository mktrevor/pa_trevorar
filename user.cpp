#ifndef USER_H
#define USER_H
#include "mylist.h"
#include <string>
#include "user.h"

User::User() {
	name_ = "";
	age_ = 0;
	zip_ = 0;
	friends_ = new MyList<int>;
}

User::~User() {
	delete friends_;
}

string User::getName() {
	return name_;
}
void User::setName(string name) {
	name_ = name;
}

int User::getAge() {
	return age_;
}
void User::setAge(int age) {
	age_ = age;
}

int User::getZip() {
	return zip_;
}
void User::setZip(int zip) {
	zip_ = zip;
}

MyList<int>* User::friends() {
	return friends_;
}
