#ifndef edge_h
#define edge_h

#include "ofMain.h"
#include "node.h"

#include <utility>

class Edge {
public: 
	Edge(Node&, Node&);
	~Edge();
	void draw();
	void setColor1();
	void setColor2();
private:
	Node start;
	Node end;
	ofColor color;
	ofColor color1;
	ofColor color2;

};

#endif
