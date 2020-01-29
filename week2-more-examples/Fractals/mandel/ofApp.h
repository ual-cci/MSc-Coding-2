#pragma once

#include "ofMain.h"

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

    float z,zx,zy;//So these are variables that hold the absolute value of z, and the x and y coordinates that we use to represent z
    float cx,cy,x,y;//These are variables we use to represent the complex number c - which is a pixel location.
    int maxIterations;//We calculate the fractal by running a test over and over again for each pixel.
    int res;

};
