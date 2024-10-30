#include <iostream>
#include <stdexcept>
using namespace std;

// Struct to represent a node with a item and priority
template <typename T>
struct Node {
    T item;        // The actual item
    int priority;   // The priority of the item

    // Constructor for convenience
    Node(T val = T(), int prio = 0) : item(val), priority(prio) {}

    bool operator<(const Node& other) const {
    // Comparison operator for min-priority queue
        return priority < other.priority;
    }
};

template <typename T>
class PriQ {
private:
    Node<T>* heap;   
    int N;           // Number of elements in the heap
    int capacity;    

    void heapUp(int index) {
    // restore heap property upwards
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapUp(parent);
        }
    }

    void heapDown(int index) {
    // restore heap property downwards
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < N && heap[left] < heap[smallest]) {
        // Find the smallest among the current node and its children
            smallest = left;
        }
        if (right < N && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
        // If the smallest is not the current node, swap and continue heapifying
            swap(heap[index], heap[smallest]);
            heapDown(smallest);
        }
    }

    void resize() {
    // Resize the array to double its capacity
        int newCapacity = 2 * capacity;
        Node<T>* newHeap = new Node<T>[newCapacity];
        for (int i = 0; i < N; ++i) {
            newHeap[i] = heap[i];
        }
        delete[] heap; 
        heap = newHeap;
        capacity = newCapacity;
    }

public:
    PriQ() : N(0), capacity(4) {
        heap = new Node<T>[capacity];  
    }
    ~PriQ() {
        delete[] heap;
    }

    void insert(T item, int priority) {
        if (N == capacity) {
            resize();  // Resize the array if it's full
        }
        heap[N] = Node<T>(item, priority);  // Insert the new element
        heapUp(N);  // Restore heap property
        N++;
    }

    bool isEmpty() const {
        return N == 0;
    }

    T removeMin() {
    // Remove and return the element with the highest priority (smallest priority item)
        if (isEmpty()) {
            throw out_of_range("Priority queue is empty.");
        }
        T minitem = heap[0].item;  // Get the item of the root
        heap[0] = heap[N - 1];  // Replace the root with the last element
        N--;  // Decrease the size of the heap
        heapDown(0);  // Restore heap property
        return minitem;
    }

    T peek() const {
    // Get the element with the highest priority (smallest priority item) without removing it
        if (isEmpty()) {
            throw out_of_range("Priority queue is empty.");
        }
        return heap[0].item;
    }

    int peekPriority() const {
    // Get the priority of the highest priority element
        if (isEmpty()) {
            throw out_of_range("Priority queue is empty.");
        }
        return heap[0].priority;
    }
};


