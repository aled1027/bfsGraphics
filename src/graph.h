#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#include "ofMain.h"
#include "node.h"
#include "edge.h"

using namespace std;

class Graph {
public:
	Graph();
	~Graph();

	void addNode(int, int, int);
	void addEdge(int x, int y);
	// vector<Node*>::iterator getNodesBegin();
	// vector<Node*>::iterator getNodesEnd();
	vector<Node*>& getNodes();
	vector<Edge>& getEdges();
	void BFS(int, int);

private:
	std::vector<Node*> nodes;
	std::vector<Node*>::iterator nodesIt;

	std::vector<Edge> edges;
	std::vector<Edge>::iterator edgesIt;
	int radius;
};
