# Coding 2 : Advanced Frameworks

# Week 4 : Embedded systems
## 2020-2021

Professor Mick Grierson

## Introduction

So far we have looked at C++ and JavaScript frameworks that are useful for a range of Creative Computing tasks that incorporate graphics, sound, interaction, machine learning etc. We've thought about how we go about common tasks using these systems. However, we've not really considered how we might respond to working outside the context of existing hardware - e.g. a desktop, mobile phone/tablet or laptop scenario. So this is what we'll be doing today.

# But first

Recap and Homework review. LetLet's take a look at the work I asked you to do, and think about some common problems.


# Introducing the Raspi

## Different PI models

- Let's look at a few different Raspberry PI devices: https://en.wikipedia.org/wiki/Raspberry_Pi
- In detail, we're going to look at the PI A+, the PI Zero, and the PI 4
- These all have different hardware, speed, memory limits etc.
- They also have very different potential uses
- We're going to examine some of the ways they differ
- Finally let's look at the GPIO. You can emulate the PI GPIO here: https://create.withcode.uk/python/A3

## Power Consumption
- These devices are quite efficient, which makes them highly usable for IoT and hardware projects
- There's a useful article here on power consumption https://raspi.tv/2015/raspberry-pi-zero-power-measurements
- As you can see, the PI Zero is very efficient
- This means you can run them from battery packs if those packs can provide enough amps.

## Setting up the PI
- I'm going to talk you through how to set up the PI
- We're going to discuss SD cards, OS download and configuration
- We'll also look at customisation, SSH, communications protocols, memory and overclocking functions
- Finally we'll discuss headless operation, boot sector corruption and how to avoid it, overlay filesystems and why they are useful etc.

## Using Linux
- First steps in Linux - using the terminal
- navigating, changing directory, listing directories
- running applications and scripts from the terminal, 
- Here's some help to get you in to using the console:
https://missing.csail.mit.edu/2020/course-shell/
- And a terminal cheat sheet:
https://linoxide.com/guide/linux-cheat-sheet.png

## Downloading Openframeworks
- Using openframeworks on the PI is very simple
- You are going to love it
- We're going to download, configure and run openframeworks
- If you are interested in making a synthesiser, lots of people have done this with a raspi, but you probably want to buy a hardware audio shield.
- Also, raspberry pi is a platform used by artists all the time due to its price point.

If you are interested in using a raspberry pi, you can either borrow a raspberry pi 4 from CCI, or purchase your own.
Usually in this session we would work together to download and install openframeworks on our PI (hint - nightly builds work well)
Then we would build a simple sound or graphics application and start to think about what else we might do.
This time, we're going to go through the process of setting up a pi together, and talk through common problems
I'm also going to get some basic applications running and make sure you've got a good idea how to do that.

## Borrowing a Raspberry PI 4
We have lots of Raspberry PI 4 devices at CCI. Talk to the technical services team if you are interested in using one.
If you need help setting it up, you can refer to this video, or see any of the huge number of resources available.

## What frameworks do I need for different types of projects?

Let's think about some theoretical examples and consider what frameworks we should probably choose.

- You want to make a real-time interactive installation with 2D or 3D computer graphics and sound, potentially using hardware sensors.
You should probably do this in C++, possibly with openFrameworks. You could do it in Unity but remember, Unity is not the best platform for integrating real-time sensors, and isn't a good platform for sound due to its buffer implementation (it's targetted for plaback of sound effects). You could also choose JavaScript, but this won't be as performant as C++, but you would need to negotiate the sensor situation depending on the browser you are using.
- You want to create an online, interactive networked environment where people in different places can interact and respond to each other.
You should probablly do this in JavaScript. You could do it in Python but it would be harder, and there would not be much benefit. You could also do this in unity if it's a simple 2D or 3D game.
- You want to build audio or video processing software for other artists
Do this in C++. You can build great sound toys in JavaScript, but for anything serious, you need to hit the metal. For audio plugins, Juce is fine and very simple to use once you've tried openFrameworks.
- You want to create new artworks using generative deep learning
You should probably do this in Python.
- You want to create a device that can use machine learning
You need to use an embedded arm device that is capable of holding reasonably sized models in memory. Consider something like a PI or similar
- You want to create a game or interactive VR experience
You can do this in Unity and it will be great. For better performance, Unreal is also good. Or you can just DIY in openGL the way I taught you. It's not hard.
- You want to scrape data off the internet and process it as part of a project
You need to do this in Python, possibly using BS4 and/or scrapey and gensim for processing.
- You want to create an internet of things device of some kind.
Raspi zero.

