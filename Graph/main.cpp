
#include "Graph.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int source = 0;
	int destination = 35;
	int upperbound = 10;
	int lowerbound = 1;

	int nodes = 50;
	int density20 = 20;
	int density40 = 40;

	Graph graph20(density20, nodes, lowerbound, upperbound);
	Graph graph40(density40, nodes, lowerbound, upperbound);
	vector<Edge> ShortestPath = graph20.ShortestPath(source, destination);
	for(unsigned int i = 0; i < ShortestPath.size(); i++)
	{
		cout << "Src: " << ShortestPath[i].source << " Dest: " << ShortestPath[i].destination << " Cost:" << ShortestPath[i].cost << endl;
	}

	cout << "Density 20 graph" << endl;
	for(int i = 1; i < nodes;i++)
	{
		destination = i;
		double lowestcost         = graph20.ShortestPathCost(source, destination);
		cout << "Start: " << source << " FinalDest: " << destination << " Cost: "<< lowestcost << endl;
	}

	cout << "Density 40 graph" << endl;
	for(int i = 1; i < nodes;i++)
	{
		destination = i;
		double lowestcost         = graph40.ShortestPathCost(source, destination);
		cout << "Start: " << source << " FinalDest: " << destination << " Cost: "<< lowestcost << endl;
	}

	return 0;
}
