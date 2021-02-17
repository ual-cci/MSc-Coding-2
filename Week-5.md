# Coding 2 : Advanced Frameworks

## 2020-21

# Session 5: Introduction to fundamental machine learning concepts with RapidLib

---


## Part one: Lecture

Follow the Lecture, then go through the exercises in class.

Grab the PDF presentation here:

- https://github.com/ual-cci/MSc-Coding-1/blob/master/Session-9.pdf

Start here:

* https://mimicproject.com/code/8de3cbbe-b7c6-d79f-65fa-42fd1aa43a26

## Part Two : Exercises

Do these exercises individually or in groups, and share your outcomes and observations with each other. 

## Exercise 1

Go through the tutorial as in the lecture here:

https://mimicproject.com/guides/RAPIDMIX

In the first step, you'll be asked to include the rapidLib library

Try entering inputs. Observe the outputs. Explore how the neural network produces results based on those inputs.

In particular:

* Try entering values that are higher than any of the values in the training set
* Try entering values that are lower than any of the values in the training set
* What do you notice about the Neural Network's behaviour?

You can grab the js code for the classification explorer here:

https://mimic-238710.appspot.com/asset/7addbbfe-b039-713d-f9b9-75a6cd00e923/classification-explorer.js


---

## Exercise 2

Take a look at the classification explorer here:

https://mimicproject.com/code/7f92bd4e-6d2b-181c-559f-4add766f2095

In order to input training examples, hold down a number key (e.g. 1) and move the mouse (you may have to click inside the example first to bring it into focus).

This will input examples of that class as long as you are holding down that number key. The decision boundary will then be displayed.

Try to choose a set of training examples that will draw the boundary with Class 1 on the left in green and Class 2 on the right in blue.

Try and make the line as straight as possible between the two classes.

Now try to make class 2 occupy the lower right quadrant.

* Have you had to manufacture examples close to the decision boundary to make it fit the shape?
* How might this effect the make-up of your datasets when working on an actual project?
* Will it just consist of representative examples of thing you are modelling?


---

## Exercise 3

Take a look at this example:

https://mimicproject.com/code/3864f3e5-8263-b70e-5ef9-1037c724d4ec

This extracts Mel-Frequency Ceptrum Coefficients and uses them as input to a KNN classifier.

Create a selection of classes and explore how good the system is.


---

## Exercise 4

Take a look at the Regression explorer:

https://mimicproject.com/code/26ab5507-0d25-07eb-cb03-aaa93883765d

* In order to input training examples, click onto screen at any point.

* The X value denotes the input value, whereas the y value denotes the output value. You will then see the regression line drawn as you add values.

* Try to get a feel for what types of lines are capable and how they’re influenced by the training data.

* Create a training set that produces a diagonal line from one corner of the canvas to the other.

* How easy is this to do? What issues do you face?

You can grab the js code for the regression explorer here.

https://mimic-238710.appspot.com/asset/26ab5507-0d25-07eb-cb03-aaa93883765d/regression-explorer.js

---

## Exercise 5

Now we are going to try and see if we can train a model with 3 outputs to behave consistently.

We’re going to one single input to control EXACTLY 3 output parameters.

Fork the below example:

https://mimicproject.com/code/5d67faaa-e4c3-771a-f824-fe5c5b978ab6

This is an example of using a slider as input to control a granular synthesiser (borrowed from Zya)

Granular synths play lots of small fragments (grains) of a soundfile at various positions.

* Play around with the two parameters and click on different parts of the waveform to find some sounds you like.

* When you are ready to record, select the "Record" checkbox.

* When you are ready to play, select the "Run" checkbox.

* This will train your model with the recorded dataset and now all 3 synthesiser parameters will be controlled by just the one value from the input slider.

* Keep recording examples until you can reliably control the output.

---

## Exercise 6

Can you take the simple RapdLib example we created at the start and use it to take different inputs, and control different outputs?

How about using the system for controlling a 3D mesh?

---

## Further reading

If you're interested in coding your own Neural Networks, this is a great tutorial :

https://karpathy.github.io/neuralnets/


# Homework: Using Numpy to compute images

This homework is to prepare you for next week's session, when we'll be creating simple machine learning systems in Python.
Understanding how Numpy works is extremely useful when trying to do this, so in order to get you up to speed, I've created a little tutorial on how to use Numpy to carry out image processing.

Follow the tutorial below, and then use it as a starting point to convert one of last term's graphics examples to Python using Numpy. For example, you might choose to create a version of the mandelbrot set, or some other 2D algorithmic graphics example. You might also choose to create a blur effect, or a simple 3D renderer - it's up to you. But - *don't try to create anything interactive!*. It's really not going to work...

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

# We're gonna use numpy

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