# Lecture : Arm devices

## The outside world
Portable devices that can carry out computational tasks in the outside world provide some interesting affordances. Working with small, portable devices opens up many opportunities:
- Create and install interactive media devices anywhere
- Use sensors to collect data remotely
- Build "ambient" computing environments (oh .. wait...what are those?)
- Design and prototype new mobile devices and platforms
- Design and prototype new computing hardware for bespoke purposes, e.g. music tech devices, vision mixers, autonomous robots etc.

## Modern hardware prototyping

Planning to deliver everything over existing hardware infrastructure is totally fine. But it has a number of restrictions

- Performance will be defined by capabilities of phones and tablets, or someone else's portable computing hardware (e.g. laptop, phone)
- So will all interaction (so nothing that isn't currently marketed widely e.g. no sliders, knobs, switches, or tactile interfaces)
- Consequently, limited capacity for interaction research (new forms of interaction)
- Locked in to an existing hardware and software ecosystem (e.g. app store)
- Have to abide by existing hardware and software ecosystem agreements
- Limited potential for trademarking, patents etc.
- Not much of a hardware business unless you plan to sell accessories for mobile platforms.   

## Why not just use Arduino?

Arduino is a great platform and very flexible. However, there are a number of things that an Arduino isn't very good at and can't do at all:
- Produce high resolution interactive graphics
- Produce professional quality sound and interactive sound outputs
- Process large amounts of data using algorithms
- Work with machine learning tools
- Carry out any complex computations / stats
- Hold anything substantial in memory

## Limitations of Arduino-type platforms
Arduino is a certain type of embedded device platform that is often not very fast or capable. It's fine for simple computations. But:
- They often use quite a simple CPU - e.g. ARM cortex-M:
- They have very limited memory (required for doing computation!)
- They are slow - usually between 16 and 42Mhz.

## ARM architectures for embedded devices
- Many embedded devices use ARM cortex M class devices
- You can find a list of these devices here:
- https://en.wikipedia.org/wiki/ARM_Cortex-M
- These devices are great for some forms of hardware prototyping
- But very often, they lack the speed of conventional mobile platforms (although they are still used as part of these types of platforms e.g. for additional processes)
- They are not that great for contemporary robotics for example.

## So what does your phone run on?
- Your phone probably runs on a device based on ARM architectures.
- However, the class of ARM device is probably higher:
- ARM 9 - https://en.wikipedia.org/wiki/ARM9
- ARM 11 - https://en.wikipedia.org/wiki/ARM11
- ARM Cortex A7, A53, A72
- Almost all phones run something like that, or substantially based on it
- ARM were a British company until a couple of years ago when they were bought by softbank in Japan.

## More powerful System on a Chip - SOC
- More powerful ARM devices can be used to create better System on a Chip devices (SOC)
- These types of SOC devices are great for hardware prototypying
- They can provide processing power comparable to your phone
- They can be easily expanded to provide excellent interface architecture (serial, USB, GPIO, SDI), graphics (including console-level GPU), Ethernet or even WIFI, bluetooth, and other features.
- Basically it's a computer - like the one in your mobile phone, or even your chromebook or laptop. But it's tiny.

## Advantages of capable SOC devices
- Low cost of manufacture
- Low cost for bulk purchase
- Open hardware options (all specifications published)
- Designs for SOC devices available license free for adaptation
- All SOC parts can be replaced and refactored
- GPIO

## What this means:
- SOC devices can do all the things that your phone or even laptop does
- But you can also wire any electronics to them that you like using GPIO
- You can also connect custom peripheral hardware using SPI (Serial Peripheral Interface)
- You can create your own custom SOCs that are identical to prototyping boards that you have used to develop your prototype
- You can do this at the fraction of the cost and in bulk
- You can completely customise the system to you needs
- You can use it to create patentable technology more easily
- (it's much easier to patent a device than to patent software)

## Prototyping boards that use ARM-style SOCs
- There are a great many different types of such platforms
- Beaglebone, PCDuino, Raspi, Jetson Nano, Chip
- Some of them have FPGAs on them !
- https://developer.arm.com/tools-and-software/development-boards/fpga-prototyping-boards
- Field Programmable Gate Array - https://en.wikipedia.org/wiki/Field-programmable_gate_array

## Raspberry PI
- Raspberry PI is by far the most popular and widely used SOC-based prototyping platform.
- Raspberry PI is currently at version 4
- PI4 is ridiculously powerful for such a cheap, small device:
- SoC: Broadcom BCM2711B0 quad-core A72 (ARMv8-A) 64-bit @ 1.5GHz
- GPU: Broadcom VideoCore VI (4k dual output)
- Networking: 2.4 GHz and 5 GHz 802.11b/g/n/ac wireless LAN
- RAM: 1GB, 2GB, or 4GB LPDDR4 SDRAM
- Bluetooth: Bluetooth 5.0, Bluetooth Low Energy (BLE)
- GPIO: 40-pin GPIO header, populated
- Storage: microSD
- Ports: 2 × micro-HDMI 2.0, 3.5 mm analogue audio-video jack, 2 × USB 2.0, 2 × USB 3.0, Gigabit Ethernet, Camera Serial Interface (CSI), Display Serial Interface (DSI)
- Dimensions: 88 mm × 58 mm × 19.5 mm, 46 g

This is more powerful than many laptops.

- (roughly) twice the CPU and RAM spec of the original Macbook air.

- Also has all the connectivity you would need to create a pretty smart robot.

## OS choice
- You can run whatever OS you like on your SOC as long as it has an kernel that suits the instruction set of your architecture
- Raspberry PI uses ARM architecture and there's an OS developed to support it.
- RASPBIAN is based on Debian linux, and is one of the most reliable operating systems available.
- Why is that?
- It's also totally free

## What can it do?
- You can run node, openframeworks, Python 2 or 3 and even Tensorflow, including (with lots of fiddling) a GPU-enabled TF installation.
- You can set them to read-only mode so that they don't b0rk after you've deployed them
- You can strip them down so that they boot in seconds and run whatever software you want without intervention
- You can do all the things you might do with an Arduino in terms of connectivity BUT, there are some important differences   

## GPIO and power
- GPIO on Raspberry PI isn't the same as Arduino
- Also, it uses a bit more power
- But these differences don't stop you doing the same things - you just need to be aware of them.
- Power consumption on the PI is not always as good as Arduino, depending on what version you use. For example, the PI Zero uses so little power I can barely remember the number because it's so small.
https://www.jeffgeerling.com/blogs/jeff-geerling/raspberry-pi-zero-power
- You can power the PI from LIPO batteries. Check the milliAmp Hour of the battery (mAh). An phone-charging battery that pumps out 3A and is 10000 mAh can power the PI for hours.
- But, when connecting devices to and from the PI you need to consider its voltage limitations:
- PI GPIO inputs are at 3.5v, whereas Arduino outputs 5v, so you will need to use a voltage divider to connect them that way.
- However, you can power devices from the PI, including Arduino, because the PI has 5v outputs. You can also draw about 1.5 amps from it. That's a lot...
- https://pinout.xyz


## Next steps
- Consider how you might restructure and refactor your Arduino projects to work on the PI
- Work in groups to share ideas about what advantages this might bring e.g. sound and graphics, machine learning, faster on-unit processing
- What other kinds of projects might you be able to create that were previously out of reach?
- In groups discuss and plan some small project with the PI.


