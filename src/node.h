#pragma once
 
#include "ofMain.h"
#include <vector>
#include <utility>

class Node {
public:
	Node();
	Node(int, int, int, int);
	~Node();
	bool checkDistance(int, int);
	void mousePressed();
	void changeColor();
	void draw();
	pair<int,int> getCoords();
	int getId();


private:
	ofColor color;
	int whichColor; // if 1 use color1. etc. 
	int w;
	int x;
	int y;
	int id;
	int radius;
};
