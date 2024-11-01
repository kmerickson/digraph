/* 
This breadth first search class is designed to be used with
graph.h where the number of vertices is predetermined. The graph
size is given with the declaration of the class object as an argument.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstdlib>
#include "Q.h"
#include "graph.h"
#include "stack.h"

using namespace std;

class BreadthFirstPaths{
private: 
	vector<bool> marked;
	vector<int> edgeTo; //the index is the vertex to and the indexed int is the vertex from
	vector<int> distTo; //stores the weight of the edge
	BreadthFirstPaths(int Gsize): marked(Gsize, false), edgeTo(Gsize, -1), distTo(Gsize,-1){}
public:
	void bfs(Graph g, int s, bool weighted=false){
		//takes in a graph object and a source vertex
		Queue<int> q;
		q.enQ(s);
		marked[s] = true;
		distTo[s] = 0;

		while(!q.isEmpty()){
			int v = q.deQ();
			for(int w: g.getAdj(v)){
			//g.getAdj returns a vector of adjacent vertices to vertex v
				if(!marked{w}){
					q.enQ(w);
					marked[w] = true;
					edgeTo[w] = v;
					distTo[w] = distTo[v]+1;
				}
			}
		}
	}


	int distTo(int v) const {
		return distTo[v];
	}
	bool isConnected(int v) const {
		return marked[v];
	}
	int* pathTo(int v) const{
		if(isConnected(v)){
			Stack<int> pathStack;
			for(int x=v; x!=-1;x=edgeTo[x]){
				pathStack.push(x);
			}
			int* path = new int[pathStack.size()];
			for(int i=0;i<pathStack.size();i++){
				path[i] = pathStack.pop();
			}
			return path;
		}
		else{
			cout<<"No viable path.\n";
			return nullptr;
		}
		/* the caller might want to use something like this to prevent mem leaks:
		int* path = bfs.pathTo(targetVertex);
		if (path != nullptr) {
    		// Use the path
    		delete[] path;  //free the memory
		} 
		else {
    		cout << "No path found." << endl;
		}*/
	}

};