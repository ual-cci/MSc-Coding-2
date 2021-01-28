# Coding 2 : Advanced Frameworks

## 2019-2020

Professor Mick Grierson

## Week 2 - C++ and openFrameworks

This week we will be looking at openFrameworks, making sure we understand how to set it up, and exploring basic examples and concepts. We'll also be looking at some more complex examples, such as the Maximilian C++ library for audio, and in particular thinking about what pointers are and when we might consider using them.

openFrameworks has been around for a long time, and is a great way of creating C++ projects for media and computational arts. As a result, it's a standard Framework in industry for developing media work. It has a large community, some of whom are very active at CCI. There are comprehensive tutorials online, and a massive library of addons (some of which might not work, so be warned). But in general, if you are trying to do something in C++ and you don't want to deal with the hassle of setting up your own graphics, sound and interaction environment for prototyping, it's a great way to get started.

# REVIEW OF LAST SESSION :

Last week we looked at the basics of C++. Let's refresh our memory of what that included:

- How to get set up using an IDE like Xcode or Visual Studio.
You should all now have an IDE setup and working on your system. This is essential for this class, so if you haven't managed to do this, you need to spend as much time as you can doing this today. We will work together to help each other if and when there are problems!

- Preprocessing and compilation

We learned that the pre-processor has to copy and paste the contents of all the files in your C++ project in to one big file before it can build your program. To help it do that, we need to use preprocessor *directives* or instructions which tell it which files we want to use. Sometimes those files are standard libraries and functions (like <iostream> or <math.h>), and sometimes they are our own files (e.g. our own headers (*.h or *.hpp *and* their *.cpp partners - remember, they come in pairs), and we use #include statements to tell the preprocesser we want them. We also need to use directives (like #ifndef) to make sure that the preprocessor only copies each file in once, as it's very common for it to be included lots of times all over the place.
  
We also learned that the compiler takes the preprocessed output and converts it into machine code - a binary file that you can run - using methods that are totally specific to your processor family (e.g. Intel, ARM, etc.). We also learned that this makes super fast code that is lots of fun and hugely powerful, especially when you need quick access to large amounts of memory (like video).

- main.cpp

We learned that main.cpp is usually where our main function goes, and that without a main function, the compiler won't be able to build your binary. We also learned that you can just create an object here, and that this object can be your actual program. So main could be huge, or it could be really small depending on the structure of your program.

- printing to the console

We learned that these days, most people use std::cout to print to the console. There are other ways but whatever. 

- data types

We looked at how data types need to be specified. We also looked at typecasting (converting data from one type to another), and data truncation (when you lose 
information resolution as a result of converting / casting data from one type to another).

- Conditionals, Loops, Functions

This was basically super easy and you should be fairly comfortable with it. If not, practice.

- C++ objects / classes, declaring and defining a class in .h (hpp) .cpp pairs

We created some basic objects in C++. First we did this in main.cpp, then we moved this into a header file (.h / .hpp) and a .cpp file pair.

We learned that you *declare (say what they are)* the variables and functions for a class (the *member variables* and *member functions*) in the *header*, and *define (write the actual function code)* for the member functions in the *.cpp* file. 

We also learned that when you want to include files in your project, they need to be associated with your project target, and the compiler needs to be able to find them. This is going to come up as an issue for you at some point and you will be able to fix it so don't worry too much.

- We also looked at MACROS, which are ways of defining stuff at the top of a file. For example, we could #define PI 3.14159 and then PI would also mean that. We also looked at how 


# THIS SESSION

## PART ONE: INTRO

I'm going to talk you through downloading and using openFrameworks. There are some key things that you need to be aware of before you start so we're going to go through these first. 

- Getting openFrameworks

https://openframeworks.cc - download the latest release or grab the nightly build? 

- OF folder structure. Where is everything and why?

You need to know the structure of the openFrameworks folders. Let's take a look.

- build settings for your platform (SDKs, paths)

What on earth are Build settings?
How do I check the build settings?
What stuff is important?
How are paths and how do I check them?

- openFrameworks project structure (main, ofApp)

What is the structure of an OF APP? How do I make changes, add methods etc.? How can I keep things clean and tidy?

- Creating and using an empty project

Should I copy the example project, or use the project generator?

- Documentation and examples

So what can I do?

- Addons and how to use them

https://ofxaddons.com/categories

What on earth are addons? 

Good things and bad things about various ofxAddons contributions.  

- Useful examples based on last term's course material - image processing, fractals, custom geometry and shaders in OF


## PART TWO: WORKSHOP

Let's build creative software together!!!!!


## PART THREE: LECTURE

- Common mistakes in openFrameworks

Where everyone gets it wrong.

- ofxMaxim example 

How to use ofxMaxim in openFrameworks for creating sound and music systems. Good news, it's super easy. 

- Pointers and Arrays, the Stack and the Heap

What on earth are pointers and why should I know about them?

- address-of operators and dereference operators

- New and Delete, Malloc and Free, Reference Counting == no.

- How and why ofxMaxim uses pointers - a quick overview of the maxiSample object


# HOMEWORK : Porting a simple project from JavaScript to OF

Find a project from last term that you feel good about or want to do more work on. 
Pick a simple one unless you really fancy a challenge
Convert this project to openFrameworks.
There are lots of useful hints for how to do this here : https://github.com/ual-cci/MSc-Coding-2/tree/master/week2-more-examples
