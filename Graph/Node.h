/*
 * Node.h
 *
 *  Created on: Oct 25, 2013
 *      Author: SK1033
 */

#ifndef NODE_H_
#define NODE_H_

#include "Edge.h"
#include <vector>
using std::vector;


class Node {
public:
	Node();
	virtual ~Node();

	int name;  						//integer labeled for identifying a node
	double TotalCostToDestination;
	vector<Edge> 	Path;  	//vector of the path to this Destination that is associated with the Total Cost
	vector<Edge> 	Edges;  	//vector of neighbors


	bool operator < (const Node& node) const
	{
	return (this->TotalCostToDestination < node.TotalCostToDestination);
	}


};

#endif /* NODE_H_ */
