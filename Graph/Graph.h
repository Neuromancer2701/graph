/*
 * Graph.h
 *
 *  Created on: Oct 25, 2013
 *      Author: SK1033
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "Node.h"
#include <vector>
#include <set>
#include <string>
using std::vector;
using std::multiset;
using std::string;

class Graph {

private :
	void AddtoOpenList(multiset<Node>& OpenList, vector<Node>& ClosedList, Node node, double currentcost);

public	:
	Graph(int density, int size, int lowerBound, int upperBound);
	Graph(string Path);
	virtual ~Graph();

	vector<Node>  vertices;  //vector of nodes

	vector<Edge> ShortestPath(int source, int destination);  //Returns a vector of edges = the shortest path
	double ShortestPathCost(int source, int destination);	 //returns total cost of the shortest path

	vector<Edge> PrimMST(int start); //returns a vector of MST
	double PrimMSTCost(int start);	//returns the cost of the MST

	void PrintVertices();
	void PrintNeighbors(int node);
	void PrintNeighborsWeight(int node);
};


#endif /* GRAPH_H_ */
