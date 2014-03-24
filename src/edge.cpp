#include "edge.h"

Edge::Edge(const Node *_start, const Node *_end) {
	start = _start;
	end = _end;
	color1.set(0,255,0);
	color2.set(0,0,255);
	setColor1();
}

Edge::~Edge() {
}

void Edge::setColor1() {
	color = color1;
}

void Edge::setColor2() {
	color = color2;
}

void Edge::draw(){
	ofFill();
	ofSetColor(color);
	pair<int,int> begin = start->getCoords();
	pair<int,int> stop = end->getCoords();
	ofLine(begin.first, begin.second, stop.first+1, stop.second+1);
}


