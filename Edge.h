#ifndef EDGE_H
#define EDGE_H
#include <vector>
#include "Node.h" 

using namespace std; 

class Edge{
public:
	Edge();
       	Edge(int a); 	
	int weight; 
	vector<Node*> eNodes; 
};







#endif
