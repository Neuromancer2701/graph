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

};

#endif /* EDGE_H_ */
