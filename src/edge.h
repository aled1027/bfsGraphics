#pragma once

#include "ofMain.h"
#include "node.h"

#include <utility>

class Edge {
public: 

	Edge(const Node*, const Node*);
	~Edge();
	void draw();
	void setColor1();
	void setColor2();
private:
	const Node *start;
	const Node *end;
	ofColor color;
	ofColor color1;
	ofColor color2;

};

