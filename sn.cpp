#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "user.h"
#include "mylist.h"
#include "gmlreader.h"
// Add appropriate headers here

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
	string infoType;
	int id = 0;
	string name1 = "", name2 = "";
	int zip = 0;
	int age = 0;
	
	for(int i = 0; i < nodes.size(); i++) {
	
		s = nodes[i];
		
		stringstream ss;
		
		ss << s;
		
		ss >> infoType >> id >> infoType >> name1 >> name2 >> infoType >> age >> infoType >> zip;
		
		User* newUser = new User(name1 + " " + name2, age, zip, id);
		
		userList.push_back(newUser);
	}
	
	for(int i = 0; i < userList.size(); i++) {
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
	
	/*for(int i = 0; i < nodes.size(); i++) {
		cout << nodes[i] << endl;
	}
	
	for(int i = 0; i < edges.size(); i++) {
		cout << edges[i] << endl;
	}*/

  return 0;
}
