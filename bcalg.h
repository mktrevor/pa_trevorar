#ifndef BCALG_H
#define BCALG_H
#include <iostream>
#include "bcuser.h"
#include "mylist.h"

using namespace std;

class BCAlg {
	public:
		static MyList<double>* computeBC(MyList<BCUser*> &userList);
};

#endif
