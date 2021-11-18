# Coding 2 : Advanced Frameworks

# Week 9 : More about C++ Objects
## 2020-2021

Professor Mick Grierson

## Introduction

This is the final lesson in advanced frameworks, and by now you should all have a good understanding of the various platforms and frameworks you can use to make creative computing projects that feature interactive sounds, images, 3D graphics, web platforms, machine learning, AI and embedded devices. You should also have a clear picture of why, how and when you might choose one framework over another. 

Let's think about some theoretical examples and consider what frameworks we should probably choose.

### You want to make a real-time interactive installation with 2D or 3D computer graphics and sound, potentially using hardware sensors.

- You should probably do this in C++, possibly with openFrameworks. You could do it in Unity but remember, Unity is not the best platform for integrating real-time sensors, and isn't a good platform for sound due to its buffer implementation (it's targetted for plaback of sound effects). You could also choose JavaScript, but this won't be as performant as C++, but you would need to negotiate the sensor situation depending on the browser you are using.

### You want to create an online, interactive networked environment where people in different places can interact and respond to each other.

- You should probablly do this in JavaScript. You could do it in Python but it would be harder, and there would not be much benefit. You could also do this in unity if it's a simple 2D or 3D game.

### You want to build audio or video processing software for other artists

- Do this in C++. You can build great sound toys in JavaScript, but for anything serious, you need to hit the metal. For audio plugins, Juce is fine and very simple to use once you've tried openFrameworks.

### You want to create new artworks using generative deep learning

- You need to do this in Python.

### You want to create a device that can use machine learning

- You need to use an embedded arm device that is capable of holding reasonably sized models in memory. Consider something like a PI or similar

### You want to create a game or interactive VR experience

- You can do this in Unity and it will be great. For better performance, Unreal is also good. Or you can just DIY in openGL the way I taught you. It's not hard.

### You want to scrape data off the internet and process it as part of a project

- You need to do this in Python, possibly using BS4 and/or scrapey and gensim for processing.

### You want to create an internet of things device of some kind.

- Raspi zero.

## In-class assignment submission.

## Instructions - submit only 4 in-class exercises!

- Choose what you consider to be your 4 best in-class exercises or homeworks that you have completed as part of Coding 2.
- Best if you use git, and follow the instructions on moodle!
- Submit them in CODE format with an associated README file (one README per exercise), and any associated output image files. You can submit .cpp + .hpp files, iPython notebooks, any other code in text form, and example PNG/JPEGS (images in any format).

Here are some ideas based on the in-class exercises and homeworks you were asked to complete. Of course, you should have spent some of your own time on these after each class, and so hopefully it won't take you too long to put the submission together. Also, it's fine if you worked with other people on these but just remember to make sure you are clear about what it is you did.
 
 # Lecture
 
 ## C++ Objects - Encapsulation, inheritance and polymorphism.
 
 - Today we are going to look at more advanced Object Orientation approaches.
 
 - Specifically we are going to look at how we can inherit properties from another class by treating it as a parent class
 -  We'll also look at polymorphism and what this really means, which frankly is not all that much
 - We will then look at Access specifiers (public, private, protected), and how we use encapsulation with them.
 
 
## But First
- Let's revise class structure so that we know what we're doing. 
- In order to do this, I'm going to put together one of the examples I gave you a few weeks ago, and that I hope some of you have taken the time to explore as it's a lot of fun, and a good example of how a class can be useful

## Let's look at a simple artificial life example

- In this example, we create a flock of virtual birds
- This is an algorithm that is primarily based on the work of Craig Reynolds    
https://www.youtube.com/watch?v=86iQiV3-3IA - How does this work?

## How does this work
- Each 'boid' is an instance of the same class
- These are all sitting in an array, doing whatever they do
- They have simple set of instructions that governs there behaviour

## Separation, Cohesion and Alignment
- There are three basic functions - separation, cohesion and alignment
- Separation :  if a boid gets to within a certain threshold of another boid, move away somehow. So perhaps you can get the unit vector and use this to send it in the opposite direction
- Cohesion : to prevent a boid getting too far away from all the other boids, move towards the centre of mass of all boids
- Alignment : Steer towards the average heading of all boids

