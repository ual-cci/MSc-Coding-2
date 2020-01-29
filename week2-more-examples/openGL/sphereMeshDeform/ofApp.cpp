#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    
    plane.set(200, 200);
    
    //You can call these in update or draw if you want - they work interactively

    plane.setResolution(100);
    plane.setPosition(ofGetWidth()*0.5, ofGetHeight()*0.5, 0);
    //plane.rotate(45,1,0,0);
    
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(1, 1, 1) );
    pointLight.setSpecularColor( ofFloatColor(1, 1, 1));
    pointLight.setAreaLight(500, 500);

    myImage.load("of.png");
    //myImage.getTexture().setTextureWrap( GL_REPEAT, GL_REPEAT );

}

//--------------------------------------------------------------
void ofApp::update(){

    plane.rotate(1,0.2,0.5,0);

    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
     //We are going to start by copying the plane's mesh into the deformPlane vboMesh
    ofEnableDepthTest();
    
    //ofEnableLighting();
    //pointLight.enable();
    
    myImage.getTexture().bind();
    plane.mapTexCoordsFromTexture( myImage.getTexture() );
    
    deformPlane = plane.getMesh();

    //We're going to create a 3 dimensional float vector to store each vertex

    ofVec3f vertexValue;
    
    //Now we are going to run a loop so that we can transform the z value of the deformPlane mesh
    
    for(int i = 0; i < deformPlane.getNumIndices(); i++ ) { // the loop goes through all the vertexes
        
        
        amp = 0.00001; // updates slowing
        
        int vertexIndex = deformPlane.getIndex(i);
        
        vertexValue = deformPlane.getVertex(vertexIndex); // get the current vertex value and store it.
        
        float er = cos(sin(mouseX*amp*i));
        float ery = cos(cos(mouseY*amp*i));
        
        vertexValue.x *= er; // make the vec value equal something else. Anything..
        vertexValue.y *= ery;
        vertexValue.z *= er*ery;
        
        deformPlane.setVertex( vertexIndex, vertexValue ); // write it all back, including the new z.
        
    }

    
    //plane.draw(); //This draws the original, non-deformed plane mesh
    
    //This next line gets the current position, rotation, scale etc. of the plane mesh.
    //Anything we draw after this will retain these coordinates / transforms.
    
    plane.transformGL();
    
    //Now we draw our newly deformed plane
    deformPlane.draw();
    
    //If you want, restore the coordinate system so that we can
    //draw something else without inheriting the plane's transforms
    plane.restoreTransformGL();
    
    myImage.getTexture().unbind();

    ofDisableDepthTest();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
