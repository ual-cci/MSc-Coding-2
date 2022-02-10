# Coding 2 : Advanced Frameworks

Professor Mick Grierson

## Week 5 - Introduction to Python

Over the past three months, I've introduced you primarily only to C-style programming approaches, and to C-style syntax. This has allowed us to get a strong grasp of the five fundamentals of programming - Variables, Conditionals, Loops, Functions, objects - using a syntax that you can more or less stick with.

Sure, we had to move from var to let, and then to float, int, and then most recently a whole bunch of new types of variables (float, int, vec, long, double, short, bool). But throughout, we stuck with C-style syntax for conditionals (if, else), for loops, function definitions with arguments (across GLSL, C and C++), and then learned the class syntax in C++.

This approach has worked very well for us so far. It's taken us from JavaScript all the way to low level languages, and we've even thought a bit about memory management. This is all great for performance hungry interactive applications.

However, some types of computing can be challenging and slow to develop in low-level languages using C-Style syntax. In particular, if you are handling lots of text data, or doing other database-style work, C++ code can take longer to write than other, more flexible, less complex languages.

This is where Python comes in. Python is great for running computations where real-time performance doesn't really matter. For example, if you're trying to analyse and process large amounts of data - be it sounds, images, video, text, or interact with data from various data sources (e.g. websites), produce graphs, or train machine learning models, it can take a lot less time if you do it in Python. So with this in mind, we're going to learn how to program in Python. This is going to be a bit tricky, because it is actually very very different to any of the other languages we've used. Comments are different, Syntax is totally different. Scope is weird. But it's going to be OK.

But don't try to make interactive systems with video, graphics, audio and live interfaces in Python. It's a really terrible idea. Some people will tell you that it can be done. But they won't be able to tell you why you should, because there's no reason.

So let's get started.

## What we will cover this session

### Getting started using Python

- How to get Python. How to run Python. Different Python Versions. PIP.

Python is installed by default on macOS. It is a bit more tricky to install on windows. But it's not too difficult. The easiest way to get Python is to use Anaconda. This is what we're going to do. We can install more python software using something called pip. We can also use conda.

- Different ways of using Python - Using the terminal, using anaconda, using jupyter notebook.

- On the command line

You can use the terminal to launch Python and run simple tests. You can also save a series of python commands as a .py file and run it from the command line. You can also run a basic web server using python using SimpleHTTPServer (p2) or http.server (p3)

- Differences between Python 2 and Python 3

Print functions
xrange / range
string concatenation methods.

## Python programming basics.
* Printing to the console, using quotes, indentation / blocks, string concatenation
* variables : ints, floats, strings, lists, tuples (read-only lists), accessing data in lists, dictionaries
* Basic operators - luckily this stuff is all the same!
* conditionals, loops, functions
* for letter in 'Python': print 'Current Letter :', letter
* keywords, comments
* import

## Lecture slides !

https://github.com/ual-cci/MSc-Coding-2/blob/master/python-intro.pdf

## Exercise - The Python Challenge!

- The Python Challenge has been on the internet for decades.
- It's a really great way to learn Python.
- Work on your own or in groups to solve the first 5 parts of the Python Challenge.

http://www.pythonchallenge.com

## HOMEWORK

Working on your own, devise and create a simple riddle or puzzle inspired by the Python Challenge. You can:

- Hide some information in a section of text
- Or in an Image
- Or in some other form of data
- Then create a simple clue that can help someone else decode in Python.

Next week, we can share our python riddles!



