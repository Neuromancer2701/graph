/*
 * Edge.h
 *
 *  Created on: Oct 27, 2013
 *      Author: count zero
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <ostream>

class Edge {
public:
	Edge();
	virtual ~Edge();

	int source;
	int destination;

	double cost;

	bool operator < (const Edge& edge) const
	{
		return (this->cost < edge.cost);
	}
};

#endif /* EDGE_H_ */
