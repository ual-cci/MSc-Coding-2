# Coding 2 : Advanced Frameworks

## 2019-2020

Professor Mick Grierson

# Week 1 - Introduction to C++

This week we will be learning some fundamentals of C++. We won't be trying to become the world's greatest C++ programmers in one day. Instead, we'll be learning the simplest possible subset of C++ approaches that we will need in order to get things done.

C++ is about the most complex language there is. It's also probably the best language you can master in terms of speed, power and flexibility. However, you can do almost everything you need to do in C++ by following a basic C-style coding approach that is common in lots of languages including JavaScript, and GLSL, which you will know reasonably well by now. If you take this approach, then it's simply a matter of learning a couple of fundamentals, and then slowly developing your vocabulary over time.

Fundamentally, the rule of thumb here is don't try to understand everything all at once - just focus on the essentials, and worry about the complexities once you feel confident with the basics.

## What we will cover this session

- Getting up and running with an Integrated Development Environment
- Understanding the basics of working with C++ as a language

This is a **CRASH COURSE** but should not be too hard given how much time we have spent learning JavaScript and GLSL, which have lots of similarities. 

If you want a nice reference for today's session, you should of course be looking here:

https://www.w3schools.com/cpp/default.asp

The things I'll be introducting you today are as follows:

- main.cpp
- #include
- printing to the console
- data types
- conditionals
- loops
- functions
- preprocessing and compilation
- C++ objects / classes
- .h (hpp) .cpp pairs
- basic macros
- declaring and defining a class
- including and using classes in a project


# Part One

## You need to get set up with an Integrated Development Environment (IDE).

There are a couple of options.

- Xcode (Download from the macOS App store)

The current version of Xcode will require you to use the most recent macOS operating system. If you really don't want to update your computer, you can sign up for a free apple developer account and download a version that works on your operating system by exploring the available links here: 

https://developer.apple.com/download/more/

- MS Visual Studio (Download from the visual studio website here

- https://visualstudio.microsoft.com/

This is what you should use if you're on windows.

The current version of Visual Studio claims to allow you to compile C++ code on macOS, which is technically true, but it's not as easy to do this as you might think.

## Linux

You can do everything you need to on the command line using GCC, G++ and MAKE. We will be exploring this later in the course but just make sure your linux distribution has the latest GCC and everything will be fine. 

## Why do I need an IDE?

- OK so the real answer to this question is, you don't really need it. 
- But it certainly makes life easier.

- A very basic IDE for C++ usually comprises a text editor, hinting / linting, a preprocessor, a compiler and debugging tools.
- Let's talk a little bit about each of these so you're all clear what they can do for you. Some of you will know this stuff, but just in case, let's remind ourselves.

* Linting is where a program can analyse your code and spot where it's going to fail.
* Hinting is where the idea tells you about errors and offer solutions
- You will have noticed these features on mimicproject.com and elsewhere
* The Preprocessor takes all the files in your project and sticks them together in to one big file which it then passes to the compiler
- You can give the preprocessor some 'directives', i.e. actions, like including other files such as standard libraries for maths, logging, or whatever.
* The compiler turns your code into binary form, and pulls off lots of tricks on the way.
- The more time you spend working with C++, the more you will care about these tricks. All you need to know is that this is how you create a program that you can run.

- You can of course use any text editor, and any compiler without using an IDE. It's totally your call. However, it will make life harder for you if you're trying to understand various frameworks, as these will expect you to be using an IDE such as those already mentioned.

# Part Two 

SO what are these things?

- main.cpp

main.cpp is the most important file in your project. 
If main.cpp doesn't exist or contains errors, your program won't compile - it's the first file that the compiler will go looking for (more on this later).

However, it's also simultaneously not that important. Most beginner programmers use main.cpp to do everything. This is fine. As you get more advanced, you might start to pass control over to other files or objects as part of your program structure. 

- #include

This is a preprocessor directive which is used to load a class, or bunch of classes, or library (such as a standard library). C++ has lots of standard libraries such as iostream which allows you to get stuff in and out of your program. You can think of it as an equivalent to adding a script with a script tag, or using an import statement in JavaScript.  

- namespaces

Namespaces are ways of separating standard functions into groups, and prevents functions with the same name from clashing. It's not common for programmers to make their own namespaces. There are lots of commonly used ones, the most important being the standard namespace. If you want to use lots of standard features, you can write 'using namespace std'. Some people will tell you never to do this, and just to make sure you never have two things with the same name, or any name that might be being used by something you need. This is actually **pretty good advice**.

- printing to the console

In C++ the most common way to print to the console is by using 'cout'. 'cout' is part of the standard library and is in the standard namespace, and has a bit of a strange syntax which we're going to look at later. If you are using the standard namespace you can just write 'cout'. If not, you need to prefix it with std::, which is shorthand for the standard namespace. This is what we're going to do most of the time.

- data types

OK so in JavaScript world, we only have var, let and const, which can be more or less anything, including floating point data, objects with lots of data, arrays or whatever. 

In C++ this is not the case. You need to specify which type of data your variable is going to hold, just like in GLSL. I love this. 

Types of data include int, short, char, string, float, double, long, long double. Here's a useful table to show you the difference.

![data types](https://github.com/ual-cci/MSc-Coding-2/blob/master/types.png)

- conditionals

You know what these are!

- loops

You know what these are too!

- functions

And these!

- C++ objects / classes

You also know what these are. We've used them a lot in JavaScript, and these days this is very similar to how they exist in C++. But some of you might not have made your own much. However, they are super easy and we're going to go through them. 

- .h (hpp) .cpp pairs

Now like most things in C++, I could talk about this for a long time, but the method I am going to teach you is an approved method for structuring and adding files that contain your own objects in ways that make it very easy for other people to understand and re-use your code. We'll go through this in the lecture, and 

- including and using classes in a project

This can be tricky if your compiler can't find your files. Sometimes, your compiler can't find your files, even if they are in your project. This means you need to know how to specifically tell the compiler where to find your files. We'll discuss this in more detail next week as it will come up a lot. Once you understand the problem, it will be easy enough for you to solve it!

- basic macros

Macros allow you to define things at a very high level, including constants, and even functions. They are messages directly to the compiler which means they can execute in ways that are compiler specific, for example you can use a macro to define code that is only relevant if you're on windows, or specifically for mobile platforms. You can also just use them to define PI if you want. I'll show you some examples in the lecture 

# Part Three : Practical Lecture

In the lecture, I'll talk you through the above in detail, providing practical code examples of each element where appropriate. In general, this is mainly about translating what you know from working in JavaScript and C into C++, and it's fairly straightforward. More details in the lecture!

# Homework

All you need to do in the homework is copy what I have done in the lecture

- Download and set up an IDE on your local machine. 
- Create a test project and design a simple program that prints a sequence of 10 values using a function.
- Create a new .cpp file and header (.hpp). Use this to make a new class of object, and then use this class in your main program. 
- Refer throughout to the C++ tutorial on w3c schools - and consider reading in full. It's well written, shouldn't take long and most of it you will already know : https://www.w3schools.com/cpp/ 


## OpenFrameworks

Next week, we're going to take a look at openFrameworks, which provides lots of functionality for you to explore whilst you settle in to your new C++ chops.

openframeworks.cc
