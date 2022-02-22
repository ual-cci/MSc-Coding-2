
# Week 7 - What on earth is Machine Learning?

So - this week, we are going to start thinking about what machine learning is in very basic terms. You will be doing much more of this next term, but this session, particularly the lecture, is simply a way to get you thinking about some of the language, concepts and theoretical ideas at play. In the lecture, you'll learn what a tensor is and how you can use one - or lots. Also, there's an exercise to help ease you in to numpy arrays, which to be honest are largely similar constructs. Finally, there's a lecture inrtoducing the basics of Neural Networks, which defines some core concepts for you, including what a perceptron is, what gradients are, what back propogation is, and why these things matter. 

# Part One - what is tensorflow?

## Tensorflow
- Machine Learning framework
- Created by Google
- Used to design, build and train deep
- learning models

---
## Tensorflow
- Tensorflow is a Python library
- Optimised for Linear algebra
- Computes numerical computations via data flow graphs
---

## Tensorflow
- Data flow graphs are useful for Machine Learning
- Because we tend to think about large numerical computations in specific ways
- e.g. data flowing through mathematical operations
- edges -> nodes

---

## What is a tensor?
- A good way of thinking about a tensors is to think about a video files
- A video is a series of frames
- Each frame contains individual colour values
- A collection of frames can be thought of as a tensor

---

- Each individual colour value can be thought of as a scalar
- A group of colour values can be thought of as a vector
- For example, RGBA colour values make up a 4D vector (xyzw)
- A block of vectors can be thought of as a tensor

---

- The 'RANK' of a tensor can be thought of as how many blocks of vectors it has
- This is similar to numpy, where the number of dimensions is thought of as the 'rank'
- But to be perfectly honest the definition isn't that clear cut.
- For example, you can describe a scalar as a tensor with a rank of zero.

---
- It's far simpler to think of it like this:
- Tensors are data
- They can also be list of numbers - e.g. vectors, of any dimensionality (rank)
- They can also be blocks of multidimensional data, such as a bank of images, or a video.
- They can also be a scaler - e.g. a single value
- This can be confusing. But it's really not that complicated.
---

- So tensorflow essentially allows you to construct large arrays of numerical data
- It also allows you to process this data in large blocks
- It can do this using the CPU, the GPU, or even a TPU (tensor processing unit)
- But basically it's just a big bunch of multiplications and additions.

---
## Things to remember
- vectors have lots of properties that carry over to large numbers of dimensions
- Therefore, so do tensors
- You can normalise tensors (i.e. turn them in to a direction vector)
- You can get some idea how similar two tensors are by calculating the dot product
- You can also get the difference and distance between two tensors using euclidean distance (pythagoras)
- Or cosine distance
---
- We went through all these processes in 3 dimensions
- They are exactly the same in any number of dimensions.
- Tensorflow attempts to make it easier to do these kinds of operations quickly

---

# Part two : Workshop!

## There are two exercises you can do:

## Exercise 1 - More NUMPY

Numpy is one of those things you just need to get used to. In order to help you, I've created a notebook that shows you how to use Numpy to create images with expressions, exactly as we did last term, using the same algorithms. This should help you get your head round some of the unfamiliar stuff that we're going to tackle this session, particularly in Exercise 2!

https://github.com/ual-cci/MSc-Coding-2/blob/master/week5-notebooks/Pixel%20Pushing%20in%20Numpy.ipynb

Go through the notebook and try to create your own image using a custom expression of your own.

## Exercise 2: Getting datasets, processing images and introducing tensorflow
- Before we start building networks in Tensorflow and exploring what they can do, we should probably try and do something simple
- Like just processing some images !!!
- As an exercise, we are going to study the following notebook that you were asked to review as homework.
- https://github.com/ual-cci/MSc-Coding-2/blob/master/Week-6-Exercise-intro-to-image-data-and-tensorflow.ipynb
- Following this, you must make a version of the notebook with at least one major difference that you have introduced yourself. First, you must do some transformation on the image dataset that isn't included in the above document. If you manage to do this, your next task is to collect and process your own dataset instead of the one provided. 

## Useful resources:
https://easy-tensorflow.com/

https://towardsdatascience.com/pytorch-vs-tensorflow-spotting-the-difference-25c75777377b

# Part three : Lecture! 

