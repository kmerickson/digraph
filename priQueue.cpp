#include "priQueue.h"
#include <string>
#include <iostream>

int main() {
    PriQ<string> pq;  // Create a priority queue for strings

    // Insert elements with different priorities
    pq.insert("Task A", 3);
    pq.insert("Task B", 1);
    pq.insert("Task C", 2);

    // Display the element with the highest priority
    cout << "Element with highest priority: " << pq.peek() 
         << " (Priority: " << pq.peekPriority() << ")" << endl;

    // Remove and display the element with the highest priority
    cout << "Removed element: " << pq.removeMin() << endl;

    // Display the next element with the highest priority
    cout << "Next element with highest priority: " << pq.peek() 
         << " (Priority: " << pq.peekPriority() << ")" << endl;

    // Check if the priority queue is empty
    cout << "Is the priority queue empty? " 
         << (pq.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}