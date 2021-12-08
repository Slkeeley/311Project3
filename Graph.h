// CSCI 311 - Fall 2021
// Graph class header
// Author: Carter Tillquist

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include "Node.h"
#include "Edge.h" 

class Graph{
  public:
    vector<Node*> nodes;
    vector<vector<int>> edgeWeights;  //use this for holding edge distances 
    Graph();

    void createMatrix(int totalNodes); 
    void printAdjList();
    bool isNeighbor(int, int);
    void DFS();
    int DFSVisit(int, int);
    void BFS(int);
    std::vector<int> distancesFrom(int);
    void Djikstra(int s); 
    bool isConnected();
    bool isReachable(int, int);
};

#endif
