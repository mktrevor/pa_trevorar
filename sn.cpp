#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "user.h"
#include "mylist.h"
#include "gmlreader.h"
#include "gmlwriter.h"

// Add appropriate headers here

void addUserData(User* user, string s1) {
	
	string datatype, name, newString;
	int value = 0;
	
	stringstream ss;	
	ss << s1;
	
	for(int i = 0; i < 4; i++) {
		ss >> datatype;
		
		if(datatype == "id") {
			ss >> value;
			getline(ss, newString, '\n');
			user->setId(value);
		} else if(datatype == "age") {
			ss >> value;
			getline(ss, newString, '\n');
			user->setAge(value);
		} else if(datatype == "zip") {
			ss >> value;
			getline(ss, newString, '\n');
			user->setZip(value);
		} else if(datatype == "name") {
			getline(ss, datatype, '\"');
			getline(ss, name, '\"');
			getline(ss, newString, '\n');
			user->setName(name);
		}
	
		ss.clear();
		ss.flush();
	
		ss << newString;
		newString = "";
	}
}

void initialAddFriends(MyList<User*> &userList, string s2) {
	stringstream ss;
	int id1, id2;
	string command1, command2;
	ss << s2;
	
	ss >> command1 >> id1 >> command2 >> id2;
	
	for(int i = 0; i < userList.size(); i++) {
		if(userList.at(i)->getId() == id1) {
			userList.at(i)->addFriend(id2);
		}
	}
}
	
	

void addFriendConnections(MyList<User*> &userList, ifstream &inputFile) {
	string firstName1, lastName1, firstName2, lastName2;
	string friend1, friend2;
	
	int checker1 = 0, checker2 = 0;
	
	char action;
	
	while(inputFile.good()) {
	
		inputFile >> action >> firstName1 >> lastName1 >> firstName2 >> lastName2;
	
		friend1 = firstName1 + " " + lastName1;
		friend2 = firstName2 + " " + lastName2;
		friend1 = friend1.substr(1, friend1.length() - 2);
		friend2 = friend2.substr(1, friend2.length() - 2);
		
		try {
			if(action == 'a') {
				for(int i = 0; i < userList.size(); i++) {
					if(userList.at(i)->getName() == friend1) {
						checker1++;
						for(int j = 0; j < userList.size(); j++) {
							if(userList.at(j)->getName() == friend2) {
								checker2++;
								userList.at(i)->addFriend(userList.at(j)->getId());
								userList.at(j)->addFriend(userList.at(i)->getId());
							}
						}
					}
				}
			}
			else if(action == 'r') {
				for(int i = 0; i < userList.size(); i++) {
					if(userList.at(i)->getName() == friend1) {
						checker1++;
						for(int j = 0; j < userList.size(); j++) {
							if(userList.at(j)->getName() == friend2) {
								checker2++;
								userList.at(i)->removeFriend(userList.at(j)->getId());
								userList.at(j)->removeFriend(userList.at(i)->getId());
							}
						}
					}
				}
			}	else {
				throw exception();
			}
		} catch(exception e) {
			cout << "Missing add/remove command on this line." << endl;
		}
		try {
			if(checker1 == 0) {
				throw logic_error("User does not exist");
		}
		} catch(logic_error le) {
			cout << le.what() << endl;
		}
		try {
			if(checker2 == 0) {
			throw logic_error("User does not exist");
			}
		} catch(logic_error le) {
			cout << le.what() << endl;
		}
		friend1 = "";
		friend2 = "";
		firstName1 = "";
		firstName2 = "";
		lastName1 = "";
		lastName2 = "";
	}
}

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 4){
    cerr << "Please provide the input GML file, command file, and output file" << endl;
    return 1;
  }
  
  ifstream inputGML;
  inputGML.open(argv[1]);
  if(!inputGML.is_open()) {
  	cout << "Cannot open GML input file." << endl;
  	return 1;
  } else {
  	inputGML.close();
  }
  
  MyList<User*> userList;

	vector<string> nodes;
	vector<string> edges;
	
	GMLReader::read(argv[1], nodes, edges);
	
	ofstream outputFile;
	
	ifstream friendCommands;
	
	for(int i = 0; i < nodes.size(); i++) {
	
		string s1 = nodes[i];
		
		User* newUser = new User();
		
		addUserData(newUser, s1);
		
		userList.push_back(newUser);
	}
	
	for(int i = 0; i < edges.size(); i++) {
		string s2 = edges[i];
		initialAddFriends(userList, s2);
	}
		
	friendCommands.open(argv[2]);

	if(friendCommands.is_open()) {
		addFriendConnections(userList, friendCommands);
	} else {
		cout << "Cannot open the command file" << endl;
	} 
		
	outputFile.open(argv[3]);
	
	GMLWriter::write(userList, outputFile);
	
	friendCommands.close();
	outputFile.close();
	
  return 0;
}
