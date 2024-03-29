# Coding 2 : Advanced Frameworks

Professor Mick Grierson

## Week 6 - Introduction to Python Continued

Last week we did a crash course in Python. This was not as hard as it otherwise might have been as you've already got some solid JavaScript experience, and also spent some time messing around with C++. I'm sure you must still have a lot of questions (for example, how long will it be before I am proficient in these languages? Answer: quite a while), but in general you should at least feel like you understand how variables, conditionals, loops, functions and objects work in Python. To remind you, this is what we looked at:

* Printing to the console, using quotes, indentation / blocks, string concatenation - in particular how this is different between Python 2 and 3.
* variables : ints, floats, strings, lists, tuples (read-only lists), accessing data in lists, dictionaries. We also looked at using type().
* Basic operators
* conditionals (if), loops (for), functions (def)
- for letter in 'Python': print 'Current Letter :', letter
* Python keywords, Python comments (#)
* import statements.

We also did the Python Challenge, which is an excellent mechanism for learning Python. If you haven't had a chance to get to the 5th challenge, that's OK, especially if you have never thought of creating a function that calls itself. I'll talk through the solutions but:

Hackingnote's solutions for Python Challenge are actually really great, and include solutions that work well in Python 3:

https://www.hackingnote.com/en/python-challenge-solutions/level-0

In particular, I recommend that you all have a try at level 7 as it's lots of fun:

https://www.hackingnote.com/en/python-challenge-solutions/level-7

I also asked you to all create your own Python challenge riddle / question. Please send these to me!


## What we will cover this session

This session is about common Python libraries and what they are used for. We will look at some basic examples for a small selection of essential tools that you need to know. We'll be looking at these roughly in order of complexity. However, just because they are complex technologies, doesn't mean they are necessarily hard to use.

## But first

Often, you will come across an example, or a library, and all you will really want to know is what methods and functions are available.

This is similar to when you are using an IDE, and you want to look up what member functions are available for an object.

But how can you get more information about a specific python object or command?

There are two main ways

* help(something). Try the following:

help(print), help(range), help(type)

This returns actual python documentation. This is a more or less fully featured system that is designed to give you good information on what a Python object / function can do.

* dir(something)

dir() is very similar to help(), but only returns the attributes that belong to an object that you pass in as an argument. It's not as fully featured as help(), and it can be a bit random what it spits out from object to object, but it tells you what is actually there. Sometimes, this is different to what's in the documentation...

You should be using help() or dir() whenever you're not sure how something works. Don't forget!

##  Core libraries

### matplotlib

https://matplotlib.org/

matplotlib is a library for plotting data using an approach similar to that which can be found in the popular research software Matlab. It is designed to allow you to create plots that are publication quality, but in general, it's just a great tool for seeing what you are doing.

```python
# this is a bit weird and easy to forget.
# here we are importing the pyplot functions as plt.
# we're also importing math so we can do some trig.

import matplotlib.pyplot as plt
import math

x = range(100)
y = []

for value in x:
    y.append(math.sin(value * 0.1))

plt.plot(y)

```
There are lots of important core plotting features, including bar charts, pie charts, scatter plots etc. Take a look:

https://matplotlib.org/gallery/index.html

### Numpy

https://numpy.org/

Numpy is one of the most powerful and important Python packages. It is excellent for handling multidimensional arrays - e.g. large blocks of data - and has some impressive built in functions for doing vector processing and linear algebra. In general, if you are wanting to process large blocks of numbers, you should be using Numpy.

Numpy arrays are much more powerful that Python lists.
They allow you to create and manipulate arrays of information, such as large blocks of image data, and process it quickly.

Quick intro to Numpy:

```python
import numpy as np

# creates an empty 1D array with 100 elements
i = np.zeros([100])

# creates an empty 3D array with 5 * 5 * 5 elements
x = np.zeros([5,5,5])

# creates a multidimensional array 3 * 2 by 2 blocks
y = np.zeros([2,2]*3)

print ("the shape of this array is ", np.shape(i))

print (i)

print ("the shape of this array is ", np.shape(x))

print (x)

print ("the shape of this array is ", np.shape(y))

print(y)

z = np.arange(100).reshape(2, 5, 10)

print(z)

```

https://numpy.org/devdocs/user/quickstart.html

### pandas

To be honest, the main reason people use pandas is because it can read in Microsoft excel files and csv files. This makes it handy for people who naturally use excel to collect and organise data.

There's a good tutorial on how to import and use excel documents in to Python here:

https://www.dataquest.io/blog/excel-and-pandas/

And this cheatsheet is pretty great.  

https://pandas.pydata.org/Pandas_Cheat_Sheet.pdf

- https://pandas.pydata.org/docs/index.html

### urllib

https://pythonspot.com/urllib-tutorial-python-3/

This is a really essential library for Python that you're going to use a lot. You can do lots of cool things that make scraping data much easier, including specifying your user agent, which basically means pretending to be any browser that you like.

It's super easy to use urllib to grab a webpage :

```python
import urllib.request

html = urllib.request.urlopen('https://www.arts.ac.uk').read()
print(html)

```

the 'html' variable / object in the above example now has all the data from the web page in it. But parsing HTML is not easy to do at all. Wouldn't it be great if there was some kind of library for parsing HTML easily? That would just be amazing. Oh wait...

### bs4

bs4, or "Beautiful Soup" is a great html parser, and the basis of a very large number of web scraping softwares. If you're building a scraper, you should start with bs4. Here' an example of a script that grabs some webpage data and iterates through it using bs4.

```python
# Get all the links from reddit world news.
# Can you spider those links?

from bs4 import BeautifulSoup
import urllib.request

html = urllib.request.urlopen('http://www.reddit.com/r/worldnews/').read()

soup = BeautifulSoup(html)

# just get all the links. Links are 'a' (as in <a href = "">)

for link in soup.find_all('a'):
    print(link.get('href'))

```

### bokeh

Bokeh is a great way of creating interactive plots. matplotlib isn't designed for interactive plot generation - it's for generating plots for books and academic papers. Bokeh on the other hand makes it super easy to make a plot that you can interact with on a webpage. Like this :

```python
from bokeh.plotting import figure, output_file, show

# prepare some data
x = [1, 2, 3, 4, 5]
y = [6, 7, 2, 4, 5]

# output to static HTML file
output_file("lines.html")

# create a new plot with a title and axis labels
p = figure(title="simple line example", x_axis_label='x', y_axis_label='y')

# add a line renderer with legend and line thickness
p.line(x, y, legend="Temp.", line_width=2)

# show the results
show(p)

```

https://docs.bokeh.org/en/latest/docs/user_guide/quickstart.html#userguide-quickstart


### gensim

https://radimrehurek.com/gensim/

Gensim is a general purpose Topic modelling and Natural Language Processing library with sentiment analysis, word-vectors, and lots of very useful topic modelling toolkits, such as Latent Semantic Analysis (LSA) and Latent Dirichlit Allocation (LDA - https://en.wikipedia.org/wiki/Latent_Dirichlet_allocation).

It's looking a bit old by modern standards, so you might also want to take a look at the next item in our list!

### Transformers

https://github.com/huggingface/transformers

Hugging Face's Transformers library is an incredible library of contemporary Natural Language Processing tools. For contemporary autosummarisation, text style transfer, and other quite startling NLP demos, check out the website below.

https://huggingface.co/models

For example, you can create a google colab notebook, import huggingface, and do an autosummarisation very easily. Here's some code that gets you started with this:

```python

!pip install transformers
from transformers import pipeline

# Open and read the article - if using colab, you can upload text to the sample_data folder, or connect your google drive. 
f = open("article.txt", "r", encoding="utf8")
to_tokenize = f.read()

# Initialize the HuggingFace summarization pipeline
summarizer = pipeline("summarization")
summarized = summarizer(to_tokenize, min_length=75, max_length=300)

# Print summarized text
print(summarized)

```

# Exercise

- Working in groups, build a simple webscraper that scrapes a bunch of documents from the internet and creates a summary of each one. One way to do this is to start with a bunch of pages, and then follow all the links on those pages, scraping new documents as you go. Then you can record each link with a quick summary in a list.

- You can use any method you like to do the summary - you could just select a couple of sentences, or use some form of summarisation tool (Huggingface has one, Gensim might have one, or you could make one up).

- If you manage to achieve this, extract keywords by counting the total number of similar words from all the different documents and see if any are more popular than others. Search for documents that contain those keywords using Python and then summarise those documents too!

# Homework - take a look at the notebook in this repository called Week-6-Exercise-intro-to-image-data-and-tensorflow. :-)