## Programming Neural Nets by hand
- This next tutorial is based on Andrey Karparthy's NN tutorial.
- https://karpathy.github.io/neuralnets/
- He puts forward the idea that real values flow forward through simple systems
- Whilst gradients flow backward through them
- This is useful for understanding Back Propagation.
- Let's take a look.

```Python

# We start by creating a simple multiplication 'gate'
# This is used in the 'forward pass'
# All this means is that data flows forward through the network

def forwardMultiplyGate(x, y):
    return x * y

print (forwardMultiplyGate(-2, 3));

print ("we want to get a number bigger than -6 without changing the inputs ourselves. How do we do that?")

```
## Random Local Search
- In Neural Nets, we tweak the input values
- until we get closer to the result we are looking for
- We can use a random local search to do this
- we could do this randomly by changing x,y randomly by small amounts
- and keep track of what works best

```python
# Random Local Search
# -----------------

# but it's a rubbish idea.

import math
import random

x = -2
y = 3;

def forwardMultiplyGate(x, y):
    return x * y

tweak_amount = 0.01 # this is a bit like the learning rate
best_out = -10000000
best_x = x
best_y = y

for k in range(100): # 100 is the number of steps
    x_try = x + tweak_amount * (random.random() * 2 - 1) # tweak x a bit
    y_try = y + tweak_amount * (random.random() * 2 - 1) # tweak y a bit
    out = forwardMultiplyGate(x_try, y_try)
    if out > best_out:
        # best improvement yet! Keep track of the x and y
        best_out = out
        best_x = x_try
        best_y = y_try
        print (best_out)

print ("This works, but is not very efficient.")

```

## Numerical Gradient
- ------------------
- "The derivative can be thought of as a force on each input
- as we pull on the output to become higher."
- ------------------

- Instead of doing a random search,
- we're going to increase the inputs very slightly
- and check what happens to the output to see if it's what we expect
- The amount of change in the output is the DERIVATIVE

- Below, we add h - the tweak amount to x and y,
- Then we check check the difference between the output
- And the first output - this difference is
## the derivative.

```python

def forwardMultiplyGate(x, y):
    return x * y

x = -2
y = 3
out = forwardMultiplyGate(x, y) # -6
h = 0.0001; # This is the tweak amount. Some say it should be
# as small as possible but this is small enough

# compute derivative with respect to x
xph = x + h # -1.9999
out2 = forwardMultiplyGate(xph, y) # -5.9997
x_derivative = (out2 - out) / h; # 3.0 - we divide by h to normalise

# compute derivative with respect to y
yph = y + h # 3.0001
out3 = forwardMultiplyGate(x, yph) # -6.0002
y_derivative = (out3 - out) / h # -2.0 - we divide by h to normalise

print ("x_derivative =", x_derivative)
print ("y_derivative =", y_derivative)

# When we talk about all the inputs together with respect to output,
# We're actually talking about the GRADIENT
# not the indiviual derivatives

gradient = [x_derivative,y_derivative]

print ("The Gradient is", gradient)

# move towards the gradient by scaling it a little
# then moving towards it a bit
# this is the same as chasing an object

step_size = 0.01; # If this was big, it would work,
# BUT it might not work with more complex networks
x = x + (step_size * x_derivative); # x becomes -1.97
y = y + (step_size * y_derivative); # y becomes 2.98
out_new = forwardMultiplyGate(x, y) # -5.87! exciting.
print ("The New Output is", out_new)

```

## So what is the Gradient?
- The gradient is the direction of the steepest increase
- This means it's taking the inputs where they need to go
- To get the output closer to what we want
- This is exactly how we move towards objects in space
- Gradients flow backwards through networks

## A different approach

## ANALYTIC GRADIENT
- -------------------

- The numerical gradient is actually rubbish
- If we have lots of inputs
- it is dumb to calculate the gradient
- by evaluating all the inputs separately all the time

- Instead we're going to use the "analytic gradient"
- The trick here is that derivative of X actually turned out to be Y
- So why bother to calculate it at all?
- Just use Y, and the whole thing gets much simpler to compute
- As long as we can calculate a base case first, we can use it
- without having to do so over and over again.

