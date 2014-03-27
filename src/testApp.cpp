#include "testApp.h"

/*
 * Window of 1048 x 648
 */

int n = 3;

//--------------------------------------------------------------
void testApp::setup(){
	// initialize logger
	Logger logger(std::string("logs.txt"));
	logger << std::string("in testApp::setup()");

	ofEnableSmoothing(); // not sure what this does
	ofSetFrameRate(30);

	// add nodes to graph
	for (int i = 1; i<5; i++) {
		g.addNode(i,i*150, 200); 
		g.addNode(i+4, i*150, 400);
	}
	// add edges to graph
	g.addEdge(1,2);
	g.addEdge(1,6);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.BFS(1,6);
}
//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(ofColor::black);
	ofBackgroundGradient(ofColor::white,ofColor(0,0,255), OF_GRADIENT_CIRCULAR); // blue/white

	// BFS
	g.drawState();

//	// Draw nodes
//	vector<Node*>::iterator nodesIt; // iterator for traversing
//	vector<Node*> vNodes = g.getNodes(); // vector of all pointers to all nodes
//	for (nodesIt = vNodes.begin(); nodesIt != vNodes.end(); nodesIt++) {
//		if (*nodesIt) {	(*nodesIt)->draw(); } // if pointer is not null
//	}
//
//	// Draw edges
//	vector<Edge*>::iterator edgesIt;  // iterator for traversing
//	vector<Edge*> vEdges = g.getEdges(); // vector of all pointers to all nodes
//	for (edgesIt = vEdges.begin(); edgesIt != vEdges.end(); edgesIt++) {
//		if (*edgesIt) {	(*edgesIt)->draw(); } // if pointer is not null
//	}

	// Draw framerate
	ofSetColor(0, 255, 0); //green
	ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	g.incrementStateCounter();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//vector<Node*>::iterator nodesIt;
	//vector<Node*> vnp = g.getNodes(); // vector of all pointers to all nodes
	//for (nodesIt = vnp.begin(); nodesIt != vnp.end(); nodesIt++) {
	//	if (*nodesIt) { // check if null
	//		if ((*nodesIt)->checkClick(x,y)) { (*nodesIt)->mousePressed(); } // check if clicked inside 
	//	}
	//}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
