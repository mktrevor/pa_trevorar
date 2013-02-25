#include <string>
#include <iostream>
#include <fstream>
#include "bcuser.h"
#include "mylist.h"
#include "gmlwriter.h"

using namespace std;

void GMLWriter::write(MyList<User*> userList, ofstream &of) {
	of << "graph [" << endl;
	of << "  directed 1" << endl;
	
	for(int i = 0; i < userList.size(); i++) {
		of << "  node [" << endl;
		of << "    id " << userList.at(i)->getId() << endl;
		of << "    name \"" << userList.at(i)->getName() << "\"" << endl;
		of << "    age " << userList.at(i)->getAge() << endl;
		of << "    zip " << userList.at(i)->getZip() << endl;
		of << "  ]" << endl;
	}
	
	for(int i = 0; i < userList.size(); i++) {
		for(int j = 0; j < userList.at(i)->friends()->size(); j++) {
			of << "  edge [" << endl;
			of << "    source " << userList.at(i)->getId() << endl;
			of << "    target " << userList.at(i)->friends()->at(j) << endl;
			of << "  ]" << endl;
			
		}
	}
	
	of << "]";
		
};

void GMLWriter::write(MyList<BCUser*> userList, ofstream &of) {
	of << "graph [" << endl;
	of << "  directed 1" << endl;
	
	for(int i = 0; i < userList.size(); i++) {
		of << "  node [" << endl;
		of << "    id " << userList.at(i)->getId() << endl;
		of << "    name \"" << userList.at(i)->getName() << "\"" << endl;
		of << "    age " << userList.at(i)->getAge() << endl;
		of << "    zip " << userList.at(i)->getZip() << endl;
		of << "  ]" << endl;
	}
	
	for(int i = 0; i < userList.size(); i++) {
		for(int j = 0; j < userList.at(i)->friends()->size(); j++) {
			of << "  edge [" << endl;
			of << "    source " << userList.at(i)->getId() << endl;
			of << "    target " << userList.at(i)->friends()->at(j) << endl;
			of << "  ]" << endl;
			
		}
	}

	of << "]";	
	
};