```Python

x = -2
y = 3
out = forwardMultiplyGate(x, y)
x_gradient = y; # because it turns out the gradient of x is y.
y_gradient = x; # vice versa

step_size = 0.01;
x += step_size * x_gradient
y += step_size * y_gradient
out_new = forwardMultiplyGate(x, y)

print ("New Output =", out_new)
# In practice NN systems compute the numerical gradient and the analytical gradient

```
## No inputs though...
- In order to turn this simple system in to a complex one,
- We just need lots of these together
- But we also have to connect them up.
- In order for this to work, we need to add something extra
- We need to -add- as well as -multiply-

```Python

# a and b are just local variables, not inputs to the neuron
def forwardMultiplyGate(a, b):
    return a * b

def forwardAddGate(a, b):
    return a + b

def forwardCircuit(x,y,z):
    q = forwardAddGate(x, y)
    f = forwardMultiplyGate(q, z)
    return f

x = -2
y = 5
z = -4
f = forwardCircuit(x, y, z); # output is -12

# Now we add things together, and then multiply
print (f)

```
## BUT how do we calculate the gradient now?
- EASY - we only do it for the inputs we are multiplying.
- So everything else stays the same
- It just allows us to chain Neurons together.
- The derivative of the addition part is always 1

```python

# Let's set this up:
# initial conditions

def forwardMultiplyGate(a, b):
    return a * b

def forwardAddGate(a, b):
    return a + b

def forwardCircuit(x,y,z):
    q = forwardAddGate(x, y)
    f = forwardMultiplyGate(q, z)
    return f

x = -2
y = 5
z = -4
q = forwardAddGate(x, y) # q is 3
f = forwardMultiplyGate(q, z) # output is -12

print (f)

# gradient of the MULTIPLY gate with respect to its inputs
# wrt is short for "with respect to"
derivative_f_wrt_z = q # 3
derivative_f_wrt_q = z # -4

# derivative of the ADD gate with respect to its inputs
derivative_q_wrt_x = 1.0
derivative_q_wrt_y = 1.0

# chain rule
derivative_f_wrt_x = derivative_q_wrt_x * derivative_f_wrt_q # -4
derivative_f_wrt_y = derivative_q_wrt_y * derivative_f_wrt_q # -4

# final gradient, from above: [-4, -4, 3]
gradient_f_wrt_xyz = [derivative_f_wrt_x, derivative_f_wrt_y, derivative_f_wrt_z]

# let the inputs respond to the force/tug:
step_size = 0.01
x = x + step_size * derivative_f_wrt_x # -2.04
y = y + step_size * derivative_f_wrt_y # 4.96
z = z + step_size * derivative_f_wrt_z # -3.97

# Our circuit now better give higher output:
q = forwardAddGate(x, y) # q becomes 2.92
f = forwardMultiplyGate(q, z) # output is -11.59, up from -12!

print (f)

# let's check the derivatives with a numerical gradient check
# initial conditions
x = -2
y = 5
z = -4

# numerical gradient check
h = 0.0001;
x_derivative = (forwardCircuit(x+h,y,z) - forwardCircuit(x,y,z)) / h # -4
y_derivative = (forwardCircuit(x,y+h,z) - forwardCircuit(x,y,z)) / h # -4
z_derivative = (forwardCircuit(x,y,z+h) - forwardCircuit(x,y,z)) / h # 3

print (x_derivative,y_derivative,z_derivative)
print ("That's close enough!")

```

## Activation
- If the input to a node in a network is high enough
- We can say that it's activated
- But often the outputs are really high or really low.
- It's sometimes useful to squish the output with a function
- So that negative values tend towards zero
- And positive values tend towards 1.
- People use SIGMOID to do this.
- SIGMOID is an activation function

```python
# -----------
# Sigmoid Function - f = 1.0 / (1.0 + math.exp(-x))
# This function is often used as
# an activation function in Neural Networks


import numpy as np
import matplotlib.pyplot as plt

input_sig = np.arange(-10,10)
output_sig = np.zeros((20))

for val in input_sig:
    output_sig[val+10] = 1.0 / (1 + math.exp(-val))


plt.plot(output_sig)
plt.plot(input_sig * 0.1) # scaling the input just so we can compare
plt.show()

```
## Cue long discussion about how real neural nets work.
- SO - if you take the node we made
- And create a row of them
- And then create another row of them
- And then connect every node in the first row
- to every node in the second row
- Then update the values in each node
- based on all the derivatives - the gradient
- And squish the output with a sigmoid function
- Then you have a two layer network!


# No homework this week! Just work on your projects instead :-)
