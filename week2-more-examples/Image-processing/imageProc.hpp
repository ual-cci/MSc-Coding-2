//
//  imageProc.hpp
//  emptyExample
//
//  Created by Michael Grierson on 13/11/2017.
//

#ifndef imageProc_hpp
#define imageProc_hpp

#include <stdio.h>
#include "ofMain.h"

class imageProc {
    
public:
    
    ofPixels threshRBG(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, int thresh);
    
    ofPixels iThreshRBG(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, int thresh);
    
    ofPixels threshGreyscale(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, int thresh);
    
    ofPixels iThreshGreyscale(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, int thresh);
    
    ofPixels greyscale(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels);

    ofPixels motionBlur(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float blur);

    ofPixels simpleHighPass(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float blur);
    
    ofPixels simpleEdgeDetect(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float edge);
 
    ofPixels resizeX(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float resize);
    
    ofPixels resizeY(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float resize);
    
    ofPixels resize(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float resize);

    ofPixels resizeXY(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float resizeX, float resizeY);

    ofPixels resizeXY(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float resizeX, float resizeY, float anchorX, float anchorY);
    
    ofPixels rotate(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float theta);

    ofPixels rotate(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float theta, int anchorX, int anchorY, int offsetX, int offsetY, float zoomX, float zoomY);

    ofPixels convolve(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float kernel[9]);
    
    float lastVal;
    
    float lastVals[9];
    
    float kernel[9];
    
};




#endif /* imageProc_hpp */
