#include<iostream> 
#include<climits> 
using namespace std; 
#include "heap.h"

int main() 
{ 
    MinHeap h(11); 
    h.insert(3); 
    h.insert(2);  
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45); 
    cout << h.deleteMin() << " "; 
    cout << h.getMin() << " ";  
    cout << h.getMin();
    h.printHeap();
    return 0; 
} 