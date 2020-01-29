//
//  imageProc.cpp
//  emptyExample
//
//  Created by Michael Grierson on 13/11/2017.
//

#include "imageProc.hpp"


// Assumes RBG

ofPixels imageProc::threshRBG(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, int thresh) {
    
    for (int i =0;i<sizeW*sizeH*channels;i++) {
        
        if (pixIn[i]>thresh) {
            
            pixOut[i]=pixIn[i];
        
        } else {
            
            pixOut[i]=0;
            
        }
    }
    
    return pixOut;
}

ofPixels imageProc::iThreshRBG(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, int thresh) {
    
    for (int i =0;i<sizeW*sizeH*channels;i++) {
        
        if (pixIn[i]<thresh) {
            
            pixOut[i]=pixIn[i];
            
        } else {
            
            pixOut[i]=0;
            
        }
    }
    
    return pixOut;
}

// Assumes RGB
// 0.2126*R + 0.7152*G + 0.0722*B
ofPixels imageProc::threshGreyscale(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, int thresh) {
    
    for (int i =0;i<sizeW*sizeH*channels;i+=channels) {
        
        // we're not resizing, so there's lots of reduntant data
        
        pixOut[i]=pixOut[i+1]=pixOut[i+2]=(pixIn[i] * 0.2126) + (pixIn[i+1] * 0.7152) + (pixIn[i+2] * 0.0722);
        
        if (pixOut[i] < thresh) {
            
            pixOut[i]=pixOut[i+1]=pixOut[i+2]=0;
            
        }
        
    }
    
    return pixOut;
}

// Assumes RGB
// 0.2126*R + 0.7152*G + 0.0722*B
ofPixels imageProc::iThreshGreyscale(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, int thresh) {
    
    for (int i =0;i<sizeW*sizeH*channels;i+=channels) {
        
        // we're not resizing, so there's lots of reduntant data
        
        pixOut[i]=pixOut[i+1]=pixOut[i+2]=(pixIn[i] * 0.2126) + (pixIn[i+1] * 0.7152) + (pixIn[+2] * 0.0722);
        
        if (pixOut[i] > thresh) {
            
            pixOut[i]=pixOut[i+1]=pixOut[i+2]=0;
            
        }
        
    }
    
    return pixOut;
}


// Assumes RGB
// 0.2126*R + 0.7152*G + 0.0722*B
ofPixels imageProc::greyscale(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels) {
    
    for (int i =0;i<sizeW*sizeH*channels;i+=channels) {
        
        // we're not resizing, so there's lots of reduntant data
        
        pixOut[i]=pixOut[i+1]=pixOut[i+2]=(pixIn[i] * 0.2126) + (pixIn[i+1] * 0.7152) + (pixIn[+2] * 0.0722);
        
    }
    
    return pixOut;
}

ofPixels imageProc::motionBlur(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float blur) {
    
    for (int i =0;i<sizeW*sizeH*channels;i++) {

        pixOut[i] = lastVals[i%3] + blur * (pixIn[i] - lastVals[i%3]);
        
        lastVals[i%3] = pixOut[i];
        
    }
    
    return pixOut;
}

ofPixels imageProc::simpleHighPass(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float blur) {
    
    for (int i =0;i<sizeW*sizeH*channels;i++) {
        
        pixOut[i] = lastVals[i%3] + blur * (pixIn[i] - lastVals[i%3]);
        
        lastVals[i%3] = pixOut[i];
        
        pixOut[i] = pixIn[i]-pixOut[i];
        
    }
    
    return pixOut;
}

ofPixels imageProc::simpleEdgeDetect(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float edge) {
    
    for (int i =0;i<sizeW*sizeH*channels;i++) {
        
        pixOut[i] = lastVals[i%3] + edge * (pixIn[i] - lastVals[i%3]);
        
        lastVals[i%3] = pixOut[i];
        
        pixOut[i] = pixIn[i]-pixOut[i];
        
    }
    
    return pixOut;
}

ofPixels imageProc::resizeX(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float resize) {
    
    for (int i =0;i<sizeH*sizeW*channels;i+=sizeW*channels) {
        
        for (int j = 0;j<sizeW;j++) {

            pixOut[i+(j*3)]=pixIn[i+(floor(j*resize)*3)];
            pixOut[i+(j*3)+1]=pixIn[i+(floor(j*resize)*3)+1];
            pixOut[i+(j*3)+2]=pixIn[i+(floor(j*resize)*3)+2];
        
        }

    }
    
    return pixOut;
}

