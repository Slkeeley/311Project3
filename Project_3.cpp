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

vector<int> stations(Graph G, int startNode, int endNode)
{
	vector<int> pathTaken;
	Node* currIndex = G.nodes[G.indexCorrection(startNode)];
	pathTaken.push_back(currIndex->id);

	while(currIndex->predecessor != nullptr)
	{
		pathTaken.push_back(currIndex->predecessor->id); 
		currIndex=currIndex->predecessor;
	
	}	


	return pathTaken; 
}

vector<int> route(Graph G, Graph sG, vector<int> path)
{
	vector<int> completePath;
	completePath.push_back(sG.nodes[sG.nodes.size()-1]->id);
	for(int i=0 i<G.nodes.size())
	{
	//if two nodes in the short path share a neighbor and te neighbors total distance between them is shorter than the dist from node A to B in the short path add it to the vector
	
	}	
	return completePath; 
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

	//TEMP CONSTRUCTION VARIABLES	
	int nodeID;
	int station;
	//GRAPHS
	Graph G;//main graph
	Graph sG;//intermediate graph

	//USER INPUT STARTS HERE
	cin >> n >> m >> c >>i;//input global variables 
	cin >> start >> end; //input start and end points

	//MAIN GRAPH CONSTRUCTION 

	for(int v=0; v<n; v++)//construct the graph and give select nodes chargers
	{ 
		cin >> nodeID >> station; 
		Node* x= new Node(v); //create new node 
		G.nodes.push_back(x); 
		G.nodes[v]->id=v; 
		if(station==1) { G.nodes[v]->charger=true; } //check whether node has charging station or not


	} 

	G.createMatrix(n); 

	for(int v=0; v<m; v++)//create edges between select nodes
	{
		int x=-1, y=-1, dist=-1; 
		cin >> x>> y >> dist; //values being input are the nodes' indexes 

		//add new nodes to neighboring vectors
		G.nodes[x]->neighbors.push_back(G.nodes[y]); 
		G.nodes[y]->neighbors.push_back(G.nodes[x]);//each nodes vector of neighbors is being pushed back

		//create new edges to be added to each nodes edge vector; 
		G.edgeWeights[x][y]=dist; 
		G.edgeWeights[y][x]=dist; 	
	}
	//USER INPUTS END HERE

	//INTERMEDIATE GRAPH CONSTRUCTION
	for(int v=0; v<G.nodes.size(); v++)
	{
		if(G.nodes[v]->charger==true || G.nodes[v]->id==start || G.nodes[v]->id==end)
		{
			Node* x= new Node(G.nodes[v]->id); 
			if(G.nodes[v]->charger==true) { x->charger=true; }
			sG.nodes.push_back(x);

		}//only add the start, end and charging nodes to this simplified graph
	}

	sG.createMatrix(sG.nodes.size());//create an adjaceny matrix for the smaller graph

	for(int v=0; v<sG.nodes.size(); v++)//create neighbor and edge vectors for the smaller graph 
	{
		Node* currNode= sG.nodes[v];  
	G.Djikstra(currNode->id);//find all distances to the nodes in the smaller graph by running djikstra's from select nodes in the main graph


		for(int j=0; j<sG.nodes.size(); j++)
		{
			Node* newNeighbor= sG.nodes[j];
			newNeighbor->dist=G.nodes[newNeighbor->id]->dist; 

				if(newNeighbor->dist <= i && newNeighbor != currNode)//if the distance to a charging station is less than max charge add the edge to the graph;
				{
				//	cout <<"the distance being added between "<<currNode->id<<" and "<< newNeighbor->id<<" is "<< newNeighbor->dist<<endl; 
					sG.nodes[v]->neighbors.push_back(sG.nodes[j]);
					sG.edgeWeights[v][j]=newNeighbor->dist; 
					sG.edgeWeights[j][v]=newNeighbor->dist; 
				}

			

		}	

	}//Add the neighbors to the simpified graph 
	
	//run Djikstras from back to get total distance of trip
	sG.Djikstra(sG.nodes.size()-1); 
	G.Djikstra(0); 
 



	int totalDistance= sG.nodes[0]->dist; 
	cout <<totalDistance<<": ";
	vector<int> path= stations(sG, start, end); 
	vector<int> completePath= route(G, sG, path); 

	//BEGIN OUTPUT

	for(int v=0; v< path.size(); v++)
	{
	cout << path[v]<<" ";
	}	

	cout <<endl; 
	//begin printing here
	return 0;
}
