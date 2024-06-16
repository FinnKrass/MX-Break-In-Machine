# MX Style Switch Break In Machine

Repository is still a work in progress!

A unique take on the switch break in machine intended to streamline the process and maximise outcomes. Useful for those who want to improve the sound and feeling of MX style keyboard switches that come scratchy/inconsistent from the factory.

![Alt text](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/Built-Pic.jpeg)

**Table of Contents:**

- [Main README](#mx-style-switch-break-in-machine)
  
  - [Background](#background)
  
  - [Features](#features)
  
  - [To Do](#to-do)
  
  - [References & Thanks](#references--thanks)

- [Bill of Materials - Hardware](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/BoM/Bill-of-Materials-(Hardware).md#bill-of-materials-hardware)
  
  - [Hardware](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/BoM/Bill-of-Materials-(Hardware).md#hardware)
  
  - [Fasteners](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/BoM/Bill-of-Materials-(Hardware).md#fasteners)

- [Making Your Own](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#making-your-own)
  
  - [Printing](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#printing)
    
    - [Print BoM](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#print-bom)
  
  - [Additional Hardware](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#additional-hardware)
    
    - [Fasteners](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#fasteners)
  
  - [Assembly](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#assembly)
    
    - [Tools Needed](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#tools-needed)
    
    - [Prepare Motor & Limit Switch](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#preparing-the-motor--limit-switch)
    
    - [Prepare Motor Assembly](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#prepare-the-motor-assembly)
    
    - [Prepare the Pistons](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#prepare-the-pistons)
    
    - [Install the Pistons](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#install-the-pistons)
    
    - [Install the Motor Assembly](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#install-the-motor-assembly)
    
    - [Install the PCB](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#install-the-pcb)
  
  - [Testing & Notes](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-Your-Own.md#testing--notes)

- [Making the PCB](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-The-PCB.md)
  
  - [Notes](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-The-PCB.md#notes)
  
  - [To Do](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-The-PCB.md#to-do)
  
  - [Ordering from JLCPCB](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Documentation/Making-The-PCB.md#ordering-from-jlcpcb)

## Background

This project started when I first fell in love with Cherry MX Black's. I wanted a way to break in the switches for all of my builds, but had absolutely no understanding of electronics and CAD at the time, so took it upon myself to learn how to use Fusion360 and eventually design a circuit. Once the design had come together, I started selling broken in switches with a fleet of these machines running around the clock, which helped me vet the design and iron out any problems as well as optimize certain things to make the labor involved with operating and maintaining the machines easier. I worked on this project on and off over about a year and was planning to sell the machines themselves once they were in a state I was proud of, but some life events got in the way, so I've decided to work back and open source it for others to enjoy as much as I have.

## Features

The machine is quite rugged, I've had customers request their switches broken in for 2.5 million + actuations and the machines have handled that no problem. For good measure, I give them 1 hour break every 12 hours, and have had machines comfortably surpass total lifetime actuations of 75 million. This isn't guaranteed of course, it depends on a plethora of variables, including materials used to print, print profiles, the motor manufacturer, bearing quality etc. Regardless, here is a list of features:

- Linear bearings (inspired by Feng Studio's machine)
  
  - Eliminate plastic on plastic friction
  - Ensure the pistons remain aligned, applying even force on all switches

- Full capacity (64 switches) off centre operation.

- Noise reducing plates
  
  - The biggest issue I had with the machines was the noise. To fix that, rear plates were integrated into the design that would be printed in a flexible material (95A TPU) to dampen the noise produced by the switches colliding with the back walls and pistons.
  - An off centre version of this was introduced later on. There are two models for this; one which attaches to the piston, and one which rests against the back wall. The intention is to operate in off centre at all times.

- USB Power Delivery compatible controller & power supply.

- 128x64 OLED display for information on progress.

- Actuation counter with programmable profiles to disable/enable the motor after *x* number of actuations. Currently programmed to turn off after 250,000 actuations to ensure an even distribution of off centre actuations on all 4 sides.

- Two speeds can be selected via a switch on the PCB.

- Rugged 24V motor, capable 564 actuations/minute. (Faster is not recommended)

- Non-volatile flash memory, will recall number of actuations recorded in the event of power loss.

## To-Do

- [ ] Finalise documentation
  
  - [ ] User guide and tips on operating the machine
  
  - [ ] General clean up, more coherent structure.

- [ ] Acceptable print tolerance specifications

- [x] Piston bearing socket tolerance calibration print

- [ ] PCB BoM optimisations (more details in PCB doc)

- [ ] PCB BoM sheet for mouser to automate adding to cart (should be done very soon)

## References & Thanks

The individual who helped me most requested not to be named, but a deep thank you goes out to them for the help they have provided me and continue to provide to the community. Their help is the reason I became more interested in the intricacies of electronics, and that passion has continued far beyond this project now. 

[Kee Keen's open source break in machine](https://github.com/keekeen/MX-Switch-Break-In-Machine/tree/main) helped me greatly in the beginning, definitely check it out if you're interested in the roots of this project!
