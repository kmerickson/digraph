#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

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
		if(vFrom<0 || vFrom>= Gsize || vTo<0 || vTo>= Gsize){
			throw out_of_range("Vertex index out of bounds");
		}	
		adj[vFrom].push_back({vTo, weight});
		//adj[vTo].push_back(vFrom); //commented out to make this a diDiGraph as this line addes the connection to both nodes
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


	~DiGraph(){
		cout<<"DiGraph dynamically allocated memory deleted.\n";
		cout<<"Program terminated.";
	}
};