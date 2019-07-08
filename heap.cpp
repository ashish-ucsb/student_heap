#include<iostream> 
#include<climits>
#include<vector>
using namespace std; 
#include "heap.h"

// Constructor: takes a int vector to build a max heap from
MaxHeap::MaxHeap(std::vector<int> v) 
{ 
    heap_size = v.size();
    harr = new int[heap_size];
    copy(v.begin(), v.end(), harr);
}

// builds a max heap from a given vector (turned to array)
void MaxHeap::buildHeap()
{
    for (int it = heap_size/2; it >= 0; it--)
    {
        percolateDown(it);
    }
}  

// Fix the max heap property if it is violated
void MaxHeap::percolateUp(int i) 
{ 
    while (i != 0 && harr[parent(i)] < harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    }
}

// Method to delete maximum element (or root) from max heap 
int MaxHeap::deleteMax() 
{ 
    if (heap_size <= 0) 
        return INT_MIN; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return harr[0]; 
    } 
  
    // Store the maximum value, and remove it from heap 
    int root = harr[0]; 
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    percolateDown(0); 
  
    return root; 
}

  
// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified
void MaxHeap::percolateDown(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int largest = i; 
    if (l < heap_size && harr[l] > harr[i]) 
        largest = l; 
    if (r < heap_size && harr[r] > harr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(&harr[i], &harr[largest]); 
        percolateDown(largest); 
    } 
}

// Prints the Heap
void MaxHeap::printHeap()
{
    cout << "\nFull Tree : \n";
    if (heap_size <= 0)
    {
        cout << "Empty Tree\n";
    }
    if (heap_size > 0)
    {
        for (int i=0; i<heap_size; i++)
        {
            cout << harr[i] << " ";
        }
        cout << endl;
    }
}

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 