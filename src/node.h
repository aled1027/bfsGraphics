#ifndef node_h
#define node_h
 
#include "ofMain.h"
#include <vector>
#include <utility>
 
class Node {
public:
	Node();
	Node(int, int, int, int);
	~Node();
	void draw();
	pair<int,int> getCoords();
	int getId();
	

private:
	ofColor color;
	int x;
	int y;
	int id;
	int radius;
};
#endif
