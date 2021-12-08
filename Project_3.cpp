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

void Djikstra(Graph G, int s, int i, int c)
{
	for(int v=0; v< G.nodes.size(); v++)
	{
		G.nodes[v]->dist=INT_MAX;
	}//set all distances to infinity
	

	queue<Node*> Q;//create a queue of nodes

	for(int v=0; v<G.nodes.size(); v++)
	{	
		Q.push(G.nodes[v]); 
	}//add all the nodes to the queue

	G.nodes[s]->dist=0; //distance to our starting node is 0; 

	
	 
	while(!Q.empty())
	{
		Node* currNode= Q.front();//take the top node in the queue
		Q.pop(); 
		for(int v=0; v<currNode->neighbors.size(); v++)//for loop to go through all neighbors of the current node 
		{
			Node* neighbor=currNode->neighbors[v]; 
			if(neighbor->dist >(currNode->dist /*+ distance between the current neighbor and currNode)*/))
			{
				neighbor->dist= currNode->dist /*+ distance to current neighbor*/;
				neighbor->predecessor=currNode; 
			}//change the distance and predecessor if shorter distance is found
		}
	}
}

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


}//give each edge two nodes to connect


//END OF USER INPUTS 

//BEGIN CREATING INTERMEDIATE GRAPH 
G.printAdjList(); 



cout << n << m << c << i<< endl;
return 0;
}
