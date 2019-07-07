#include<iostream> 
#include<climits>
#include<vector>
using namespace std; 
#include "heap.h"

int main() 
{ 
    vector<int> v;

    for(int i=0; i<10; i++)
    {
       v.push_back(i);
    }

    MaxHeap h(v); 
    h.buildHeap();

    
    h.printHeap();
    return 0; 
} 