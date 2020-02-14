# Coding 2 : Advanced Frameworks

## 2019-2020

Professor Mick Grierson

# Part One - Using Numpy to compute images

## Python Numpy Image Processing Tutorial
- You can use numpy arrays to do all the things we did in JavaScript with images
- I don't recommend you do this all the time, but doing it a bit can be instructive
- I've put together a simple tutorial to help you.

## Pixel pushing in numpy
- This is just to get you in to the way numpy works
-  It will be helpful for getting you up to speed
- Using Tensorflow or Pytorch without knowing numpy first is not great
- Some useful extra reading is available here:
- http://cs231n.github.io/python-numpy-tutorial/

## We can use matplotlib to draw images

```Python
from matplotlib import pyplot as plt

# We're going use numpy

import numpy as np

# math!
import math

# randomly initialise an image 10 * 10 pixels
my_array = np.random.random((10,10))

# Also use 'full' or 'ones' or 'zeros'
# y = np.zeros((10,10)) # also try 'full((10,10),0.5)' or 'ones'

# cmap sets the colourmap - https://matplotlib.org/examples/color/colormaps_reference.html
# cmap is ignored for datasets with rank of 3 or 4, as these are assumed to be RGB(a)
# interpolation is used when the number of pixels in the array
# is such that it can't be shown properly given the size of the plot
# you need to set the lower and upper limits with clim !!!

plt.imshow(my_array,  cmap='gray', clim=(0,1))
plt.show()

```
## This is interesting, but how would you go about just colouring one pixel?

```Python
myImage = np.zeros((10,10))

myImage[5,5]=1

plt.imshow(myImage, clim=(0,1),cmap="gray")
plt.show()

```
## Drawing a circle

```python

# This doesn't look great, but it is useful to do

# so numpy arrays are column major, not row major.
# So you need to do height first
myImage = np.zeros((240,320))

# This code is exactly the same as the the code frmo
TWO_PI = 3.14159 * 2
segments = 600
spacing = TWO_PI / segments
size = 40

for i in range(segments):
    x = math.cos(spacing * i) * size
    y = math.sin(spacing * i) * size
    myImage[math.floor(x) + 50, math.floor(y) + 50] = 1 # notice we need to floor the output to ints

plt.imshow(myImage, interpolation="bilinear", clim=(0,1),cmap="gray")
plt.show()

```

## Drawing a square

```python

myImage = np.zeros((240,320))

# This code is exactly the same as the the code from our JS and C++ examples
TWO_PI = 3.14159 * 2
segments = 600
spacing = TWO_PI * 2 / segments
size = 40
centre = 120

for i in range(240):
    for j in range(320):
        if abs(centre-i) < size and abs(centre-j) < size:
            myImage[i,j]=1

plt.imshow(myImage, clim=(0,1),cmap="gray")
plt.show()

```

## Using a distance field to draw a circle

```Python
myImage = np.zeros((240,320))

# This code is exactly the same as the the code from our JS and C++ examples

centre = 100
size = 50

for i in range(240):
    for j in range(320):
        x_dist = abs(centre-i)
        y_dist = abs(centre-j)
        dist = math.sqrt(x_dist * x_dist + y_dist * y_dist)
        if dist < size:
            myImage[i,j] = 1

plt.imshow(myImage, clim=(0,1),cmap="gray")
plt.imshow(myImage, interpolation="bilinear", clim=(0,1), cmap="gray")
plt.show()

```

## Using numpy to calculate distances in high dimensions
- This is actually a LOT slower than doing it by hand as above
- But is super useful if you are wanting to compute distances
- Particularly if your data has thousands of dimensions

```Python

# This is actually five times slower
# but it is easier to write if you are operating in high dimensions.

# you could experiment with many more dimensions. Try adding more...
positions=np.array([[30,40],[50,60]])
# using built in np function for normalised distance
distance = np.linalg.norm(positions[0:1] - positions[1:2])
print (distance)

```

## Drawing circles using built in numpy distance functions

```python
myImage = np.zeros((240,320))

# uses numpy distance measures but is lots slower..

centre = 100
size = 50

for i in range(240):
    for j in range(320):
        positions=np.array([[i,j],[abs(centre-i),abs(centre-j)]])
        distance = np.linalg.norm(positions[0:1] - positions[1:2])
        if distance < size:
            myImage[i,j] = 1

plt.imshow(myImage, clim=(0,1),cmap="gray")
plt.imshow(myImage, interpolation="bilinear", clim=(0,1), cmap="gray")
plt.show()

```

## More complex expressions

```Python
myImage = np.zeros((240,320))

# This code is exactly the same as the the code from our JS and C++ examples

width_frequency = 3.14159/240

frequency = width_frequency * 3

for i in range(240):
    for j in range(320):
        t = math.sin(math.sqrt(i * i + j * j) * frequency)
        myImage[i,j]=t

plt.imshow(myImage, clim=(0,1),cmap="gray")
plt.imshow(myImage, interpolation="bilinear", clim=(0,1),cmap="gray")
plt.show()

```

## More More complex expressions
```Python
myImage = np.zeros((240,320))

# This code is exactly the same as the the code from our JS and C++ examples

PI = 3.14159

width_frequency = 3.14159 / 320

frequency = width_frequency * 5000

for i in range(240):
    for j in range(320):
        t = math.tan(i / frequency) * math.cos(j / frequency) + math.atan(j / frequency) * math.cos(i / frequency);
        myImage[i,j]=t

plt.imshow(myImage, clim=(0,1),cmap="gray")
plt.imshow(myImage, interpolation="bilinear", clim=(0,1),cmap="gray")
plt.show()

```
# Part Two

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

# Part three - what is tensorflow?

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

# Part Four
## Exercise: Getting datasets, processing images and introducing tensorflow
- Before we start building networks in Tensorflow and exploring what they can do
- We should probably try and do something simple
- Like just processing some images
- Use your study time next week to complete the following exercise
- As part of week 6, which is a self-study week, you must study the following notebook.
- https://github.com/ual-cci/MSc-Coding-2/blob/master/Week-6-Exercise-intro-to-image-data-and-tensorflow.ipynb
- Following this, you must make a version of the notebook with at least one major difference that you have introduced yourself. First, you must do some transformation on the image dataset that isn't included in the above document. If you manage to do this, your next task is to collect and process your own dataset instead of the one provided. 

## Useful resources:
https://easy-tensorflow.com/
https://towardsdatascience.com/pytorch-vs-tensorflow-spotting-the-difference-25c75777377b