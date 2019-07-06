#include<iostream> 
#include<climits> 
using namespace std; 
#include "heap.h"

int main() 
{ 
    MaxHeap h(11); 
    h.insert(41);   
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45);
    h.insert(41); 
    // cout << h.deleteMax() << " "; 
    // cout << h.getMax() << " ";  
    // cout << h.getMax();
    h.printHeap();
    return 0; 
} 