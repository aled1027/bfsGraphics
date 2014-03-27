#include "node_edge.h"
 
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

void Node::addEdge(Edge* new_edge) {
	edges.push_back(new_edge);
}

bool Node::checkClick(int _a, int _b) const {
	// checks if distance from click to center of circle (x,y) is less than the radius
	// ie, was the click inside the shape?
	if (ofDist(x, y, _a, _b) < radius) {
		return true;
	} else {
		return false;
	}
}

void Node::hit() {
	changeColor();
}

void Node::mousePressed() {
//	std::cout << "Node::mousePressed" << std::endl;
	changeColor();
}

void Node::changeColor() {
	switch (whichColor) {
		case 1:  
			color.set(0,0,255);
			whichColor = 2;
			//change colors of edges
			for (list<Edge*>::iterator it = edges.begin(); it != edges.end(); it++) {
				(*it)->changeColor(0,0,255); 
			}
			break;
		case 2:
			color.set(0,255,0);
			whichColor = 1;
			//change colors of edges
			for (list<Edge*>::iterator it = edges.begin(); it != edges.end(); it++) { (*it)->changeColor(0,255,0); }
			break;
	}
}

void Node::setColor(int _red, int _green, int _blue) {
	color.set(_red, _green, _blue);
	
}

void Node::draw() {
	ofSetColor(color);
	ofFill();
	ofCircle(x, y, radius);
}
 
pair<int,int> Node::getCoords() const {
	return make_pair(x,y);
}

int Node::getId() const {
	return id;
}

Node Node::getObjectCopy() {
	return *this;
}
