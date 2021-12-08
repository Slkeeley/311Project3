#ifndef PQ_H
#define PQ_H
#include <vector> 
#include "Node.h"

using namespace std; 
class pQ{
	public: 
	pQ();
       	vector<Node*> heap; 	
	bool empty(); 
	int size(); 
	void heapify(int s);
	void push(Node* N); 
	Node* pop(); 

};


#endif 
