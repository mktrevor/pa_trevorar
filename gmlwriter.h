#ifndef GML_WRITER_H
#define GML_WRITER_H
#include <string>
#include <iostream>
#include "user.h"
#include "bcuser.h"
#include "mylist.h"

using namespace std;

class GMLWriter {	
	public:		
		static void write(MyList<User*>* userList, ofstream &output);
		
		static void write(MyList<BCUser*>* userList, ofstream &output);
	
};

#endif
