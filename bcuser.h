#ifndef BCUSER_H
#define BCUSER_H
#include "mylist.h"
#include "user.h"
#include <string>
#include <iostream>

using namespace std;

class BCUser : public User {
	public:
		BCUser();
		~BCUser();
		
		int dist;							// distance to current source vertex
		int num_sp;						// number of shortest paths
		MyList<int> preds;		// list of predecessors
		double delta;					// partial BC score
		double bc;						// total BC score
};

#endif

