#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    z,zx,zy=0;//So these are variables that hold the absolute value of z, and the x and y coordinates that we use to represent z
    cx,cy,x,y=0;//These are variables we use to represent the complex number c - which is a pixel location.
    maxIterations=20;//We calculate the fractal by running a test over and over again for each pixel.
    res=2;

    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(600, 450);
    //We are going to test every single pixel on the screen, so we need nested for loops.
    for (int i=-600;i<600;i+=res) {//for every pixel in the x dimension (columns)...
        for (int j=-450;j<450;j+=res) {//...run through all the y pixels
            zx=(float)i/300.0;//this is going to create a Julia set
            zy=(float)j/225.0;
            cx=(mouseX/300.0)-2.0;//adjust the values of x so that it is between -2 and 2, as this is where the mandelbrot is. Otherwise we'd be searching around for ages.
            cy=(mouseY/225.0)-2.0;//same for y. These two lines have given us the complex number c, which is just (cx,cy)
            for (int test=0;test<maxIterations && z<4.0;test++) {//now we run the test as many times as we want. the more we run it the longer it takes
                //the way we calculate z^2 is as follows :
                // z^2=(zx^2-zy^2,2*zx*zy)
                x=(zx*zx)-(zy*zy);//this x is going to be used to calculate zx
                y=2*zx*zy;//and y will be used to calculate zy
                zx=x+cx;//we add cx to x to get the current value of zx
                zy=y+cy;//and then add cy to y to get the current value of zy
                z=zx*zx+zy*zy;//Now we get the new absolute value of z so that we can see if it's over 2 the next time we run the test. If it is, we don't do anything
                ofSetColor((255/maxIterations)*test);//the colour we use depends on how many tests we had to do before the value of z got bigger than 2.
            }
            z=0;//before we run the next test we need to clear the variables we're using.
            zx=0;
            zy=0;
            ofRect(i,j,res,res);//now we draw the pixel with a colour that represents how many tests we did before the output went over 2.0
        }
    }
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}