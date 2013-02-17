#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "user.h"
#include "mylist.h"
#include "gmlreader.h"
#include "gmlwriter.h"
// Add appropriate headers here

void addUserData(User* user, stringstream &ss) {
	string datatype, name, newString;
	int value = 0;
	ss >> datatype;
	
	for(int i = 0; i < 4; i++) {
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
		ss >> datatype;
	}
}

void addFriendConnections(MyList<User*> userList, ifstream &inputFile) {
	string firstName1, lastName1, firstName2, lastName2;
	string friend1, friend2;
	
	char action;
	
	while(inputFile.good()) {
	
		inputFile >> action >> firstName1 >> lastName1 >> firstName2 >> lastName2;
	
		friend1 = firstName1 + " " + lastName1;
		friend2 = firstName2 + " " + lastName2;
		friend1 = friend1.substr(1, friend1.length() - 2);
		friend2 = friend2.substr(1, friend2.length() - 2);
		
		if(action == 'a') {
			for(int i = 0; i < userList.size(); i++) {
				if(userList.at(i)->getName() == friend1) {
					
					
				}
			}
		}
	
		cout << action << friend1 << friend2 << endl;
	}
}

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 4){
    cerr << "Please provide the input GML file, command file, and output file" << endl;
    return 1;
  }
  
  MyList<User*> userList;

	vector<string> nodes;
	vector<string> edges;
	
	GMLReader::read(argv[1], nodes, edges);
	
	ofstream outputFile;
	
	ifstream friendCommands;
	
	for(int i = 0; i < nodes.size(); i++) {
	
		User* newUser = new User();
	
		string s = nodes[i];
		
		stringstream ss;
		
		ss << s;
		
		addUserData(newUser, ss);
		
		userList.push_back(newUser);
	}
	
	/*userList.at(0)->friends()->push_back(1);
	userList.at(1)->friends()->push_back(0);
	userList.at(0)->friends()->push_back(2);
	userList.at(2)->friends()->push_back(0);*/
	
	friendCommands.open(argv[2]);
	
	addFriendConnections(userList, friendCommands);
	
	outputFile.open(argv[3]);
	
	GMLWriter::write(userList, outputFile);
	

	
	//The follow lines are for testing purposes.
	
	/*for(int i = 0; i < userList.size(); i++) {
		cout << userList.at(i)->getId() << endl;
	}
	
	for(int i = 0; i < userList.size(); i++) {
		cout << userList.at(i)->getName() << endl;
	}
	
	for(int i = 0; i < userList.size(); i++) {
		cout << userList.at(i)->getAge() << endl;
	}
	
	for(int i = 0; i < userList.size(); i++) {
		cout << userList.at(i)->getZip() << endl;
	}
	
	for(int i = 0; i < nodes.size(); i++) {
		cout << nodes[i] << endl;
	}
	
	for(int i = 0; i < edges.size(); i++) {
		cout << edges[i] << endl;
	}*/
	
	friendCommands.close();
	outputFile.close();
	
  return 0;
}
