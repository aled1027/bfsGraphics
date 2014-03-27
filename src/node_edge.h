#pragma once
 
#include "ofMain.h"
#include <iostream>
#include <list>
#include <utility>

class Edge; class State; class Node;

class Node {
public:
	Node();
	Node(int, int, int, int);
	~Node();
	void addEdge(Edge*);
	bool checkClick(int, int) const;
	void hit();
	void mousePressed();
	void changeColor();
	void setColor(int, int, int);
	void draw();
	pair<int,int> getCoords() const;
	int getId() const;
	Node getObjectCopy();



private:
	ofColor color;
	int whichColor; // if 1 use color1. etc. 
	int w;
	int x;
	int y;
	int id;
	int radius;
	std::list<Edge*> edges;
};

class Edge {
public: 
	Edge(Node*, Node*);
	~Edge();
	void draw();
	void changeColor(int,int,int);
	int getStartId() const;
	int getEndId() const;

private:
	const Node *start;
	const Node *end;
	ofColor color;
};

class State {
public:
	State(vector<Node>, vector<Edge>);
	void draw();

private:
	std::vector <Node> nodes;
	std::vector <Edge> edges;
};


//     std::copy(to_vector.begin(), to_vector.end(),
//                   std::ostream_iterator<int>(std::cout, " "));




