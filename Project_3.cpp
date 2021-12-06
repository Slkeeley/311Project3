#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "Node.h"
#include "Graph.h"
#include "Edge.h"

using namespace std;

bool verifyPath(Graph G, vector<int> path, int i, int c)//i for initial charge of vehicle, c for max charge
{
	return false; 
}//check if the vehicle is able to make the trip with the selected path of nodes 

void Djikstra(Graph G, int s, int i, int c)
{
/*	for(int u=0; u <G.nodes.size(); u++)
	{
		G.nodes[u].dist=INT_MAX;
	}//set all distances to infinity to begin
	G.nodes[s]=0; 
	
	for int(u=0, u <G.nodes.size(); u++)
	{
		

	}*/
}

int main()
{
//GLOBAL VARIABLES
int n;//number of nodes in the graph;
int m; //number of edges in the graph;
int c; //range of vehicle on max charge
int i; //range of vehicle
int start; 
int end;
Graph G;//MAIN GRAPH 
Graph sG;//intermediate graph  

//TEMPORARY VARIABLES
int nodeID;
int charge; 

//USER INPUT STARTS HERE
cin >> n >> m >> c >>i;//input global variables 
cin >> start >> end; 

for(int v=0; v<n; v++)
{
	cin >> nodeID >> charge; 
	Node x(v);
	G.nodes.push_back(x);//expand the graph by adding a new node; 
	G.nodes[v].id=v;
	if(charge==1) { G.nodes[v].charger=true; } //set the most recent node's ID and whether it has a charger or not

}// give each node an id and whether or not it has a charging station 

for(int v=0; v<m; v++)
{
	int x=-1, y=-1, dist=-1; 
	cin >> x>> y >> dist; //values being input are the nodes' indexes 
	//add new nodes to neighboring vectors
	G.nodes[x].neighbors.push_back(&G.nodes[y]); 
       	G.nodes[y].neighbors.push_back(&G.nodes[x]);//each nodes vector of neighbors is being pushed back
	
	//Create a new edge
	Edge e(dist);
	G.edges.push_back(e);
	G.edges[v].eNodes.push_back(&G.nodes[x]); 
	G.edges[v].eNodes.push_back(&G.nodes[y]); 

}//give each edge two nodes to connect
//END OF USER INPUTS 
//BEGIN CREATING INTERMEDIATE GRAPH 
 

cout << n << m << c << i<< endl;
return 0;
}
