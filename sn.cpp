#include <iostream>
#include <vector>
#include <string>
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

	vector<string> nodes;
	vector<string> edges;
	
	GMLReader::read(argv[1], nodes, edges);
	
	for(int i = 0; i < nodes.size(); i++) {
		cout << nodes[i] << endl;
	}
	
	for(int i = 0; i < edges.size(); i++) {
		cout << edges[i] << endl;
	}

  return 0;
}
