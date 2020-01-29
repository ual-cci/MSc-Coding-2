#include "ofApp.h"

// This example uses pure openGL (mostly) to create a procedural sphere, and light it by computing the correct surface normals.

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableDepthTest();
    
    dim=30;
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
        
        for (int j = 0; j < dim ; j++ ) {
            
            // ...create the next point in the circle at the current size s, at the current depth z
            
            ofVec3f point;
            
            point.set(cos(spacing * j) * s,sin(spacing * j) * s,z);
            
            points.push_back(point);

        }
    }

    cout << "done";

    // this just prints out all the vertices.
    for (int i = 0; i < points.size(); i++) {
        
        cout << points[i].x << " " << points[i].y << " " << points[i].z << endl;
        
    }

    
    //We are using ofCamera, which sets up a projection matrix like the ones we have built by hand.
    //Here we can set the clipping planes
    //And also the camera position
    //If we wanted we could adjust the FOV and a bunch of other stuff
    
    
    cam.setNearClip(1);
    cam.setFarClip(-100);
    cam.setPosition(0,0,10);
    
    // This turns on the lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    // This generates a bunch of arrays that we can pass in as lighting parameters
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
    GLfloat specularLight[] = { 0.15f, 0.15f, 0.15f, 1.0f };
//    GLfloat position[] = { -1.5f, 1.0f, -4.0f, 1.0f };
    
    // These fuctions define the characteristics of our light, GL_LIGHT0 - remember there are 8 lights
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
//    glLightfv(GL_LIGHT0, GL_POSITION, position);
    
    // This turns on color tracking. Might be on by default in openFrameworks
    glEnable(GL_COLOR_MATERIAL);
    // This sets the material properties. Important for lighting.
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    
    //Again, I think this is the default mode in OF. But if you aren't using OF you need to do this manually
    
    glShadeModel(GL_SMOOTH); // Can also be flat. When flat, the last colour specified for a triangle is the colour of the triangle

}


//--------------------------------------------------------------
void ofApp::update(){
    
    
}

//--------------------------------------------------------------

ofVec3f ofApp::normal(std::vector<ofVec3f> tri) {
    
    //Each face in the geometry needs to have a normal vector perpendicular to the face.
    //This is computed by getting the cross product of two points along the surface, a and b.
    
    ofVec3f a, b, normal;
    
    // We need to work out what a and b are
    // using CCW
    
    // a
    a.x = tri[0].x - tri[1].x;
    a.y = tri[0].y - tri[1].y;
    a.z = tri[0].z - tri[1].z;
    
    // b
    b.x = tri[1].x - tri[2].x;
    b.y = tri[1].y - tri[2].y;
    b.z = tri[1].z - tri[2].z;
    
    // This next bit of code does the cross product
    normal.x = (a.y * b.z) - (a.z * b.y);
    normal.y = (a.z * b.x) - (a.x * b.z);
    normal.z = (a.x * b.y) - (a.y * b.x);
    
    // now we have to normalise - this is basically the same as getting a unit vector.
    // we divide each element of the vector by its magnitude.
    // we should do it by hand but to save time I'm just calling a built in function

    return normal.normalize();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0);

    // cam gives us proper openGL world coordinates, like proper openGL
    cam.begin();

    // We're rotating using OF, because OFs projection matrix is a bit screwy if we use the native openGL method.
    
    ofRotateY(ofGetElapsedTimeMillis()/20);

//    glColor3f(0.0f, 0.0f, 1.0f); // blue
//    glBegin(GL_TRIANGLES);
//    glVertex3f(-1.0f, 0.0f, 0.0f);
//    glVertex3f(0.0f, -1.0f, 0.0f);
//    glVertex3f(1.0f, 0.0f, 0.0f);
//    glEnd();

// We're going to draw some triangles
    
    glBegin(GL_TRIANGLES);
    
// This loop takes a bunch of vertices and correctly draws them as a series of triangles.
    
    for (int i = dim; i < points.size(); i++) {

        //calculate the normal
        
        //get the triangle
        std::vector<ofVec3f> triangle;
        ofVec3f vec;
        vec.set(points[i].x, points[i].y, points[i].z);
        triangle.push_back(vec);
        vec.set(points[i-1].x, points[i-1].y, points[i-1].z);
        triangle.push_back(vec);
        vec.set(points[i-dim].x, points[i-dim].y, points[i-dim].z);
        triangle.push_back(vec);
        
        //Get the normal for this triangle
        vec = ofApp::normal(triangle);

        //set the normal.
        glNormal3f(vec.x, vec.y, vec.z);
        //draw the triangle
        glVertex3f(points[i].x, points[i].y, points[i].z);
        glVertex3f(points[i-1].x, points[i-1].y, points[i-1].z);
        glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);


      // then the next pass of triangle
        std::vector<ofVec3f> triangle2;

        if (dim >1) {
        
        vec.set(points[i-dim-1].x, points[i-dim-1].y, points[i-dim-1].z);
        triangle2.push_back(vec);
            
        } else {
            
        vec.set(points[i-dim].x, points[i-dim].y, points[i-dim].z);
        triangle2.push_back(vec);
            
        }
            
        vec.set(points[i-dim].x, points[i-dim].y, points[i-dim].z);
        triangle2.push_back(vec);
        vec.set(points[i-1].x, points[i-1].y, points[i-1].z);
        triangle2.push_back(vec);
        
        vec = ofApp::normal(triangle2);
        
        glNormal3f(vec.x, vec.y, vec.z);
        glVertex3f(points[i-dim-1].x, points[i-dim-1].y, points[i-dim-1].z);
        glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);
        glVertex3f(points[i-1].x, points[i-1].y, points[i-1].z);
        
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

    //move the light using the mouse.
    GLfloat position[] = { static_cast<GLfloat>((float) ofGetWidth()-mouseX), static_cast<GLfloat>((float) mouseY), 100.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, position);

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
