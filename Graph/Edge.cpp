/*
 * Edge.cpp
 *
 *  Created on: Oct 27, 2013
 *      Author: count zero
 */

#include "Edge.h"
#include <ostream>

Edge::Edge() {
	// TODO Auto-generated constructor stub

}

Edge::~Edge() {
	// TODO Auto-generated destructor stub
}

std::ostream& operator <<(std::ostream& stream, const Edge& edge)
{
	stream << "Src: " << edge.source << " Dest: " << edge.destination
		   << " Cost: " << edge.cost << std::endl;
	return stream;
}
