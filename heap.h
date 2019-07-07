#ifndef HEAP_H
#define HEAP_H


// A class for Min Heap
class MaxHeap 
{ 
    int *harr; // pointer to array of elements in heap 
    // int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap

public: 

    MaxHeap(vector<int> v); // Constructor 
    int parent(int i) { return (i-1)/2; } 
    int left(int i) { return (2*i + 1); } // to get index of left child of node at index i 
    int right(int i) { return (2*i + 2); } // to get index of right child of node at index i
    int getMax() { return harr[0]; }  // Returns the minimum key (key at root) from min heap
    
    void buildHeap(); // Inserts a new key 'k'
    void percolateDown(int i); // to heapify a subtree with the root at given index
    int deleteMax(); // Delete the root which is the minimum element   
    void percolateUp(int i); // Fix the min heap property if it is violated   
    void printHeap(); // Prints the Heap
}; 

// Prototype of a utility function to swap two integers 
void swap(int *x, int *y);

#endif