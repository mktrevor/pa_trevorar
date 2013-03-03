#include <string>
#include <iostream>
#include <fstream>
#include "user.h"
#include "bcuser.h"
#include "mylist.h"
#include "gmlwriter.h"

using namespace std;

void GMLWriter::write(MyList<User*>* userList, ofstream &output) {
	output << "graph [" << endl;
	output << "  directed 1" << endl;
	
	for(int i = 0; i < userList->size(); i++) {
		output << "  node [" << endl;
		output << "    id " << userList->at(i)->getId() << endl;
		output << "    name \"" << userList->at(i)->getName() << "\"" << endl;
		output << "    age " << userList->at(i)->getAge() << endl;
		output << "    zip " << userList->at(i)->getZip() << endl;
		output << "  ]" << endl;
		
	}
	
	for(int i = 0; i < userList->size(); i++) {
		for(int j = 0; j < userList->at(i)->friends()->size(); j++) {
			output << "  edge [" << endl;
			output << "    source " << userList->at(i)->getId() << endl;
			output << "    target " << userList->at(i)->friends()->at(j) << endl;
			output << "  ]" << endl;
			
		}
	}
	
	output << "]";
};

void GMLWriter::write(MyList<BCUser*>* userList, MyList<double>* BCList, ofstream &output) {
	for(int i = 0; i < userList->size(); i++) {
		output << userList->at(i)->getId() << " " << BCList->at(i) << endl;
	}
}
