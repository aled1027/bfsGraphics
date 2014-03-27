#pragma once

#include "ofMain.h"

#include "graph.h"
#include "node_edge.h"
#include "logger/logger.h"

#include <iostream>
#include <vector>

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	// objects
	
	Logger logger;
	Graph g;

	// useful iterators

};
