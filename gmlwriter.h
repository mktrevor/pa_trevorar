#ifndef GML_WRITER_H
#define GML_WRITER_H
#include <string>
#include <iostream>
#include "bcuser.h"
#include "mylist.h"

using namespace std;

class GMLWriter {	
	public:		
		static void write(MyList<User*> userList, ofstream &of);
		
		static void write(MyList<BCUser*> userList, ofstream &of);
		
	private:
	
};

#endif
