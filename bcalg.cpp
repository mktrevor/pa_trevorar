#include <iostream>
#include "bcuser.h"
#include "mylist.h"
#include "bcalg.h"
#include "stack.h"
#include "queue.h"

using namespace std;

MyList<double>* BCAlg::computeBC(MyList<BCUser*>* userList) {
	
	MyList<double>* BCList = new MyList<double>; //Initial declaration of a list of BC scores

	for(int i = 0; i < userList->size(); i++) { //Setting all BC scores to 0
		userList->at(i)->bc = 0;
	}
	
	for(int i = 0; i < userList->size(); i++) { //This loop will run through for each user in the userList
		for(int j = 0; j < userList->size(); j++) { //First, clear out all the variables for each user
			userList->at(j)->num_sp = 0;
			userList->at(j)->dist = -1;
			userList->at(j)->delta = 0.0;
			userList->at(j)->preds->clear();
			userList->at(j)->preds = new MyList<int>;
		}
		
		userList->at(i)->num_sp = 1;
		userList->at(i)->dist = 0;
	
		//Initial declaration of a stack and queue to hold users	
		Stack<BCUser*> userStack; 
		Queue<BCUser*> userQueue;
		
		userQueue.push_back(userList->at(i));
		
		while(!userQueue.empty()) {
			BCUser* v = userQueue.front(); //v is the starting vertex
			userQueue.pop_front();
			userStack.push_front(v);
			
			for(int i = 0; i < v->friends()->size(); i++) {
				int buddyID = v->friends()->at(i); //buddy will be set to equal each one of v's friends in the course of this loop
				for(int j = 0; j < userList->size(); j++) {
					BCUser* buddy = userList->at(j);
					
					if(buddyID == buddy->getId()) { //Finding the user with a certain ID number.
						if(buddy->dist == -1) {
							userQueue.push_back(buddy);
							buddy->dist = v->dist + 1;
						}
						if(buddy->dist == v->dist + 1) {
							buddy->num_sp = buddy->num_sp + v->num_sp;
							buddy->preds->push_back(v->getId());
						}
					}
				}
			}
		}
		
		//This loop calculates the bc score for each user on the stack
		while(!userStack.empty()) {
			BCUser* user = userStack.front();
			userStack.pop_front();
			for(int i = 0; i < user->preds->size(); i++) {
				int buddyID = user->preds->at(i);
				for(int j = 0; j < userList->size(); j++) {
					BCUser* buddy = userList->at(j);
					if(buddyID == buddy->getId()) {
						buddy->delta = buddy->delta + (buddy->num_sp/user->num_sp)*(1+user->delta);
						break;
					}
				}
			}
			user->bc = user->bc + user->delta;
		}
	}	
	
	//Populating the BC score list
	for(int i = 0; i < userList->size(); i++) {
		BCList->push_back(userList->at(i)->bc);
	}
	
	double min = BCList->at(0);
	double max = BCList->at(0);
	
	//Finding the maximum and minimum BC scores
	for(int i = 1; i < BCList->size(); i++) {
		if(BCList->at(i) > max) {
			max = BCList->at(i);
		}
		if(BCList->at(i) < min) {
			min = BCList->at(i);
		}
	}
	
	//Normalizing each score to be between 0 and 1
	for(int i = 0; i < BCList->size(); i++) {
		BCList->at(i) = (BCList->at(i) - min)/(max - min);
	}
	
	return BCList;	
}
