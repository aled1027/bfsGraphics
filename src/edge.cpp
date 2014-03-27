#include "node_edge.h"

Edge::Edge(Node *_start, Node *_end) {
	start = _start;
	end = _end;
	color.set(0,255,0); // initialize to green
}

void Edge::changeColor(int _r, int _g, int _b) {
	color.set(_r,_g,_b);
}

Edge::~Edge() {
}

void Edge::draw(){
	ofFill();
	ofSetColor(color);
	pair<int,int> begin = start->getCoords();
	pair<int,int> stop = end->getCoords();
	ofLine(begin.first, begin.second, stop.first+1, stop.second+1);
}

int Edge::getStartId() const {
	return start->getId();
}
int Edge::getEndId() const {
	return end->getId();
}
