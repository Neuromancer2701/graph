/*
 * Graph.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: SK1033
 */

#include "Graph.h"
#include <vector>
#include <set>
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;
using std::multiset;

// Density valid range 1-100;
// Size valid positive integer
Graph::Graph(int density, int size) {
	Node n;
	srand (time(NULL));
	for(int i = 0; i < size; i++ )
	{
		n.name = i;
		vertices.push_back(n);
	}


	for(int i = 0; i < size; i++)			// move though every node in graph
	{
		for(int j = i + 1; j < size; j++)		// only need to calculate the node combinations that are left
		{									//e.g. Node 1 is calculated for the whole graph so when Node 2 is calculated we can skip Node 1
			if( rand() % 100 < density)
			{
				double weight = (double)((rand() % 90) + 10)/10.0;	//calculate a random edge value between 1.0 and 10.0
				Edge edge;
				edge.source = i;
				edge.destination = j;
				edge.cost = weight;
				vertices[i].Edges.push_back(edge);

				edge.source = j;
				edge.destination = i;
				vertices[j].Edges.push_back(edge);
			}
		}
	}
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}


Node LowestCost(multiset<Node> OpenList)
{
	std::multiset<Node>::iterator it = OpenList.begin();

	return (*it);									// Lowest total cost Node
}


void Graph::AddtoOpenList(multiset<Node>& OpenList, Node node, double currentcost)
{
	for( unsigned int i = 0; i < node.Edges.size(); i++)			//Search all Edges with this Node
	{


		multiset<Node>::iterator it = OpenList.find(vertices[node.Edges[i].destination]); 	//Is the New Node already on the Open list
		if(it != OpenList.end())
		{
			if(it->TotalCostToDestination >= node.Edges[i].cost + currentcost)				// Update Node already on Open List check if this path is cheaper
			{
				vertices[node.Edges[i].destination].TotalCostToDestination = node.Edges[i].cost + currentcost;  // Update Graph Info
				vertices[node.Edges[i].destination].Path = node.Path;
				vertices[node.Edges[i].destination].Path.push_back(node.Edges[i]);

				OpenList.erase(it);																				//remove old node data
				OpenList.insert(vertices[node.Edges[i].destination]);											//Add updated node to Open List
			}
		}
		else
		{
			vertices[node.Edges[i].destination].TotalCostToDestination = node.Edges[i].cost + currentcost;
			vertices[node.Edges[i].destination].Path = node.Path;
			vertices[node.Edges[i].destination].Path.push_back(node.Edges[i]);
			OpenList.insert(vertices[node.Edges[i].destination]);												//Add node to Open List
		}

	}
	OpenList.erase(node);  //after exploring all edges from this node remove Node from Open List
}

bool DestinationFound(vector<Node> List, int node)
{
	bool found = false;
	for(unsigned int i = 0; i < List.size(); i++)
	{
		if(List[i].name == node)
		{
			found = true;
			break;
		}
	}
	return found;
}

vector<Edge> Graph::ShortestPath(int source, int destination)
{
	vector<Node> ClosedList;
	multiset<Node> OpenList;
	Node currentNode;

	if(source == destination)																		//Shouldn't happen will return empty path
		return vertices[source].Path;

	AddtoOpenList(OpenList, vertices[currentNode.name], currentNode.TotalCostToDestination);		//add starting node end points to Open List
	ClosedList.push_back(vertices[currentNode.name]);												//add starting node Closed List

	while(!OpenList.empty())
	{
		currentNode = LowestCost(OpenList);															//Find Lowest Cost Node on OpenList
		AddtoOpenList(OpenList, vertices[currentNode.name], currentNode.TotalCostToDestination);	//Add C
		ClosedList.push_back(vertices[currentNode.name]);

		if(DestinationFound(ClosedList, destination))												//Have we found the destination?
		{
			break;
		}
	}

	return vertices[destination].Path;																//Return Path of Destination will be empty path if no valid path
}


double Graph::ShortestPathCost(int source, int destination)
{
	vector<Node> ClosedList;
	multiset<Node> OpenList;
	Node currentNode;

	if(source == destination)																		//Shouldn't happen will return 0
	{
		vertices[source].TotalCostToDestination = 0;
		return vertices[source].TotalCostToDestination;
	}


	AddtoOpenList(OpenList, vertices[currentNode.name], currentNode.TotalCostToDestination);		//add starting node end points to Open List
	ClosedList.push_back(vertices[currentNode.name]);												//add starting node Closed List

	while(!OpenList.empty())
	{
		currentNode = LowestCost(OpenList);															//Find Lowest Cost Node on OpenList
		AddtoOpenList(OpenList, vertices[currentNode.name], currentNode.TotalCostToDestination);	//Add C
		ClosedList.push_back(vertices[currentNode.name]);

		if(DestinationFound(ClosedList, destination))												//Have we found the destination?
		{
			break;
		}
	}

	return vertices[destination].TotalCostToDestination;											//Return Total Cost will be -1 if no valid path
}


void Graph::PrintNeighborsWeight(int node)
{
	cout << "Neighbors of Node" << node << endl;
	cout << "% of Neighbors:" << (double)(vertices[node].Edges.size())/vertices.size() << endl;

	for(unsigned int i = 0; i < vertices[node].Edges.size(); i++)
	{
		cout << "Src: " << vertices[node].Edges[i].source << " Dest: " << vertices[node].Edges[i].destination
			   << " Cost: " << vertices[node].Edges[i].cost << endl;
	}
	cout << endl;
}

void Graph::PrintNeighbors(int node)
{
	cout << "Neighbors of Node" << node << endl;
	cout << "% of Neighbors:" << (double)(vertices[node].Edges.size())/vertices.size() << endl;
	for(unsigned int i = 0; i < vertices[node].Edges.size(); i++)
	{
		cout <<	vertices[node].Edges[i].destination << " , ";
	}
	cout << endl;
}


void Graph::PrintVertices()
{
	for(unsigned int i = 0; i < vertices.size(); i++)
	{
		cout <<	vertices[i].name << endl;
	}
}