ofPixels imageProc::resizeY(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float resize) {
    
    int totalSize = sizeH*sizeW*channels;
    
    for (int i =0;i<sizeH;i++) {
        
        int coll=i*sizeW*channels;
        int resizedY = floor(i*resize)*sizeW*channels;
        
        for (int j = 0;j<sizeW;j++) {
            
            pixOut[coll+(j*3)]=pixIn[fmod(resizedY+(j*3),totalSize)];
            pixOut[coll+(j*3)+1]=pixIn[fmod(resizedY+(j*3)+1,totalSize)];
            pixOut[coll+(j*3)+2]=pixIn[fmod(resizedY+(j*3)+2,totalSize)];
            
        }
        
    }
    
    return pixOut;
}

ofPixels imageProc::resize(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float resize) {
    
    int totalSize = sizeH*sizeW*channels;
    
    for (int i =0;i<sizeH;i++) {
        
        int coll=i*sizeW*channels;
        int resizedY = floor(i*resize)*sizeW*channels;
        
        for (int j = 0;j<sizeW;j++) {
            
            pixOut[coll+(j*3)]=pixIn[fmod(resizedY+(floor(j*resize)*3),totalSize)];
            pixOut[coll+(j*3)+1]=pixIn[fmod(resizedY+(floor(j*resize)*3)+1,totalSize)];
            pixOut[coll+(j*3)+2]=pixIn[fmod(resizedY+(floor(j*resize)*3)+2,totalSize)];
            
        }
        
    }
    
    return pixOut;
}

ofPixels imageProc::resizeXY(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float resizeX, float resizeY) {
    
    int totalSize = sizeH*sizeW*channels;
    
    for (int i =0;i<sizeH;i++) {
        
        int coll=i*sizeW*channels;
        int resizedY = floor(i*resizeY)*sizeW*channels;
        
        for (int j = 0;j<sizeW;j++) {
            
            pixOut[coll+(j*3)]=pixIn[fmod(resizedY+(floor(j*resizeX)*3),totalSize)];
            pixOut[coll+(j*3)+1]=pixIn[fmod(resizedY+(floor(j*resizeX)*3)+1,totalSize)];
            pixOut[coll+(j*3)+2]=pixIn[fmod(resizedY+(floor(j*resizeX)*3)+2,totalSize)];
            
        }
        
    }
    
    return pixOut;
}

ofPixels imageProc::resizeXY(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float resizeX, float resizeY, float anchorX, float anchorY) {
    
    int totalSize = sizeH*sizeW*channels;
    
    for (int i =0;i<sizeH;i++) {
        
        int coll=i*sizeW*channels;
        int resizedY = floor((i+anchorY)*resizeY)*sizeW*channels;
        
        for (int j = 0;j<sizeW;j++) {
            
            pixOut[coll+(j*3)]=pixIn[fmod(resizedY+(floor((j+anchorX)*resizeX)*3),totalSize)];
            pixOut[coll+(j*3)+1]=pixIn[fmod(resizedY+(floor((j+anchorX)*resizeX)*3)+1,totalSize)];
            pixOut[coll+(j*3)+2]=pixIn[fmod(resizedY+(floor((j+anchorX)*resizeX)*3)+2,totalSize)];
            
        }
        
    }
    
    return pixOut;
}

ofPixels imageProc::rotate(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float theta) {
    
    int totalSize = sizeH*sizeW*channels;
    
    theta = fmod(theta,TWO_PI);
    
    for (int i=0;i<sizeH;i++) {
        
        for (int j = 0;j<sizeW;j++) {
            
            // basic rotation. Note the output is int.
            // otherwise you get weird distortion.
            int x = floor((cos(theta) * j) - (sin(theta) * i));
            int y = floor((sin(theta) * j) + (cos(theta) * i));
            
            int coll=i*sizeW*channels;
            
            if (x * y >= 0 && x * y <= sizeH*sizeW*channels) {
            
                pixOut[coll+(j*channels)]=pixIn[(y*sizeW*channels)+x*channels];
                pixOut[coll+(j*channels)+1]=pixIn[(y*sizeW*channels)+(x*channels)+1];
                pixOut[coll+(j*channels)+2]=pixIn[(y*sizeW*channels)+(x*channels)+2];
                
            }

        }
        
    }
    
    return pixOut;
}

