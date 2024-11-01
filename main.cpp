/*
This main function is designed to read in input text  file 
storing vertex connection data for a graph in the format of:
first line = text designating next line is the number of vertices
second line = number of vertices
third lines = format of data for vertex connections
fourth and on = source vertex, destination vertex, edge weight
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "digraph.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc<2){
		std::cerr<<"Error: Missing filename as main function arg.\n";
		return 1;
	}

	string filename = argv[1];
	ifstream file(filename);
	if(!file.is_open()){
		cerr<<"Error: File named "<<filename<<" could not be opened.\n";
		return 1;
	}
	string word, line;
	int vTo, vFrom, edgeWeight, Gsize; // destination vertex, source vertex, edge weight, graph size

	getline(file, line); //throw away first line of input text
	getline(file, line);
	cout<<line<<endl;
	Gsize = stoi(line); // get the graph size integer 
	getline(file, line); // throw away 3rd line

	DiGraph dg(Gsize); // create graph op

	while(!file.eof()){
		//using getline:
		//getline(file, word, ' ');
		//vFrom = stoi(word);
		//getline(file, word, ' ');
		//vTo = stoi(word);
		//getline(file, word, ' ');
		//edgeWeight = stoi(word);

		//using sstream:
		getline(file, line);
		istringstream iss(line);
		iss>>vFrom>>vTo>>edgeWeight;

		//cout<<"vFrom: "<<vFrom<<endl;
		//cout<<"vTo: "<<vTo<<endl;
		//cout<<"weight: "<<edgeWeight<<endl;
		//cout<<endl;
		dg.addEdge(vFrom, vTo, edgeWeight); // add connections in graph
	}
	file.close();

	dg.dijkstraSPT(7, 32);
	dg.dijkstraSPT(19, 32);
	dg.dijkstraSPT(26, 32);

	dg.dijkstraSPT(7, 22);
	dg.dijkstraSPT(19, 22);
	dg.dijkstraSPT(26, 22);

	dg.dijkstraSPT(7, 3);
	dg.dijkstraSPT(19, 3);
	dg.dijkstraSPT(26, 3);

	


	
	
	
	//DiGraph dg2(10);
	//dg.addEdge(0, 1);
	//dg.addEdge(0,3);
	//dg.addEdge(0,5);
	//dg.addEdge(0,15);

	//dg.printAdj(0);
	//dg.printAdj(7);
	//dg.printAdj(1);
	//dg.printAdj(3);
	//dg.printAdj(22);
	//dg.printAdj(17);
	//dg.printAdj(14);
	//dg.printAdj(19);
	//dg.printAdj(20);
	//dg.printAdj(31);
	//dg.printAdj(32);

	//DiGraph dg2(33);
	//dg2.addEdge(0, 8, 3);
	//dg2.addEdge(8, 12, 11);
	//dg2.addEdge(12, 10, 11);
	//dg2.addEdge(0, 12, 100);
	//dg2.dijkstraSPT(0,12);
	//dg2.printAdj(0);
	//dg2.printAdj(8);
	//dg2.printAdj(12);


	return 0;
}
