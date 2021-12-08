#include <iostream>
#include <vector>
#include "pQ.h"
#include "Node.h"

using namespace std;

pQ::pQ()
{

}//constructor

bool pQ::empty()
{
	if(heap.size()==0)
	{
	return true; 
	}
	
	return false;
}//function to check if queue is empty

int pQ::size()
{
	return heap.size(); 
}

void pQ::heapify(int s)
{
	int left = (s*2)+1;
	int right = (s*2)+2;
	int parent =(s-1)/2;
	int min=s; 
	int size= heap.size(); 

	if(heap[parent] != heap[s] && heap[parent]->dist > heap[s]->dist)
	{
		Node* tempNode= heap[s];
		heap[s]= heap[parent];
		heap[parent]= tempNode; 
		heapify(parent); 
	}

	if(left <= size && heap[left]->dist < heap[s]->dist)  { min=left;  }
	if(right <= size && heap[right]->dist <heap[s]->dist) { min=right; }

	if(min!=s)
	{
		Node* tempNode= heap[s];
		heap[s]= heap[min];
		heap[min]= tempNode; 
		heapify(min); 
	}
}
void pQ::push(Node* N)
{
	heap.push_back(N); 
	int currSize=heap.size()-1; 
	int parentIndex= (currSize-1)/2;

	while(currSize >0 && heap[parentIndex]->dist > heap[currSize]->dist)
	{
		Node* temp= heap[currSize];
		heap[currSize]= heap[parentIndex];
		heap[parentIndex]= temp;

		currSize=parentIndex; 
		parentIndex = (currSize-1)/2;
	}

}

Node* pQ::pop()
{
	Node* top = heap[0];
	heap[0]=heap[heap.size()-1];//make the farthest node in the heap the new root
	heap.pop_back(); 
	heapify(0); 
	return top; 
}
