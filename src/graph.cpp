#include "graph.h"

Graph::Graph() {
	radius = 50;
	// inefficient, but needed for Graph::addNode
	for (int i=0; i<100; i++) {
		nodes.push_back(Node());
	}
}

Graph::~Graph() {

}

void Graph::addNode(int id, int x, int y) {
	// make this so it can't be misued (add try, except or if-then-else)
	nodes.at(id) = Node(id, radius, x, y);
}

void Graph::addEdge(int _from, int _to) {
	edges.push_back(Edge(nodes[_from], nodes[_to]));
}


vector<Node>& Graph::getNodes() {
	return nodes;
}

vector<Edge>& Graph::getEdges() {
	return edges;
}

void Graph::BFS(int x, int required) {
	std::queue<int> Q;
	vector<bool> visited(nodes.size(), false);
	Q.push(x);
	if (x==required) {
		return;
	}

	visited[x] = true;
	std::cout << "Starting bfs from vertex" << std::endl;
	std::cout << x << ": ";
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		if (k == required) {
			cout << "Found here" << endl;
			continue;
		}
		std::cout << k << " ";
		for (int i=0; i<nodes.size(); i++) {
			// fix below -- add isConnected ----- CAN USE <ALGORITHMS>
			if (true) {
	//		if (isConnected(k, i) && !visited[i]) {
				Q.push(i);
				visited[i] = true;
			}
		}
	}
	cout << endl;
}
