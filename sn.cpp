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
	
	ofstream outputFile;
	
	string s;
	
	for(int i = 0; i < nodes.size(); i++) {
	
		User* newUser = new User();
	
		s = nodes[i];
		
		stringstream ss;
		
		ss << s;
		
		addUserData(newUser, ss);
		
		userList.push_back(newUser);
	}
	
	userList.at(0)->friends()->push_back(1);
	userList.at(1)->friends()->push_back(0);
	userList.at(0)->friends()->push_back(2);
	userList.at(2)->friends()->push_back(0);
	
	outputFile.open(argv[3]);
	
	GMLWriter::write(userList, outputFile);
	
	outputFile.close();
	
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

  return 0;
}
