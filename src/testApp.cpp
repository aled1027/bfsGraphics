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
	g.addEdge(4,6);
}
//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(ofColor::black);
	ofBackgroundGradient(ofColor::white,ofColor(0,0,255), OF_GRADIENT_CIRCULAR);
	ofSetColor(0, 255, 0);
	ofFill();

	// Draw nodes
	vector<Node> vn = g.getNodes();
	for (nodesIt = vn.begin(); nodesIt != vn.end(); nodesIt++) { // can't use for_each here?
		nodesIt->draw();
	}
	
	// Draw edges
	vector<Edge> ve = g.getEdges();
	std::cout << ve.size() << std::endl;
	for (edgesIt = ve.begin(); edgesIt != ve.end(); edgesIt++) {
		edgesIt->draw();
	}

	// Draw framerate
	ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
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
