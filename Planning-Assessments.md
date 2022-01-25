# Coding 2 : Advanced Frameworks

# Assessment : 
## 2020-2021

Professor Mick Grierson

## Introduction

By now you should all have a good understanding of the various platforms and frameworks you can use to make creative computing projects that feature interactive sounds, images, 3D graphics, web platforms, machine learning, AI and embedded devices. You should also have a clear picture of why, how and when you might choose one framework over another. 

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
 
