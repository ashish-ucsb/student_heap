// A C++ program to demonstrate common Binary Heap Operations 

#include<iostream> 
#include<climits>
#include<vector>
using namespace std; 
#include "heap.h"

// Constructor: Builds a heap from a given array a[] of given size 
MaxHeap::MaxHeap(vector<int> v) 
{ 
    heap_size = v.size();
    harr = new int[heap_size];
    copy(v.begin(), v.end(), harr);
}

void MaxHeap::buildHeap()
{
    for (int it = heap_size/2; it >= 0; it--)
    {
        percolateDown(it);
    }
}  

// Fix the min heap property if it is violated
void MaxHeap::percolateUp(int i) 
{ 
    while (i != 0 && harr[parent(i)] < harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    }
}

// Method to remove minimum element (or root) from min heap 
int MaxHeap::deleteMax() 
{ 
    if (heap_size <= 0) 
        return INT_MIN; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return harr[0]; 
    } 
  
    // Store the minimum value, and remove it from heap 
    int root = harr[0]; 
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    percolateDown(0); 
  
    return root; 
}

  
// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified
// PERCOLATE DOWN
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