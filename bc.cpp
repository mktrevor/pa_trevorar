#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "bcuser.h"
#include "mylist.h"
#include "gmlreader.h"
#include "gmlwriter.h"
#include "bcalg.h"
// Add appropriate headers here


using namespace std;

//Adds the user data from a string into a user object.
void addUserData(BCUser* user, string s1) {
	//Declaration of variables to hold values temporarily until they're added to the object.
	string datatype, name, newString;
	int value = 0;
	
	stringstream ss;	
	ss << s1;
	//This loop cycles through pairs of values, using the first value to identify what data type it is, and then inputting it into the correct user attribute.
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
		//Clearing out the stringstream.
		ss.clear();
		ss.flush();
	
		ss << newString;
		newString = "";
	}
}

//This function adds the initial friend connections to the list of users using the vector that stores edge information.
void initialAddFriends(MyList<BCUser*>* userList, string s2) {
	//Initial declaration of variables.
	stringstream ss;
	int id1, id2;
	string command1, command2;
	ss << s2;
	//Extracting info from the stringstream.
	ss >> command1 >> id1 >> command2 >> id2;
	
	//Searching the list of users for a certain id, and adding another id to the first's friend list.
	for(int i = 0; i < userList->size(); i++) {
		if(userList->at(i)->getId() == id1) {
			userList->at(i)->addFriend(id2);
		}
	}
}
	
int main(int argc, char *argv[])
{
  if(argc < 3){
    cerr << "Please provide the input GML file and output file" << endl;
    return 1;
  }
  
  //Checking to see if the input GML file is valid.
  ifstream inputGML;
  inputGML.open(argv[1]);
  if(!inputGML.is_open()) {
  	cout << "Cannot open GML input file." << endl;
  	return 1;
  } else {
  	inputGML.close();
  }
  
  //Initial declaration of a list of users and a list of BC scores.
  MyList<BCUser*>* userList = new MyList<BCUser*>;
	MyList<double>* BCList;

	//These vectors will hold the node and edge information.
	vector<string> nodes;
	vector<string> edges;
	
	//Transferring information from input GML file into the nodes and edges vectors.
	GMLReader::read(argv[1], nodes, edges);
	
	//Declaring output file.
	ofstream outputFile;
	
	//This loop goes through each line of the nodes vector and populates a user object.
	for(int i = 0; i < nodes.size(); i++) {
	
		string s1 = nodes[i];
		
		BCUser* newUser = new BCUser();
		
		//This function transfers data from the string into the user object.
		addUserData(newUser, s1);
		
		//Adding the new user to the end of the list of users.
		userList->push_back(newUser);
	}
	
	//This loop runs through each line of the edges vector and adds the info to the appropriate user object.
	for(int i = 0; i < edges.size(); i++) {
		string s2 = edges[i];
		
		//Adding friend connections from the input GML file.
		initialAddFriends(userList, s2);
	}

	BCList = BCAlg::computeBC(userList);
	
	cout << userList << endl;
	
	for(int i = 0; i < BCList->size(); i++) {
		cout << BCList->at(i) << endl;
	}
			
	outputFile.open(argv[2]);
	//Writing a new GML file using the information from the list of users.
	GMLWriter::write(userList, BCList, outputFile);
	
	//Closing out input and output files.
	outputFile.close();
	
  return 0;
}
