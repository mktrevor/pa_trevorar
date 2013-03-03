#include <string>
#include <iostream>
#include "user.h"

using namespace std;

User::User() {
	name_ = "";
	age_ = 0;
	zip_ = 0;
	id_ = 0;
	friends_ = new MyList<int>;
};

User::User(string name, int age, int zip, int id) {
	name_ = name;
	age_ = age;
	zip_ = zip;
	id_ = id;
	friends_ = new MyList<int>;
};

User::~User() {
	clearFriends();
};

string User::getName() {
	return name_;
};
void User::setName(string name) {
	name_ = name;
};

int User::getAge() {
	return age_;
};
void User::setAge(int age) {
	age_ = age;
};

int User::getZip() {
	return zip_;
};
void User::setZip(int zip) {
	zip_ = zip;
};

int User::getId() {
	return id_;
};
void User::setId(int id) {
	id_ = id;
};
	
void User::addFriend(int id) { //Adds an id number to a user's friendlist.
	friends_->push_back(id);
};

void User::removeFriend(int id) { //Removes an id number from a user's friendlist.
	friends_->remove(id);
}

void User::clearFriends() {
	delete [] friends_;
}

MyList<int>* User::friends() {
	return friends_;
};
