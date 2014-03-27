#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

#include "ofMain.h"
#include "node_edge.h"

using namespace std;

class Graph {
public:
	Graph();
	~Graph();

	void addNode(int, int, int);
	void addEdge(int x, int y);
	vector<Node*>& getNodes();
	vector<Edge*>& getEdges();

	// related to BFS
	void BFS(int,int);
	bool isConnected(int,int);
	void saveState();
	void drawState();
	void incrementStateCounter();

private:
	std::vector<Node*> nodes;
	std::vector<Node*>::iterator nodesIt;

	std::vector<Edge*> edges;
	std::vector<Edge*>::iterator edgesIt;
	int radius; // radius we want our nodes to be
	int num_nodes;

	// related to BFS
	std::vector<State*> BFSstates; // remember to delete // haven't done this yet
	int stateCounter;
};
