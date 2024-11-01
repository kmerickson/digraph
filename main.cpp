/*
This main function is designed to read in input text  file 
storing vertex connection data for a graph in the format of:
first line = text designating next line is the number of vertices
second line = number of vertices
third lines = format of data for vertex connections
fourth and on = source vertex, destination vertex, edge weight
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include "digraph.h"

using namespace std;

typedef std::chrono::steady_clock Time; // Makes is to where we don't have to type entire library every time.

void logEvent(std::string);
std::string buildString(int, int, std::chrono::_V2::high_resolution_clock::duration);

int main(int argc, char* argv[]){
	auto progTimeStart = Time::now();
    std::string printString ="Run started";
    logEvent(printString);

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
	getline(file, line); // grabs the number of vertices in graph
	//cout<<line<<endl;
	Gsize = stoi(line); // get the graph size integer 
	getline(file, line); // throw away 3rd line

	DiGraph dg(Gsize); // create graph object

	while(!file.eof()){
		//using getline: (Having a hard time getting this to work)
		// the first character of each line after the first is not being read
		//getline(file, word, ' ');
		//vFrom = stoi(word);
		//getline(file, word, ' ');
		//vTo = stoi(word);
		//getline(file, word, ' ');
		//edgeWeight = stoi(word);
		//getline(file,line);

		////using sstream:
		getline(file, line);
		istringstream iss(line);
		iss>>vFrom>>vTo>>edgeWeight;

		dg.addEdge(vFrom, vTo, edgeWeight); // add connections in graph
	}
	file.close();
	string GsizeS = to_string(Gsize);
    printString = "Graph with " + GsizeS;
    printString = printString + " vertices created.";
    logEvent(printString);


	int input, v1,v2,v3, destV;
	cout<<"Enter a negative integer to close the program.\n";
	while(true){ // terminal interface loop
		cout<<"Provide 3 source vertices: ";
		
		cin>>v1;
		if(v1<0) break;
		cin>>v2;
		if(v2<0) break;
		cin>>v3;
		if(v3<0) break;
		
		cout<<"\nDestination 1?: ";
		cin>>destV;
		if(destV<0) break;
		
		cout<<"Shortest path 1 from "<<v1<<": ";   

        auto timeStart = Time::now();
		dg.dijkstraSPT(v1, destV);
        auto timeStop = Time::now();
        auto duration = Time::duration(timeStop - timeStart);
        printString = buildString(v1, destV, duration);
        logEvent(printString);

		cout<<"Shortest path 2 from "<<v2<<": ";
        timeStart = Time::now();
		dg.dijkstraSPT(v2, destV);
        timeStop = Time::now();
        duration = Time::duration(timeStop - timeStart);
        printString = buildString(v2, destV, duration);
        logEvent(printString);

		cout<<"Shortest path 3 from "<<v3<<": ";
        timeStart = Time::now();
		dg.dijkstraSPT(v3, destV);
        timeStop = Time::now();
        duration = Time::duration(timeStop - timeStart);
        printString = buildString(v3, destV, duration);
        logEvent(printString);

		
		cout<<"\nDestination 2?: ";
		cin>>destV;
		if(destV<0) break;
		
        timeStart = Time::now();
		dg.dijkstraSPT(v1, destV);
        timeStop = Time::now();
        duration = Time::duration(timeStop - timeStart);
        printString = buildString(v1, destV, duration);
        logEvent(printString);

		cout<<"Shortest path 2 from "<<v2<<": ";
        timeStart = Time::now();
		dg.dijkstraSPT(v2, destV);
        timeStop = Time::now();
        duration = Time::duration(timeStop - timeStart);
        printString = buildString(v2, destV, duration);
        logEvent(printString);

		cout<<"Shortest path 3 from "<<v3<<": ";
        timeStart = Time::now();
		dg.dijkstraSPT(v3, destV);
        timeStop = Time::now();
        duration = Time::duration(timeStop - timeStart);
        printString = buildString(v3, destV, duration);
        logEvent(printString);

		cout<<"\nDestination 3?: ";
		cin>>destV;
		if(destV<0) break;
		
        timeStart = Time::now();
		dg.dijkstraSPT(v1, destV);
        timeStop = Time::now();
        duration = Time::duration(timeStop - timeStart);
        printString = buildString(v1, destV, duration);
        logEvent(printString);

		cout<<"Shortest path 2 from "<<v2<<": ";
        timeStart = Time::now();
		dg.dijkstraSPT(v2, destV);
        timeStop = Time::now();
        duration = Time::duration(timeStop - timeStart);
        printString = buildString(v2, destV, duration);
        logEvent(printString);

		cout<<"Shortest path 3 from "<<v3<<": ";
        timeStart = Time::now();
		dg.dijkstraSPT(v3, destV);
        timeStop = Time::now();
        duration = Time::duration(timeStop - timeStart);
        printString = buildString(v3, destV, duration);
        logEvent(printString);
	}
	auto progTimeStop = Time::now();
	auto duration = Time::duration(progTimeStop - progTimeStart);
    printString ="Run ended, total run time was " + to_string(duration.count()) + " ns.";
    logEvent(printString);
	return 0;
}

// Function logs the current Date/Time and prints passed string afterwards.
void logEvent(std::string passedString)
{
    std::ofstream logStream;
    logStream.open("log.txt", std::ios::app);
    if (!logStream.is_open())
    {
        std::cerr << "Log stream failed to open, aborting." << std::endl;
        return;
    }

    // Getting the current time from Chrono Library.
    auto now = std::chrono::system_clock::now();

    // Casting "now" to time_t type.
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // Converting "now_time_t" to a tm struct.
    std::tm now_tm = *std::localtime(&now_time_t);

    logStream << "[" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << "]";
    logStream << " " << passedString << endl;
    logStream.close();
}

// Function builds the log file string.
std::string buildString(int sourceV, int destV, std::chrono::_V2::high_resolution_clock::duration duration)
{
	string sourceVstr = to_string(sourceV);
	string destVstr = to_string(destV);


    std::string returnString = "BFS between vertex " + sourceVstr;
    std::string tempString = " and vertex " + destVstr;
    returnString = returnString + tempString;

    tempString = " performed in " + to_string(duration.count());
    returnString = returnString + tempString;

    tempString = " ns.";
    returnString = returnString + tempString;

    return returnString;
}