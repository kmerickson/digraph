#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include "priQueue.h"
#include "stack.h"

using namespace std;

#define INF 2147483647

struct Edge{
	int vertex;
	int weight;
};

class DiGraph{
	private:
		int Gsize;
		vector<vector<Edge>> adj; //adjacency list 
			
	public:
		DiGraph(int Gsize): Gsize(Gsize), adj(Gsize){
		// create empty DiGraph w/ V vertices
			// this code appears to be redundant as vertice(vertice) initializes the number of vertices to be 
			// the value added to the class constructor, and adj(vertice) initializes an empty adjacencty list for each vertex
			/*for(int v=0; v<vertice; v++){
				adj[v] = std::vector<int>();
			}*/
		}
	void addEdge(int vFrom, int vTo, int weight=1){
	// add edge vFrom-vTo (parallel edges and self-loops allowed)
	//default weight set to 1 if no weight provided
		//cout<<"edge added: ";
		//cout<<"vFrom="<<vFrom<<", vTo="<<vTo<<", weight="<<weight<<endl;
		if(vFrom<0 || vFrom>= Gsize || vTo<0 || vTo>= Gsize){
			throw out_of_range("Vertex index out of bounds");
		}	
		if(vFrom==vTo){weight=0;}
		adj[vFrom].push_back({vTo, weight});
		//adj[vTo].push_back(vFrom); //commented out to make this a DiGraph as this line addes the connection to both nodes
	}
	vector<Edge>& getAdj(int v){
	//use a pointer to dereference the address returned
	//iterator for vertices adjacent to v
		return adj[v];
	}
	void printAdj(int v){
		if(v<0 || v>=Gsize){
			cout<<"Vertex index out of range\n";
			return;
		}
		cout<<"vertice "<<v<<" has "<<adj[v].size()<<" adjacent vertices:\n";
		for(const auto& edge : adj[v]){
			cout<< "(vertex: "<< edge.vertex<<", weight: "<<edge.weight<<")\n";
		}
		cout<<"\n";
	}

	void dijkstraSPT(int srcV, int destV){
		PriQ<int> pq; // priority queue that utilizes a heap
		int v; // used to hold next vertex to process
		int weight; // holds the edge weight to next vertex
		int u; // holds current vertex having its neighbors assessed
		int dist[Gsize]; //array to store distances 
		int parent[Gsize]; //parent array used to reconstruct the path
		for(int i=0; i<Gsize; i++){
			dist[i] = INF;	// initialize all distances to INF
			parent[i] = -1; //if -1, not a parent
		}
		// place source vertex on the pri queue
		pq.insert(srcV, 0); // first argument is the vertice, second is the weight
		dist[srcV] = 0;
		
		while(!pq.isEmpty()){
			u = pq.removeMin(); //remove smallest edged vertex

			for(auto& neighbor : adj[u]){//go through all adj vertices of u
				v = neighbor.vertex;
				weight = neighbor.weight;
				if(dist[v] > dist[u] + weight){//if shorter path is found
				//get new dist and push on pri queue
					dist[v] = dist[u] + weight;
					parent[v] = u;	//update parent of v
					pq.insert(v, dist[v]);
				}

			}
		}
		//prints the distance to each vertex
		//cout<<"Distance from source vertex to destination vertex:\n";
		//for(int i=0; i<Gsize;++i)
		//	cout<<i<<" \t\t"<<dist[i]<<endl;
		Stack<int> pathStack;
		for (int v = destV; v!=-1; v=parent[v])
			pathStack.push(v);

		cout<<"From "<<srcV<<" to "<<destV<<" is:\n";
		cout<<"Path weight is "<<dist[destV]<<endl;
		//display path:
		while(!pathStack.isEmpty()){
			cout<<pathStack.pop();
			if(!pathStack.isEmpty()){cout<<"->";}
		}
		cout<<endl<<endl;
	}
	~DiGraph(){
		cout<<"DiGraph dynamically allocated memory deleted.\n";
		cout<<"Program terminated.\n";
	}
};