#ifndef BCUSER_H
#define BCUSER_H

#include "user.h"

BCUser::BCUser() {
	name_ = "";
	age_ = 0;
	zip_ = 0;
	id_ = 0;
	friends_ = new MyList<int>;
	
	dist = -1;
	numsp = 0;
	delta = 0;
	bc = 0;
}

BCUser::~BCUser() {
	delete friends_;
}

#endif
