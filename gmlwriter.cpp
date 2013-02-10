#include <string>
#include <iostream>
#include <fstream>
#include "user.h"
#include "mylist.h"
#include "gmlwriter.h"

using namespace std;

GMLWriter::GMLWriter(MyList<User*> userList) {
	userList_ = userList;
};

void GMLWriter::write(ofstream of) {
	of << "graph [" << endl;
	of << "  directed 1" << endl;
	
	for(int i = 0; i < userList_.size(); i++) {
		of << "  node [" << endl;
		of << "    id " << userList_.at(i)->getId() << endl;
		of << "    name " << userList_.at(i)->getName() << endl;
		of << "    age " << userList_.at(i)->getAge() << endl;
		of << "    zip " << userList_.at(i)->getZip() << endl;
		of << "  ]" << endl;
	}
	
	for(int i = 0; i < userList_.size(); i++) {
		for(int j = 0; j < userList_.at(i)->friends()->size(); j++) {
			of << "  edge [" << endl;
			of << "    source " << userList_.at(i)->getId() << endl;
			of << "    target " << userList_.at(i)->friends()->at(j) << endl;
			of << "  ]" << endl;
			
		}
	}
	
	of << "]";
		
};
