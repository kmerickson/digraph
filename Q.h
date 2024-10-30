#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

template <typename T> class Queue{
private:
	T* q;
	int N;
	int capacity;
	int head;
	int tail;
public:
	Queue():capacity(4){
		cout<<"Queue class created"<<endl;
		q= new T[capacity];
		N = 0; //size tracking variable 
		head = 0; //head position tracking variable 
		tail = -1; // tail position tracking variable
	}
	void enQ(T item){
		
		tail++;
		N++;
		cout<<"Queued item: "<<item<<endl;
		if(N==capacity){ // double cap if not enough room
			resize(2*capacity);
			cout<<"capacity is: "<<capacity<<endl;
		}
		
		q[tail] = item; //place new item at tail
		cout<<"item at tail: "<<q[tail]<<endl;
		cout<<"tail is: "<<tail<<endl;
	}
	bool isEmpty(){
		// checks to see if the queue is empty
		return N==0;
	}
	void showHead(){
		if(isEmpty()){
			std::cout<<"Queue is empty, no head to show.\n";
		}
		else{
			cout<<"head item is: "<<q[head]<<endl;
		}
	}
	int size()const{
		return N;
	}
	T deQ(){
		if(isEmpty()){
			cout<<"Queue underflow, cannot dequeue.\n";
			return "";
		}
		T returnItem = q[head];
		head++;
		if(head > tail){
			head = 0;
			tail = -1;
		}
		N--; 
		cout<<"tail is now at: "<<tail<<endl;
		cout<<"dequeued: "<<returnItem<<endl;
		return returnItem;		
	}
	void showQ(){
		cout<<"Queue contents:\n";
		for(int i = head; i<=tail; i++){
			cout<<"'"<<q[i]<<"', ";
		}
		cout<<endl;
	}
private:
	void resize(int newCapacity){
		//creates an array of twice the size and copies items over
		T* copy = new T[newCapacity];
		cout<<"resizing array.\n";
		for(int i = 0; i<N; i++){
			copy[i] = q[head+i];
		}
		delete[] q;
		q = copy;
		capacity = newCapacity;
		//reset head and tail positions
		head = 0;
		tail = size-1;
	}
	~Queue(){
		delete q[];
	}
};