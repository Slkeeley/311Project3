#include "Edge.h"
#include "Node.h"
#include <vector>

using namespace std; 

Edge::Edge()
{
	weight=0; 
	eNodes= {};
}

Edge::Edge(int a)
{
	weight=a; 
	eNodes={}; 

}
