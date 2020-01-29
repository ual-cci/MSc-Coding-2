#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    myImage.load("adele.jpg");
    

}


//--------------------------------------------------------------
void ofApp::update(){
    
    ofPixels pix;
    
    ofPixels myPixels;
    
    myPixels.allocate(myImage.getWidth(), myImage.getHeight(),3);
    
    pix = myImage.getPixels();
    
    //for testing convolution
    //myPixels = myImage.getPixels();
    
    float div = mouseX / 10;
 
//    myPixels = myImageProc.rotate(pix, myPixels, myImage.getWidth(), myImage.getHeight(), 3, (float )mouseX / 100.0);
    
    myPixels = myImageProc.rotate(pix, myPixels, myImage.getWidth(), myImage.getHeight(), 3,(float) mouseX/ofGetWidth() * PI * 3, myImage.getWidth()/2,myImage.getHeight()/2,0,0,1,1);
 
          //box blur
          //float myKernel[9]={1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9};
    
    //      motion blur
          //float myKernel[9]={0.5/6,0.5/6,1.0/6,0.5/6,0.5/6,1.0/6,0.5/6,0.5/6,1.0/6};
    
    //      Guassian blur
//          float myKernel[9]={1.0/16,2.0/16,1.0/16,2.0/16,4.0/16,2.0/16,1.0/16,2.0/16,1.0/16};
//
//    for (int i = 0 ; i < mouseX/2 ; i++) {
//
//        myPixels = myImageProc.convolve(myPixels, myPixels, myImage.getWidth(), myImage.getHeight(), 3, myKernel);
//
//    }
    
    myTexture.allocate(myPixels);
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    myTexture.draw(0,0);
    
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
