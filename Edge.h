#ifndef EDGE_H
#define EDGE_H
#include <vector>
 

using namespace std; 

class Edge{
public:
	Edge();
       	Edge(int w, int ID); 	
	int weight; 
	int id;  
	bool visited; 
};







#endif
