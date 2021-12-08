#ifndef EDGE_H
#define EDGE_H
#include <vector>
#include "Node.h" 

using namespace std; 

class Edge{
public:
	Edge();
	int weight; 
	Node* node1;
	Node* node2;
	bool visited; 
};







#endif
