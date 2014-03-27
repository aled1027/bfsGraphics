#include "graph.h"

Graph::Graph() {
	radius = 50;
	num_nodes = 0;
	// inefficient, but needed for Graph::addNode
	for (int i=0; i<100; i++) {
		nodes.push_back(0);
	}
	// for BFS
	stateCounter = 0;
}

Graph::~Graph() {
	// Delete *node from nodes
	for (nodesIt = nodes.begin(); nodesIt != nodes.end(); nodesIt++) {
		if (*nodesIt) {
	    	delete *nodesIt;
		}
	}
	// Delete *edge from edges
	for (edgesIt = edges.begin(); edgesIt != edges.end(); edgesIt++) {
		if (*edgesIt) {
	    	delete *edgesIt;
		}
	}
	// delete *state from BFSstates
	vector<State*>::iterator it;
	for (it = BFSstates.begin(); it != BFSstates.end(); it++) {
		if (*it) {
	    	delete *it;
		}
	}
}

void Graph::addNode(int id, int x, int y) {
	// make this so it can't be misued (add try, except or if-then-else)
	nodes[id] = new Node(id, radius, x, y);
	num_nodes++;
}

void Graph::addEdge(int _from, int _to) {
	Edge * new_edge = new Edge(nodes[_from], nodes[_to]);
	edges.push_back(new_edge); // add to Graph::edges vector
	nodes[_from]->addEdge(new_edge); // add edge to each node
	nodes[_to]->addEdge(new_edge); // add edge to each node
}

vector<Node*>& Graph::getNodes() {
	return nodes;
}

vector<Edge*>& Graph::getEdges() {
	return edges;
}




bool Graph::isConnected(int a, int b) {
	for (edgesIt = edges.begin(); edgesIt != edges.end(); edgesIt++) {
		if ((*edgesIt)->getStartId() == a && (*edgesIt)->getEndId() == b) {
			return true;
		} else if ((*edgesIt)->getStartId() == b && (*edgesIt)->getEndId() == a) {
			return true;
		}
	}
	return false;
}

// this should be const
void Graph::BFS(int x, int required) {
	saveState();
	if (x==required) {
		return;
	}

	std::queue<Node*> Qn;
	Qn.push(nodes[x]);

	vector<bool> visited(num_nodes, false);
	visited[x] = true; 
	while (!Qn.empty()) {
		// print queue
		std::cout << std::endl << "printing queue" << std::endl;
		std::queue<Node*> Q = Qn;
		while(!Q.empty()) {
			Node * asdf = Q.front();
			std::cout << asdf->getId() << " ";
			Q.pop();
		}

		// bfs
		Node *k = Qn.front();
		Qn.pop();
		k->hit(); saveState(); // saving state
		if (k->getId() == required) {
			cout << "finished bfs" << std::endl;
			return;
		}
		for (int i=1; i<num_nodes; i++) {
			if (isConnected(k->getId(), i) && !visited[i]) {
				visited[i] = true;
				Qn.push(nodes[i]);
			}
		}
	}
}

void Graph::saveState() {
	// make the nodes not pointers
	vector <Node> the_nodes;
	vector <Node*>::iterator nit;
	for (nit = nodes.begin(); nit != nodes.end(); nit++) {
		if (*nit) {  // check if pointer is not null
			the_nodes.push_back(**nit);
		}	
	}
	// make the edges not pointers
	vector <Edge> the_edges;
	vector <Edge*>::iterator eit;
	for (eit = edges.begin(); eit != edges.end(); eit++) {
		if (*eit) {
			the_edges.push_back(**eit);
		}
	}
	// create State pointer
	State * s = new State(the_nodes, the_edges);
	BFSstates.push_back(s);
}

void Graph::drawState() {
	BFSstates[stateCounter]->draw();
}

void Graph::incrementStateCounter() {
	if (stateCounter < BFSstates.size()-1) {
		stateCounter++;
	}
}
