// A C++ program to demonstrate common Binary Heap Operations 

#include<iostream> 
#include<climits> 
using namespace std; 
#include "heap.h"

// Constructor: Builds a heap from a given array a[] of given size 
MinHeap::MinHeap(int cap) 
{ 
    heap_size = 0; 
    capacity = cap; 
    harr = new int[cap]; 
} 

// Inserts a new key 'k' 
void MinHeap::insert(int k) 
{ 
    if (heap_size == capacity) 
    { 
        cout << "\nOverflow: Could not insert Key (capacity full)\n"; 
        return; 
    }

    // First insert the new key at the end 
    heap_size++; 
    int i = heap_size - 1; 
    harr[i] = k; 
    percolateUp(i);
} 

// Fix the min heap property if it is violated
void MinHeap::percolateUp(int i) 
{ 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    }
}

// Method to remove minimum element (or root) from min heap 
int MinHeap::deleteMin() 
{ 
    if (heap_size <= 0) 
        return INT_MAX; 
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
void MinHeap::percolateDown(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && harr[l] < harr[i]) 
        smallest = l; 
    if (r < heap_size && harr[r] < harr[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(&harr[i], &harr[smallest]); 
        percolateDown(smallest); 
    } 
}

void MinHeap::printHeap()
{
    cout << "\nFull Tree : \n";
    if (heap_size <= 0)
    {
        cout << "No Nodes\n";
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