## Where did the boids go?

- To prevent the boids flying offscreen, you can one of a few things
- You can check to see if the current position of each boid is beyond the visible frame, and if so, multiply their direction vector by -1. This inverts the direction, just like we did with the bouncing ball example in week 1
- You could also choose to send subtract the current width and height if they go offscreen. So if they go off the top, they will appear at the bottom and keep going...

## Building on an existing example

- Let's take a look at a boids example and see how it works. This is the header file for the code I gave you a few weeks ago.

```#ifndef _BOID
#define _BOID
#include <vector>
#include "ofMain.h"

class Boid
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
private:    
    ofVec3f position;
    ofVec3f velocity;
    
    float separationWeight;
    float cohesionWeight;
    float alignmentWeight;
    
    float separationThreshold;
    float neighbourhoodSize;
    
    ofVec3f separation(std::vector<Boid *> &otherBoids);
    ofVec3f cohesion(std::vector<Boid *> &otherBoids);
    ofVec3f alignment(std::vector<Boid *> &otherBoids);
    
// all the methods and variables after the
// public keyword can only be used by anyone
public:    
    Boid();
    Boid(ofVec3f &pos, ofVec3f &vel);
    
    ~Boid();
    
    ofVec3f getPosition();
    ofVec3f getVelocity();
    
    
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
    
    void update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max);
    
    void walls(ofVec3f &min, ofVec3f &max);
    
    void draw();
};

#endif
```
```/*
*  boid.cpp
*  boids
*
*  Created by Marco Gillies on 05/10/2010.
*  Copyright 2010 Goldsmiths, University of London. All rights reserved.
*
*/

#include "boid.h"
#include "ofMain.h"

Boid::Boid()
{
   separationWeight = 1.0f;
   cohesionWeight = 0.2f;
   alignmentWeight = 0.1f;
   
   separationThreshold = 15;
   neighbourhoodSize = 100;
   
   position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
   velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
}

Boid::Boid(ofVec3f &pos, ofVec3f &vel)
{
   separationWeight = 1.0f;
   cohesionWeight = 0.2f;
   alignmentWeight = 0.1f;
   
   separationThreshold = 15;
   neighbourhoodSize = 100;
   
   position = pos;
   velocity = vel;
}

Boid::~Boid()
{
   
}

float Boid::getSeparationWeight()
{
   return separationWeight;
}
float Boid::getCohesionWeight()
{
   return cohesionWeight;
}

float Boid::getAlignmentWeight()
{
   return alignmentWeight;
}


float Boid::getSeparationThreshold()
{
   return separationThreshold;
}

float Boid::getNeighbourhoodSize()
{
   return neighbourhoodSize;
}


void Boid::setSeparationWeight(float f)
{
   separationWeight = f;
}
void Boid::setCohesionWeight(float f)
{
   cohesionWeight = f;
}

void Boid::setAlignmentWeight(float f)
{
   alignmentWeight = f;
}


void Boid::setSeparationThreshold(float f)
{
   separationThreshold = f;
}

void Boid::setNeighbourhoodSize(float f)
{
   neighbourhoodSize = f;
}


ofVec3f Boid::getPosition()
{
   return position;
}

ofVec3f Boid::getVelocity()
{
   return velocity;
}

ofVec3f Boid::separation(std::vector<Boid *> &otherBoids)
{
   // finds the first collision and avoids that
   // should probably find the nearest one
   // can you figure out how to do that?
   for (int i = 0; i < otherBoids.size(); i++)
   {    
       if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
       {
           ofVec3f v = position -  otherBoids[i]->getPosition();
           v.normalize();
           return v;
       }
   }
}

ofVec3f Boid::cohesion(std::vector<Boid *> &otherBoids)
{
   ofVec3f average(0,0,0);
   int count = 0;
   for (int i = 0; i < otherBoids.size(); i++)
   {
       if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
       {
           average += otherBoids[i]->getPosition();
           count += 1;
       }
   }
   average /= count;
   ofVec3f v =  average - position;
   v.normalize();
   return v;
}

ofVec3f Boid::alignment(std::vector<Boid *> &otherBoids)
{
   ofVec3f average(0,0,0);
   int count = 0;
   for (int i = 0; i < otherBoids.size(); i++)
   {
       if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
       {
           average += otherBoids[i]->getVelocity();
           count += 1;
       }
   }
   average /= count;
   ofVec3f v =  average - velocity;
   v.normalize();
   return v;
}

void Boid::update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max)
{
   velocity += separationWeight*separation(otherBoids);
   velocity += cohesionWeight*cohesion(otherBoids);
   velocity += alignmentWeight*alignment(otherBoids);
   
   walls(min, max);
   position += velocity;
}

void Boid::walls(ofVec3f &min, ofVec3f &max)
{
   if (position.x < min.x){
       position.x = min.x;
       velocity.x *= -1;
   } else if (position.x > max.x){
       position.x = max.x;
       velocity.x *= -1;
   }
   
   if (position.y < min.y){
       position.y = min.y;
       velocity.y *= -1;
   } else if (position.y > max.y){
       position.y = max.y;
       velocity.y *= -1;
   }
   
   
}

void Boid::draw()
{
   ofSetColor(0, 255, 255);
   ofCircle(position.x, position.y, 5);
}
```
## Inheritance
- One useful feature of C++ objects is that we can create objects substantially based on other objects
- We can treat any class as a bass class. This means we don't need to copy all the code from one class to another. Some people like to work this way as it means you write less code.
- However,  it can also make your code harder to understand as many people can't be bothered to check how the base class actually works, and this often breaks things.
- But don't worry about this. Just remember, that in your own projects, it will definitely save you time to only write certain code once.
- A simple example is in games, where your different agents (e.g. game characters) all need to move around a game world in the same way.
- In that case, it's great to have a class called 'character', and then inherit a hole bunch of code for each character.
- like this ```class myCharacter : public character```
- In this case, myCharacter is a derived (child) class, and will inherit all the code from the base (parent) class 'character'.
- You can inherit from more than one class by listing your classes, separated by commas
- ```class myCharacter : public character, public rainbow```
- So this time, this character also has all the propertyies of a rainbow :-)
- You can inherit from a base class that is derived from another class :-)

