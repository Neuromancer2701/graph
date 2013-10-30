

#include "Graph.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int source = 1;
	int destination = 35;

	int nodes = 100;
	int density = 10;

	Graph graph(density, nodes);

	vector<Edge> ShortestPath = graph.ShortestPath(source, destination);
	double lowestcost         = graph.ShortestPathCost(source, destination);

	cout << "Total Steps to destination: " <<  ShortestPath.size() << endl;
	for(unsigned int i = 0; i < ShortestPath.size(); i++)
	{
		cout << "Src: " << ShortestPath[i].source << " Dest: " << ShortestPath[i].destination << " Cost:" << ShortestPath[i].cost << endl;
	}
	cout << "Start: " << source << " FinalDest: " << destination << " Cost: "<< lowestcost << endl;

	return 0;
}
