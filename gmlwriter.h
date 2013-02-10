#ifndef GML_WRITER_H
#define GML_WRITER_H
#include <string>
#include <iostream>
#include "user.h"
#include "mylist.h"

using namespace std;

class GMLWriter {
	private:
		MyList<User*> userList_;
	
	public:
		GMLWriter();
		GMLWriter(MyList<User*> userList);
		~GMLWriter();
		
		void write(ofstream of);
};

#endif
