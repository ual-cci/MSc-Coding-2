#include "ofApp.h"

// This example uses pure openGL (mostly) to create a procedural sphere

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableDepthTest();
    
    dim=20;
    spacing = ((PI * 2) / dim);
    size = 2;
    
    // This code generates all the vertices we need to make a sphere
    for (int i = 0; i < dim + 1; i++) {
        
        // ******* Calculate the current ring position ********
        
        // To calculate the current ring position, we divide our spacing variable in half
        // This is because otherwise, the cosine / sine waves will
        // generate twice as many numbers as we need (e.g. positive then negative)
        // We only need the first half of the wave
        
        // z is the position of the current ring
        float z = size * cos(spacing / 2 * i);
        
        // This calculates the size of the current ring
        float s = size * sin(spacing / 2 * i);
        
        // For each ring..
        
        for (int j = 0; j < dim ; j++) {
            
            // ...create the next point in the circle at the current size s, at the current depth z
            
            ofVec3f point;
            
            point.set(cos(spacing * j) * s,sin(spacing * j) * s,z);
            
            points.push_back(point);

        }
    }

    cout << "done";
    
    //We are using ofCamera, which sets up a projection matrix like the ones we have built by hand.
    //Here we can set the clipping planes
    //And also the camera position
    //If we wanted we could adjust the FOV and a bunch of other stuff
    
    
    cam.setNearClip(1);
    cam.setFarClip(-100);
    cam.setPosition(0,0,10);
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0);

    // cam gives us proper openGL world coordinates, like proper openGL
    cam.begin();

    // We're rotating using OF, because OFs projection matrix is a bit screwy if we use the native openGL method.
    
    ofRotateY(ofGetElapsedTimeMillis()/20);
    
 glBegin(GL_LINE_LOOP);

    // you could do this instead
//    glBegin(GL_TRIANGLES);

    for (int i = dim ; i < points.size(); i++) {
        
        ofVec3f vec;
        
        glVertex3f(points[i].x, points[i].y, points[i].z);
        
        glVertex3f(points[i-1].x, points[i-1].y, points[i-1].z);

        glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);

        glVertex3f(points[i-1].x, points[i-1].y, points[i-1].z);
        
        glVertex3f(points[i-dim-1].x, points[i-dim-1].y, points[i-dim-1].z);
        
        glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);
        
    }

    glEnd();

    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
