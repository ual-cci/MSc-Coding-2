#include "testApp.h"

testApp::~testApp()
{
	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
}

//--------------------------------------------------------------
void testApp::setup(){
	
	
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();
	ofSetWindowPosition(screenW/2-300/2, screenH/2-300/2);
	
	//load our typeface
	vagRounded.loadFont("vag.ttf", 16);
    
	bFullscreen	= 0;
	
	//lets set the initial window pos
	//and background color
	//ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofSetWindowShape(640, 480);
	
	ofBackground(0,50,50);
	
	// set up the boids
	for (int i = 0; i < 50; i++)
		boids.push_back(new Boid());
	
	framecounter = 0;
	updatecounter = 0;
}


//--------------------------------------------------------------
void testApp::update(){
    
	//update our window title with the framerate and the position of the window
	//[zach fix] ofSetWindowTitle(ofToString(ofGetFrameRate(), 2)+":fps - pos ("+ofToString((int)windowX)+","+ofToString((int)windowY)+")");
    
	
	if(bFullscreen){
		ofHideCursor();
	}else{
		ofShowCursor();
	}
	
	ofxVec3f min(0, 0);
	ofxVec3f max(ofGetWidth(), ofGetHeight());
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids, min, max);
	}
	updatecounter += 1;
}

//--------------------------------------------------------------
void testApp::draw(){
	framecounter += 1;
	ofSetupScreen();
	
    
	
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
	}
	
    //	vagRounded.drawString("frame rate frame " + ofToString(framecounter/ofGetElapsedTimef()) + " update " + ofToString(updatecounter/ofGetElapsedTimef()), 10, 25);
    
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
	if(key == 'f'){
        
		bFullscreen = !bFullscreen;
		
		if(!bFullscreen){
			ofSetWindowShape(300,300);
			ofSetFullscreen(false);
			// figure out how to put the window in the center:
			int screenW = ofGetScreenWidth();
			int screenH = ofGetScreenHeight();
			ofSetWindowPosition(screenW/2-300/2, screenH/2-300/2);
		} else if(bFullscreen == 1){
			ofSetFullscreen(true);
		}
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
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
