/*
 *  boid.h
 *  boids
 *
 *  Created by Marco Gillies on 05/10/2010.
 *  Copyright 2010 Goldsmiths, University of London. All rights reserved.
 *
 */

#ifndef _BOID
#define _BOID

// you use quotes "" for your own header files
#include "ofxVectorMath.h"
// and angle brackets <> for the build in header files
#include <vector>

class Boid
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
private:	
	ofxVec3f position;
	ofxVec3f velocity;
	
	float separationWeight;
	float cohesionWeight;
	float alignmentWeight;
	
	float separationThreshold;
	float neighbourhoodSize;
	
	ofxVec3f separation(std::vector<Boid *> &otherBoids);
	ofxVec3f cohesion(std::vector<Boid *> &otherBoids);
	ofxVec3f alignment(std::vector<Boid *> &otherBoids);
	
// all the methods and variables after the
// public keyword can only be used by anyone
public:	
	Boid();
	Boid(ofxVec3f &pos, ofxVec3f &vel);
	
	~Boid();
	
	ofxVec3f getPosition();
	ofxVec3f getVelocity();
	
	
	float getSeparationWeight();
	float getCohesionWeight();
	float getAlignmentWeight();
	
	float getSeparationThreshold();
	float getNeighbourhoodSize();
	
	void setSeparationWeight(float f);
	void setCohesionWeight(float f);
	void setAlignmentWeight(float f);
	
	void setSeparationThreshold(float f);
	void setNeighbourhoodSize(float f);
	
	void update(std::vector<Boid *> &otherBoids, ofxVec3f &min, ofxVec3f &max);
	
	void walls(ofxVec3f &min, ofxVec3f &max);
	
	void draw();
};




#endif _BOID