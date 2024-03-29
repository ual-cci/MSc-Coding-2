# Coding 2 : Advanced Frameworks

# Week 8: Using deep neural networks to classify and generate images

Professor Mick Grierson

## Part one : Recap

Last session we focussed on trying to understand what a simple machine learning system was, and how you could build a very basic one. We learned a lot of things. Some of the most important things we went through were as follows:

- We tend to use Neural Networks to try to transform data without us having to change parameters manually.
- For example, we might want to build a system that can automatically change input values in order to meet some condition, e.g. making an output value get higher.
- We can do this by measuring the distance between the output and the desired output, then passing a value derived from this distance back through the network's parameters.

- This works with single input systems, but is even more powerful if we can have more inputs, so we chain them together
- We do all this by adjusting the inputs by a small amount, and getting the derivative, which is the difference between input and output for different parameters of the system, scaled by a small amount (we move slowly towards the target..)

![Gradient Descent](https://upload.wikimedia.org/wikipedia/commons/a/a3/Gradient_descent.gif)

- When we get all the derivatives together, we get a gradient. This can be thought of as containing direction.

- We use the gradient to adjust the parameters of the network. The difference propagates back through the network.
- Input data flows forward through nodes in a graph - this is the forward pass
- We calculate the gradient and use this to adjust the network parameters - this is the backward pass.
- We call this "Back Propagation."
- We can add and squash the output of a bunch of Neurons together with an activation function, such as a sigmoid.
- We can use this to turn a Neuron into a smoothed-switch with a maximum of 1 and a minimum of 0.

# Last week's exercises

- I asked you to go through an introductory notebook that shows you how to do basic signal processing on a batch of images.
- I then asked you to try to do some type of transformation on the image dataset (something you devised yourself).
- I then asked you to modify the notebook so that you ran the process on a totally different batch of images that you sourced yourself.
- Getting a dataset is one of the most important, and also simultaneously most annoying aspects of machine learning.



## This session

- Today we are going to do three things
- First, we are going to look at how large ensembles of neurons can classify an image, and how we can structure such systems
- Second, we are going to look at a few interesting Creative uses of these types of systems
- Finally, we're going to learn more by exploring a Jupyter notebook from Parag Mital's Creative Applications of Deep Learning course, which allows us to build simple networks for the first time.

# Part Two - Using deep learning to classify images.

- Take a look at this demo here from Terence Broad:
- https://blog.terencebroad.com/archive/convnetvis/vis.html
- This is a simple visualisation of a real CNN classifying a handwritten image
- The input image flows through layers of a trained network
- The 'paths' through the different layers show how different aspects of the image are classified by different layers by the network.
- Let's actually explore a simple program that actually trains this system.

# Exercise 1

In groups we're going to do an exercise looking at this MNIST notebook here:

https://github.com/ual-cci/MSc-Coding-2/blob/master/Week-7-notebooks/Week-7-MNIST.ipynb

Try to understand what each line is doing with reference to what we described in the lecture. Remember, this is creating a large network layer by layer.

## Exercise 2 : Image Fun with tensorflow

- You will have noticed that you can run the MNIST training demo on Google's colab platform.

This is useful if you can't get notebooks to work, or are having issues using tensorflow.

https://colab.research.google.com/notebooks/intro.ipynb

- Colab can be useful if you are wanting to try things out quickly
- However, it's not necessarily very good if you are trying to do complex things that require long periods of training
- But you really should try it out!

Lots of people are very excited about using deep learning to generate images.
Two popular techniques are style transfer and using generative image models, such as Generative Adversarial Networks (GANs).
- Have a look at the following demos from Google on Style Transfer and GANs. You will be learning more about these next term so these are just to whet your appetite:
- You will need to install tensorflow hub to use these demos. From the terminal:
```pip install tensorflow_hub```
- https://github.com/ual-cci/MSc-Coding-2/blob/master/Week-7-notebooks/tf2_arbitrary_image_stylization.ipynb
- https://github.com/ual-cci/MSc-Coding-2/blob/master/Week-7-notebooks/tf_hub_generative_image_module.ipynb
- Use your own images to create your own style transfer and GAN outputs if you can.
- Check out some of the other examples:
https://www.tensorflow.org/hub/tutorials

# Part Three : Lecture 

## How neural networks are structured:

- Different NN systems have different structures
- There are many different features these structures
- One good example of such a system is a what is called
- a "Fully connected network"

## Fully Connected networks
- It's super easy to understand a fully connected network
- All this means is that every node in one layer is connected to every node in the next layer
- This makes a massive web of connections

## What are the layers doing?
- We start with a bunch of inputs at the first layer, one for each pixel, for example.
- We might want to downsample the image first, and convert it to greyscale. We don't need colour to work out what number it is.
- Then we want to have a bunch of outputs. In the example of the MNIST handwritten digit classification, there are 10 outputs for 10 numbers (0-9).
- Then, we have what are called 'hidden layers' in-between.
- They are 'hidden' because we don't monitor their inputs or outputs directly in normal circumstances.

## Seriously, what do the layers do?

- The input layers and hidden layers divide up the task of working out what the image representation needs to be.
- They do this literally by adding up the values from different parts of the image.
- This is one reason why the dataset is normalised in terms of size and orientation.
- However this isn't always necessary. Just mostly necessary!

## No but really...
- First layers might work out some of the edges
- The hidden layers then spread out the job of representing different aspects of the image input. These are basically different blocks of pixels - just like in Terence's demo.
- This leads to the output layer receiving a collection of activiations which it can use to determine what the input image is.

## Weights, Biases, Activation
- A trained network is really just a really big grid of weights (values).
- These weights have been arrived at through the training process, and just tell you what the values of the pixels are for a particular part of the image
- The training process simply compares the outputs to the input, works out the difference, and propagates this back to adjust the weights a tiny amount in the direction represented by the gradient.
- Also, you might want to make it harder for the network to get activated. This is useful to help make sure the nodes in the network only activate when there's a strong response.
- To do this, you can add a bias - usually a negative number - before you pass the output through a sigmoid or rectified linear unit activation function (RELU)
- RELU is loads better than sigmoid because it's simple.
- RELU is just converts the neuron's combined sum of inputs by weights, with bias, into a diagonal line from zero. Parag mentions it in his second week session, further down this page.

## SO...

- Each neuron takes all the inputs from the previous layer
- It then spits out a number between 0 and 1 that is a combination of all the high or low activation in the prior layer pushed in to a function.
- This is all just a simple function, that is part of a larger function - the NN is just a function approximator made up of lots of other functions.
- Here is a surprisingly good explanation that is pretty easy to grasp:

https://www.youtube.com/watch?v=aircAruvnKk

# Homework
- Now that we've looked in detail at the whole process
- You should be able to tackle this notebook from Parag Mital. It shows you how to design a Neural Network to generate a new image from scratch based on a separate image. It also reinforces some of the learning we've been through and adds further detail.

https://github.com/ual-cci/MSc-Coding-2/blob/master/Week-7-notebooks/Week-7-CADL-Lecture2.ipynb

- 
