#include "node.h"
 
Node::Node() {
}

Node::Node(int _id, int r, int _x, int _y) {
	id = _id;
	x = _x;
	y = _y;
	radius = 50;
	color.set(0,255,0);
}

Node::~Node() {
	return;
}
 
void Node::draw(){
	ofSetColor(color);
	ofFill();
	ofCircle(x, y, radius);
}

pair<int,int> Node::getCoords() {
	return make_pair(x,y);
}

int Node::getId() {
	return id;
}
