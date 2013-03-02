#include <iostream>
#include "bcuser.h"
#include "mylist.h"
#include "bcalg.h"
#include "stack.h"
#include "queue.h"

using namespace std;

MyList<double>* BCAlg::computeBC(MyList<BCUser*> &userList) {
	for(int i = 0; i < userList.size(); i++) {
		userList.at(i)->bc = 0;
	}
	
	for(int i = 0; i < userList.size(); i++) {
		for(int j = 0; j < userList.size(); j++) {
			userList[j]->num_sp = 0;
			userList[j]->dist = -1;
			userList[j]->delta = 0.0;
			userList[j]->preds.clear();
		}
		
		userList[i]->num_sp = 1;
		userList[i]->dist = 0;
		
		Stack<BCUser*> userStack;
		Queue<BCUser*> userQueue;
		
		userQueue.push_back(userList[i]);
		
		while(!userQueue.empty()) {
			BCUser* v = userQueue.front(); //v is the starting vertex
			userQueue.pop_front();
			userStack.push_front(v);
			
			for(int i = 0; i < v->friends()->size(); i++) {
				int buddyID = v->friends()->at(i); //buddy will be set to equal each one of v's friends in the course of this loop
				for(int j = 0; j < userList.size(); j++) {
					BCUser* buddy = userList[j];
					if(buddyID == buddy->getId()) {
						if(buddy->dist == -1) {
							userQueue.push_back(buddy);
							buddy->dist = v->dist + 1;
						}
						if(buddy->dist == v->dist + 1) {
							buddy->num_sp = buddy->num_sp + v->num_sp;
							buddy->preds.push_back(v->getId());
						}
					}
				
				}
			}
		}		
		
		
		
		
	}
	
	return NULL;	
}
