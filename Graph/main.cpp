

#include "Graph.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int source = 1;
	int destination = 45;

	int nodes = 50;
	int density = 40;

	Graph graph(density, nodes);

	vector<Edge> ShortestPath = graph.ShortestPath(source, destination);
	double lowestcost         = graph.ShortestPathCost(source, destination);

	for(unsigned int i = 0; i < ShortestPath.size(); i++)
	{
		cout << "Src: " << ShortestPath[i].source << " Dest: " << ShortestPath[i].destination << endl;
	}
	cout << "Start: " << destination << " FinalDest: " << destination << " Cost: "<< lowestcost << endl;

	return 0;
}
