# Coding 2 : Advanced Frameworks

# Week 8 : Embedded systems
## 2019-2020

Professor Mick Grierson

## Introduction

So far we have looked at a selection of software languages, platforms and frameworks that are useful for a range of Creative Computing tasks that incorporate graphics, sound, interaction, machine learning etc. We've thought about how we go about common tasks using these systems. However, we've not really considered how we might respond to working outside the context of existing hardware - e.g. a desktop, mobile phone/tablet or laptop scenario.

## The outside world
Portable devices that can carry out computational tasks in the outside world provide some interesting affordances. Working with small, portable devices opens up many opportunities:
- Create and install interactive media devices anywhere
- Use sensors to collect data remotely
- Build "ambient" computing environments
- Design and prototype new mobile devices
- Design and prototype new computing hardware for bespoke purposes, e.g. music tech devices, vision mixers, autonomous robots etc.

## Modern hardware prototyping

Planning to deliver everything over existing hardware infrastructure is totally fine. But it has a number of restrictions

- Performance will be defined by capabilities of phones and tablets, or someone else's portable computing hardware (e.g. laptop)
- So will all interaction
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
- It often uses quite a simple CPU - e.g. ARM cortex-M:
- It has very limited memory (required for doing computation!)
- It is slow - usually between 16 and 42Mhz.

## ARM architectures for embedded devices
- Many embedded devices use ARM cortex M class devices
- You can find a list of these devices here:
- https://en.wikipedia.org/wiki/ARM_Cortex-M
- These devices are great for some forms of hardware prototyping
- But generally, they lack the speed of conventional mobile platforms
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
- They can provide excellent interface architecture (serial, USB, GPIO, SDI), graphics (including console-level GPU), Ethernet or even WIFI, bluetooth, and other features.
- Basically it's a computer - like the one in your mobile phone, or even your chromebook or laptop.

## Advantages of capable SOC devices
- Low cost of manufacture
- Low cost for bulk purchase
- Open hardware options (all specifications published)
- Designs for SOC devices available for free
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

## Prototyping boards that use
- There are a great many different types of such platforms
- Beaglebone, PCDuino, Raspi, Jetson Nano, Chip
- Some of them have FPGAs on them !
- https://developer.arm.com/tools-and-software/development-boards/fpga-prototyping-boards
- Field Programmable Gate Array - https://en.wikipedia.org/wiki/Field-programmable_gate_array

## Raspberry PI
- Raspberry PI is by far the most popular and widely used SOC-based prototyping platform.
- Raspberry PI is currently at version 4
- PI4 is ridiculously powerful:
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
- RASPBIAN is based on Debian linux, and is one of the most reliable operating systems in existence.
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

# Let's set up our PIs !

## Exercise 1
Get your PI set up and play with it for a little while
Try to Download and install openframeworks on the PI (hint - nightly builds work well)
Build a simple sound or graphics application
Be aware, the PI doesn't have an audio / mic input, or a webcam attached. You would need to add those.

Some things to consider:

- Do you have any linux experience at all?
- If not, here's some help to get you in to using the console:
https://missing.csail.mit.edu/2020/course-shell/
- And a terminal cheat sheet:
https://linoxide.com/guide/linux-cheat-sheet.png
Some questions:
- Which version of OF should I grab?
- What version of GL does the PI use?
- What kind of shaders can you use on on the PI?

## Exercise 2
- Consider how you might restructure and refactor your Arduino projects to work on the PI
- What other kinds of projects might you be able to create that were previously out of reach?
- Plan some small project with the PI to test out your skill
