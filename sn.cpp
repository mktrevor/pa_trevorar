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
	
	string s;
	
	for(int i = 0; i < nodes.size(); i++) {
	
		User* newUser = new User();
	
		s = nodes[i];
		
		stringstream ss;
		
		ss << s;
		
		addUserData(newUser, ss);
		
		//ss >> infoType >> id >> infoType >> name1 >> name2 >> infoType >> age >> infoType >> zip;
		
		//User* newUser = new User(name1 + " " + name2, age, zip, id);
		
		userList.push_back(newUser);
	}
	
	for(int i = 0; i < edges.size(); i++) {
		
		
		
	}
	
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
	}*/
	
	for(int i = 0; i < edges.size(); i++) {
		cout << edges[i] << endl;
	}

  return 0;
}