## Polymorphism
- Polymorphism is super easy to understand
- All it means is that if you have a function in your base (parent) class,  you can have it behave differently in your derived (child) class. 
- For example, this means your characters can all inherit a 'playSound()' function from your base class, but you can make them play different sounds if you like
- Of course, this whole process calls in to question the entire reason behind inheriting functions to make code more reusable, but don't think about that. No, seriously, it's not worth bringing it up. Nobody wants to hear that. Nor do they want to hear about how it's possibly pointless because of virtual functions. Just leave it ok?

## Access Specifiers
- Previously I asked you to just make everything public, because otherwise you wouldn't have been able to call any of your member functions or variables from outside your class.  
- In general, this is fine when you're starting out. However, it's considered insecure.
- The problem is that, as I demonstrated previously, when you try to access a variable that is private **outside the class**, you get an error.
- This would also happen if you inherit something private.
- To get round this, it's usual to use something called 'encapsulation'.
- All this means is you write a public function that allows you to set or get the value of a private variable. e.g. ```getMyPrivateVar() { return myPrivateVar; }```
- Hmmm. 
- Hmmmm.
- You can also declare something as 'protected'. This means you can access it from a derived class. 

## Exercise 1 : Inheritance and polymorphism

- Working in groups, get the boids project up and running
- Create a new derived (child) class based on the boids class. 
- Using the smallest amount of code you can, change the appearance of the new class
- Now create a new vector of your new boids in the project

## Exercise 2 : More complex inheritance

- Working in groups or on your own, try to get your two types of boids to pay attention to each other.
- Keep them as two separate flocks, but make it so that each group stays away from each other!

 

