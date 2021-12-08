// CSCI 311 - Fall 2021
// Node Class
// Author: Carter Tillquist

#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include "Edge.h"
using namespace std;

class Node{
  public:
    int id;
    int dist;
    int discovered;
    int finished;
    bool visited;
    bool charger; 
    Node* predecessor;
  vector<Node*> neighbors; 
    vector<Edge*> edges;
    
    Node();
    Node(int);
};

#endif
