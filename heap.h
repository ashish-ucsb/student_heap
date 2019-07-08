#ifndef HEAP_H
#define HEAP_H
using namespace std;

// Prototype of a utility function to swap two integers 
void swap(int *x, int *y);

// A class for max Heap
class MaxHeap 
{ 
    int *harr; // pointer to array of elements in heap  
    int heap_size; // Current number of elements in max heap

public: 

    MaxHeap(vector<int> v); // Constructor (converts vector to an array)
    int parent(int i) { return (i-1)/2; } // to get index of parent of node at index i
    int left(int i) { return (2*i + 1); } // to get index of left child of node at index i 
    int right(int i) { return (2*i + 2); } // to get index of right child of node at index i
    int getMax() { return harr[0]; }  // Returns the Maximum key (key at root) from max heap
    void buildHeap(); // Builds heap from a given array
    void percolateDown(int i);
    int deleteMax(); // Delete the root which is the maximum element   
    void percolateUp(int i); 
    void printHeap(); // Prints the Heap
}; 

#endif