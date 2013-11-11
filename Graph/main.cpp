
#include "Graph.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	string path("data.txt");
	Graph graph(path);


	vector<Edge> MST = graph.PrimMST(0);

	for( Edge edge: MST)
	{
		cout << "Start: " << edge.source << " FinalDest: " << edge.destination << " Cost: "<< edge.cost<< endl;
	}

	double cost = graph.PrimMSTCost(0);
	cout << "Cost of Prim MST:" << cost << endl;




	return 0;
}
