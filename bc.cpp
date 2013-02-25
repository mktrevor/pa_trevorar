#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "bcuser.h"
#include "user.h"
#include "mylist.h"
#include "gmlreader.h"
#include "gmlwriter.h"
// Add appropriate headers here

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
void initialAddFriends(MyList<BCUser*> &userList, string s2) {
	//Initial declaration of variables.
	stringstream ss;
	int id1, id2;
	string command1, command2;
	ss << s2;
	//Extracting info from the stringstream.
	ss >> command1 >> id1 >> command2 >> id2;
	
	//Searching the list of users for a certain id, and adding another id to the first's friend list.
	for(int i = 0; i < userList.size(); i++) {
		if(userList.at(i)->getId() == id1) {
			userList.at(i)->addFriend(id2);
		}
	}
}
	
//This function uses the information from the commands document to add and remove friend connections.
void addFriendConnections(MyList<BCUser*> &userList, ifstream &inputFile) {
	//Declaring variables to store strings temporarily.
	string firstName1, lastName1, firstName2, lastName2;
	string friend1, friend2;
	
	//These checkers will increment if a user's name is found so that an exception can be thrown if the name is never found.
	int checker1 = 0, checker2 = 0;
	//'a' for add or 'r' for remove
	char action;
	
	//While the inputFile is okay for input/output.
	while(inputFile.good()) {
		//Extracting data from the commands document into variables.
		inputFile >> action >> firstName1 >> lastName1 >> firstName2 >> lastName2;
		//Creating full name variables.
		friend1 = firstName1 + " " + lastName1;
		friend2 = firstName2 + " " + lastName2;
		//Removing the quotation marks.
		friend1 = friend1.substr(1, friend1.length() - 2);
		friend2 = friend2.substr(1, friend2.length() - 2);
		
		//These loops search through the user list to find the two different users and add them to each others' friend lists.
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
			//If the action is 'r', though, the users are removed from each others' friend lists.
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
		
		//These statements check to see if a user was found with the specified name.
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
		//Resetting the variables for the next loop through.
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
  
  //Checking to see if the input GML file is valid.
  ifstream inputGML;
  inputGML.open(argv[1]);
  if(!inputGML.is_open()) {
  	cout << "Cannot open GML input file." << endl;
  	return 1;
  } else {
  	inputGML.close();
  }
  
  //Initial declaration of a list of users.
  MyList<BCUser*> userList;

	//These vectors will hold the node and edge information.
	vector<string> nodes;
	vector<string> edges;
	
	//Transferring information from input GML file into the nodes and edges vectors.
	GMLReader::read(argv[1], nodes, edges);
	
	//Declaring input and output files.
	ofstream outputFile;
	ifstream friendCommands;
	
	//This loop goes through each line of the nodes vector and populates a user object.
	for(int i = 0; i < nodes.size(); i++) {
	
		string s1 = nodes[i];
		
		BCUser* newUser = new BCUser();
		
		//This function transfers data from the string into the user object.
		addUserData(newUser, s1);
		
		//Adding the new user to the end of the list of users.
		userList.push_back(newUser);
	}
	
	//This loop runs through each line of the edges vector and adds the info to the appropriate user object.
	for(int i = 0; i < edges.size(); i++) {
		string s2 = edges[i];
		
		//Adding friend connections from the input GML file.
		initialAddFriends(userList, s2);
	}
		
	friendCommands.open(argv[2]);
	//Checking to see if command file is valid.
	if(friendCommands.is_open()) {
		//Adding/removing all friend connections from the command file.
		addFriendConnections(userList, friendCommands);
	} else {
		cout << "Cannot open the command file" << endl;
	} 
		
	outputFile.open(argv[3]);
	//Writing a new GML file using the information from the list of users.
	GMLWriter::write(userList, outputFile);
	
	//Closing out input and output files.
	friendCommands.close();
	outputFile.close();
	
  return 0;
}