ofPixels imageProc::rotate(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float theta, int anchorX, int anchorY, int offsetX, int offsetY, float zoomX, float zoomY) {
    
    int totalSize = sizeH*sizeW*channels;
    
    theta = fmod(theta,TWO_PI);
    
    for (int i=0;i<sizeH;i++) {
        
        for (int j = 0;j<sizeW;j++) {
 
            // Full Rotation code, including offset, anchor and zoom

            int x = floor((cos(theta)/zoomX) * (j-(offsetX+anchorX)) - (sin(theta)/zoomY) * (i-(offsetY+anchorY)))+anchorX;
            int y = floor((sin(theta)/zoomX) * (j-(offsetX+anchorX)) + (cos(theta)/zoomY) * (i-(offsetY+anchorY)))+anchorY;
            
            int coll=i*sizeW*channels;
            
            if ((y*sizeW*channels)+x*channels >= 0 && (y*sizeW*channels)+x*channels <= sizeH*sizeW*channels) {
                
                pixOut[coll+(j*channels)]=pixIn[(y*sizeW*channels)+x*channels];
                pixOut[coll+(j*channels)+1]=pixIn[(y*sizeW*channels)+(x*channels)+1];
                pixOut[coll+(j*channels)+2]=pixIn[(y*sizeW*channels)+(x*channels)+2];
                
            } else {
                pixOut[coll+(j*channels)]=0;
                pixOut[coll+(j*channels)+1]=0;
                pixOut[coll+(j*channels)+2]=0;
                
            }
            
        }
        
    }
    
    return pixOut;
}

ofPixels imageProc::convolve(ofPixels pixIn, ofPixels pixOut, int sizeW, int sizeH, int channels, float kernel[9]) {
    
    for (int i = 1; i < sizeH-1; i++) {

        int collm1=(i-1)*sizeW*channels;

        int coll=i*sizeW*channels;
        
        int collp1=(i+1)*sizeW*channels;

        for (int j = 1; j < sizeW-1; j++) {

            pixOut[coll+(j*3)]=((pixIn[collm1+((j-1)*3)] * kernel[0]) + (pixIn[collm1+((j)*3)] * kernel[1]) + (pixIn[collm1+((j+1)*3)] * kernel[2]) + (pixIn[coll+((j-1)*3)] * kernel[3]) + (pixIn[coll+((j)*3)] * kernel[4]) + (pixIn[coll+((j+1)*3)] * kernel[5]) + (pixIn[collp1+((j-1)*3)] * kernel[6]) + (pixIn[coll+((j)*3)] * kernel[7]) + (pixIn[collp1+((j+1)*3)] * kernel[8]));
            
            pixOut[coll+(j*3)+1]=((pixIn[collm1+((j-1)*3)+1] * kernel[0]) + (pixIn[collm1+((j)*3)+1] * kernel[1]) + (pixIn[collm1+((j+1)*3)+1] * kernel[2]) + (pixIn[coll+((j-1)*3)+1] * kernel[3]) + (pixIn[coll+((j)*3)+1] * kernel[4]) + (pixIn[coll+((j+1)*3)+1] * kernel[5]) + (pixIn[collp1+((j-1)*3)+1] * kernel[6]) + (pixIn[coll+((j)*3)+1] * kernel[7]) + (pixIn[collp1+((j+1)*3)+1] * kernel[8]));
            
            pixOut[coll+(j*3)+2]=((pixIn[collm1+((j-1)*3)+2] * kernel[0]) + (pixIn[collm1+((j)*3)+2] * kernel[1]) + (pixIn[collm1+((j+1)*3)+2] * kernel[2]) + (pixIn[coll+((j-1)*3)+2] * kernel[3]) + (pixIn[coll+((j)*3)+2] * kernel[4]) + (pixIn[coll+((j+1)*3)+2] * kernel[5]) + (pixIn[collp1+((j-1)*3)+2] * kernel[6]) + (pixIn[coll+((j)*3)+2] * kernel[7]) + (pixIn[collp1+((j+1)*3)+2] * kernel[8]));
            
        }
        
    }
    
    return pixOut;

}




