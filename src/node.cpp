#include "node.h"
 
Node::Node() {
}

Node::Node(int _id, int r, int _x, int _y) {
	id = _id;
	x = _x;
	y = _y;
	radius = 50;
	whichColor = 1;
	color.set(0,255,0);

}

Node::~Node() {
	return;
}

bool Node::checkDistance(int _a, int _b) {
	if (ofDist(x, y, _a, _b) < radius) {
		return true;
	} else {
		return false;
	}

}

void Node::mousePressed() {
//	std::cout << "Node::mousePressed" << std::endl;
	changeColor();
}

void Node::changeColor() {
	if (whichColor == 1) { 
		color.set(0,0,255);
		whichColor = 2;
	} else if (whichColor == 2) {
		color.set(0,255,0);
		whichColor = 1;
	}
}

void Node::draw() {
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
