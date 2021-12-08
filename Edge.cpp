#include "Edge.h"
#include "Node.h"
#include <vector>

using namespace std; 

Edge::Edge()
{
	weight=0; 
	id=0;
       	visited=false; 	
}

Edge::Edge(int w, int ID)
{
	weight=w; 
	id=ID; 
	visited=false;
}
