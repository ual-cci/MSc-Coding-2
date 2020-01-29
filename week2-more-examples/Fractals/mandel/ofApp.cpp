#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    z,zx,zy=0;//So these are variables that hold the absolute value of z, and the x and y coordinates that we use to represent z
    cx,cy,x,y=0;//These are variables we use to represent the complex number c - which is a pixel location.
    maxIterations=50;//We calculate the fractal by running a test over and over again for each pixel.
    res=1;
    //NoLooping;

    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofTranslate(700, 300);
    //We are going to test every single pixel on the screen, so we need nested for loops.
    for (int i=-700;i<500;i+=res) {//for every pixel in the x dimension (columns)...
        for (int j=-300;j<300;j+=res) {//...run through all the y pixels
            cx=(float)i/250;
            cy=(float)j/250;
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
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    maxIterations=mouseX/10;

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