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
using std::vector;
using std::multiset;


class Graph {

private :
	void AddtoOpenList(multiset<Node>& OpenList, Node node, double currentcost);

public	:
	Graph(int density, int size);
	virtual ~Graph();

	vector<Node>  vertices;  //vector of nodes

	vector<Edge> ShortestPath(int source, int destination);  //Returns a vector of edges = the shortest path
	double ShortestPathCost(int source, int destination);	 //returns total cost of the shortest path

	void PrintVertices();
	void PrintNeighbors(int node);
	void PrintNeighborsWeight(int node);
};


#endif /* GRAPH_H_ */
