#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "user.h"
#include "mylist.h"
#include "gmlreader.h"
// Add appropriate headers here

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 4){
    cerr << "Please provide the input GML file, command file, and output file" << endl;
    return 1;
  }
  
  MyList<User*> userList;

	vector<string> nodes;
	vector<string> edges;
	
	GMLReader::read(argv[1], nodes, edges);
	
	string s;
	stringstream ss;
	string infoType;
	
	for(int i = 0; i < nodes.size(); i++) {
		s = nodes[i];
	}
	
	/*for(int i = 0; i < nodes.size(); i++) {
		cout << nodes[i] << endl;
	}
	
	for(int i = 0; i < edges.size(); i++) {
		cout << edges[i] << endl;
	}*/

  return 0;
}
