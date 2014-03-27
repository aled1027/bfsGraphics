#include "node_edge.h"

State::State(vector<Node> _nodes, vector<Edge> _edges) {
	nodes = _nodes;
	edges = _edges;
}

void State::draw() {
	// Draw nodes
	vector<Node>::iterator nodesIt; // iterator for traversing
	for (nodesIt = nodes.begin(); nodesIt != nodes.end(); nodesIt++) {
		nodesIt->draw();
	}

	// Draw edges
	vector<Edge>::iterator edgesIt; 
	for (edgesIt = edges.begin(); edgesIt != edges.end(); edgesIt++) {
		edgesIt->draw(); 
	}
}




