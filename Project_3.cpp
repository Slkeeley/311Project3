#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <queue> 
#include "Node.h"
#include "Graph.h"
#include "Edge.h"

using namespace std;

bool verifyPath(Graph G, vector<int> path, int i, int c)//i for initial charge of vehicle, c for max charge
{
	return false; 
}//check if the vehicle is able to make the trip with the selected path of nodes 

int main()
{
//GLOBAL VARIABLES
int n;//number of nodes in the graph;
int m; //number of edges in the graph;
int c; //range of vehicle on max charge
int i; //range of vehicle
int start;//starting point node
int end;//destination node


//TEMPORARY INPUT VARIABLES FOR CONSTRUCTION
int nodeID;
int charge; 

//GRAPHS
Graph G;//main graph
Graph sG;//intermediate graph

//USER INPUT STARTS HERE
cin >> n >> m >> c >>i;//input global variables 
cin >> start >> end; //input start and end points


for(int v=0; v<n; v++)//construct the graph and give select nodes chargers
{
	cin >> nodeID >> charge; 
	Node* x= new Node(v); 
	G.nodes.push_back(x);//expand the graph by adding a new node; 
	G.nodes[v]->id=v;
	if(charge==1) { G.nodes[v]->charger=true; } //set the most recent node's ID and whether it has a charger or not

}// give each node an id and whether or not it has a charging station 



for(int v=0; v<m; v++)//create edges between select nodes
{
	int x=-1, y=-1, dist=-1; 
	cin >> x>> y >> dist; //values being input are the nodes' indexes 
	
	//add new nodes to neighboring vectors
	G.nodes[x]->neighbors.push_back(G.nodes[y]); 
       	G.nodes[y]->neighbors.push_back(G.nodes[x]);//each nodes vector of neighbors is being pushed back

	//create new edges to be added to each nodes edge vector; 
	Edge* e= new Edge(dist, x);
	Edge* f= new Edge(dist, y); 
	G.nodes[x]->edges.push_back(e); 
	G.nodes[y]->edges.push_back(e); 

}//give each edge two nodes to connect


//END OF USER INPUTS 

//BEGIN CREATING INTERMEDIATE GRAPH 
for(int v=0; v<n; v++)
{
	if(G.nodes[v]->charger==true || G.nodes[v]->id==start || G.nodes[v]->id==end)
	{
		Node* x= new Node(G.nodes[v]->id); 
		sG.nodes.push_back(x);
	}//only add the start, end and charging nodes to this simplified graph
}

for(int v=0; v<sG.nodes.size(); v++)
{

	G.Djikstra(sG.nodes[v]->id);//find all distances to nodes in main graph from charging stations and start/end 
	for(int j=0; j<sG.nodes.size(); j++)
	{
		Node* newNeighbor= sG.nodes[j];
		newNeighbor->dist=G.nodes[newNeighbor->id]->dist; 
		if(newNeighbor->dist <= c)//if the distance to a charging station is less than max charge add the edge to the graph;
		{
			sG.nodes[v]->neighbors.push_back(sG.nodes[j]); 
			sG.nodes[j]->neighbors.push_back(sG.nodes[v]);
		}

	}	

}//Add the neighbors to the simpified graph 

sG.Djikstra(sG.nodes[sG.nodes.size()-1]->id);//use Djikstra's to find the distances from the destination to the start; 

int totalDistance=sG.nodes[0]->dist;

if(totalDistance==INT_MAX)
{
	cout<<"No path"<<endl;
	return 0; 
}

cout << totalDistance<<endl;




cout << "program is ending" << endl;
return 0;
}
