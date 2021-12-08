// CSCI 311 - Fall 2021
// Graph class cpp
// Author: Carter Tillquist

#include <iostream>
#include "Graph.h"
#include "Node.h"
#include "pQ.h"
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

Graph::Graph(){
	nodes={}; 
	edgeWeights ={}; 
}//initialize graph constructor

void Graph::Djikstra(int s)
{
	for(int v=0; v< nodes.size(); v++)
	{
		nodes[v]->dist=INT_MAX;
		nodes[v]->predecessor=nullptr;
		
	}//set all distances to infinity
	

	nodes[s]->dist=0;//the distance to our starting node is 0; 
	pQ minHeap;//create a queue of nodes
	
	for(int v=0; v<nodes.size(); v++)
	{
	minHeap.push(nodes[v]); 

	}

	minHeap.heapify(0); 
	while(!minHeap.empty())
	{
		Node* currNode= minHeap.pop();//take current top of the queue and use to find distances
		cout << currNode->id<<endl;

		for(int v=0; v<currNode->neighbors.size(); v++)//for loop to go through all neighbors of the current node 
		{
			Node* neighbor=currNode->neighbors[v];
		     
			if(neighbor->dist >(currNode->dist + edgeWeights[currNode->id][neighbor->id]))
			{
	 
				neighbor->dist =(currNode->dist +edgeWeights[currNode->id][neighbor->id]); 
				neighbor->predecessor=currNode; 
				minHeap.heapify(neighbor->id);  
			}//change the distance and predecessor if shorter distance is found
		}
	}//while queue is not empty keep the algorithm going 
}

void Graph::createMatrix(int totalNodes)
{
	vector<int> across(totalNodes, -1); 
	vector<vector<int>> down(totalNodes, across);
	edgeWeights=down; 
}

void Graph::printAdjList(){
	for(int i=0; i< nodes.size(); i++)
	{
		cout<< nodes[i]->id<<": ";
		for(int v=0; v<nodes[i]->neighbors.size();v++)
		{
				cout<< nodes[i]->neighbors[v]->id<<" ";
		}
		cout << endl;
	}
}//print all nodes and what they are adjacent two

bool Graph::isNeighbor(int u, int v){
	if(u==v) {return false;}// node cannot be its own neighbor
	int s; 
	for(int i=0; i<nodes.size(); i++)
	{
		if(nodes[i]->id==u)
		{
			s=i; 
			break;
		}

	}

	for(int i=0; i< nodes[s]->neighbors.size(); i++)
	{
		if(nodes[s]->neighbors[i]->id==v)
		{
			return true;
		}

	}//only checking if two nodes are neighbors, if it is found v is a neighbor return true; 
	
	return false;
}

void Graph::DFS(){
	for(int i=0; i<nodes.size(); i++)
	{	
		nodes[i]->visited=false;
		nodes[i]->predecessor=NULL;
		nodes[i]->discovered=-1;
		nodes[i]->finished=-1;
	}//initialize every node to these values before searching
	int time=0;
	for(int i=0; i<nodes.size(); i++)
	{
		if(nodes[i]->visited=false)
		{
			time=DFSVisit(nodes[i]->id, time); 
		}//begin recursive DFS
	}
}//start time for DFS

int Graph::DFSVisit(int s, int time){
	time = time+1;
	nodes[s]->discovered=time;
	nodes[s]->visited=true;
	for(int v=0; v<nodes.size(); v++)
	{
		if(nodes[v]->visited==false) 
		{
			time=DFSVisit(nodes[v]->id, time); 
		}//if the search can still move farther keep calling DFS

	}
	time=time+1; 
	nodes[s]->finished=time; 
	return time;
}//recusrive DFS returns time when a node has no unvisited neighbors

void Graph::BFS(int s){
	for(int i=0; i<nodes.size(); i++)
	{
		nodes[i]->dist =INT_MAX;
		nodes[i]->visited=false;
		nodes[i]->predecessor=NULL;
	}//set all distances to infinity and all nodes to be unvisited
	nodes[s]->dist=0; 
	nodes[s]->visited=true;
	queue<int> Q;
	Q.push(s); //push our source node onto the queue

	while(!Q.empty())
	{
		s=Q.front();
		Q.pop(); 	
		int d=1;
		for(int i=0;i< nodes[s]->neighbors.size(); i++)
		{
			if(nodes[i]->visited==false)
			{
				nodes[i]->visited=true;
				nodes[i]->dist=d;
				Q.push(nodes[i]->id); 
			}//if neighboring node is unvisited add it to the queue

		}
		d++;

	}//while unvisited nodes are still being added to the queue keep doing BFS


}

vector<int> Graph::distancesFrom(int s){
	vector<int> distances;
	BFS(s);//run a BFS on our source node to get the distances from S
	for(int i=0; i< nodes.size(); i++)
	{
		distances.push_back(nodes[i]->dist);
	}//push those distances onto a vector and return it
	return distances;
}


bool Graph::isConnected(){
	for(int i=0; i<nodes.size(); i++)
	{
		for(int v=0; v<nodes.size(); v++)
		{
			if(isReachable(nodes[i]->id, nodes[v]->id)==false)
			{
				return false; 
			}//if there is not a path between two nodes the graph is not connected

		}
	}
	return true;
}//function to find if graph is connected by finding paths between two nodes

bool Graph::isReachable(int u, int v){
	if(u==v) {return true;} //base case, if they are the same node then both u and v are reachable from each other
	for(int i=0; i<nodes.size(); i++)
	{
		nodes[i]->visited=false;
	}//reset all nodes to be unvisited before we search

	queue <int> Q; 
	nodes[u]->visited=true; 
	Q.push(u);
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop(); 
		for(int i=0; i<nodes[u]->neighbors.size(); i++)
		{
			if(nodes[u]->neighbors[i]->id==v)
			{
				return true; 
			}//return true if there exists a path from U to V

			if(nodes[u]->neighbors[i]->visited==false)
			{
				nodes[u]->neighbors[i]->visited=true;
				Q.push(nodes[u]->neighbors[i]->id); 
			}// if the neighboring node was just visited push it onto the queue so its neighbors can be checked
		}

	}
	return false;
}//find if path exists between two nodes
