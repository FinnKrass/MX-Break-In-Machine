
# MX Style Switch Break In Machine 
![Alt text](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/Built-Pic.jpeg)
## Preamble

This project started when I first fell in love with Cherry MX Black's. I wanted a way to break in the switches for all of my builds, but had absolutely no understanding of electronics and CAD at the time, so took it upon myself to learn how to use Fusion360 and eventually design a circuit. Once the design had come together, I started selling broken in switches with a fleet of these machines running around the clock, which helped me vet the design and iron out any problems as well as optimize certain things to make the labour involved with operating and maintaining the machines easier. I worked on this project on and off over about a year and was planning to sell the machines themselves once they were in a state I was proud of, but some life events got in the way, so I've decided to work back and open source it for others to enjoy as much as I have.

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

## Making Your Own
**NOTE:**

It's suggested to read through the repo in whole before choosing to build one, there will be notes for each section which will include vital information. If you find any issues in the design or gaps in the documentation, feel free to open a github issue and the problem will be addressed.

The PCB/Controller is not necessary if it's too much of a hassle to get manufactured and assembled. The assembled PCB's may be sold at some point if there's interest, but otherwise you just need a 24V power source (or get the 12V motor and a 12V power source).

Another thing worth mentioning is that a lot of the design decisions were made for repeatability, convenience, and cost saving. This is to say, there are likely areas which can be improved for an end user. 

**Cloning the repository**

Open terminal in your folder of choice:

`git clone https://github.com/FinnKrass/MX-Break-In-Machine.git`

then:

`cd MX-Break-In-Machine`

and lastly:

`git submodule init`

### Printing

It's a good idea to make the prints rugged, so for each item in the print BoM there will be a corresponding *suggested* material. These can be changed, but I can't guarantee the longevity if substituted for a weaker material. I've only tested the off centre plates in TPU, so I can't guarantee functionality if printed in standard materials. I've also added a column for alternative materials where applicable. Finally, when selecting the print settings, make sure you use ~6 or more perimeters and 25% (gyroid) infill. For some parts this strength isn't critical, so feel free to make changes at your own liberty. I've also selected the primary material choices to be attainable at a reasonable price, if Nylon (PA) or PC are listed as an alternative and you have some on hand, then use that!
#### Print BoM

| Name                 | Quantity | Material | Optional |   Alternative   |
|:---------------------|:--------:|:--------:|:--------:|:---------------:|
| Switch Tray          |    2     |   PLA    |    NO    | PETG/PLA-CF/ABS |
| Back Plate           |    2     |   TPU    |    NO    |  PLA/PETG/ABS   |
| Machine Housing      |    1     | PETG-CF  |    NO    | PETG/PLA-CF/ABS |
| Motor Mounting Plate |    1     | PETG-CF  |    NO    |  PA-CF/PAHT-CF  |
| Motor Yoke           |    1     | PETG-CF  |    NO    |  PA-CF/PAHT-CF  |
| Piston               |    2     | PETG-CF  |    NO    |   PLA-CF/ABS    |
| Rod Cap              |    2     |   PLA    |    NO    | PETG/PLA-CF/ABS |
| OC Back Plate        |    2     |   TPU    |   YES    |       N/A       |
| OC Piston Sleeve     |    2     |   TPU    |   YES    |       N/A       |

OC = Off Centre, PA = Nylon

*NOTE:*

Please keep in mind that print tolerances vary between printers (and even print settings). Each piston requires bearings to be pressure fitted for the linear rails. Test first by cutting one of the holes off the model in your slicer, if the bearing fits snug then you're good to go, but if it's too tight or too loose then you can tweak it using the X-Y hole compensation setting in your slicer. This can be very sensitive, so adjust in +/- 50 micron steps.

#### Additional Hardware
*Sourcing Notes:* 

The JGA25-370 is easy to find, I've linked product pages I've used but if it's easier to purchase elsewhere then just make sure you buy the correct voltage/speed. The same applies for the linear bearings (LM6UU), though there is a huge difference in quality comparing cheap to expensive. If you get the cheap ones (sub 50c each), buy a handfull of extras in case bearings comes out or they're not gliding freely along the rod. The more expensive ones may be worth it if you're going for longevity, if you're in Australia use [these](https://www.makerstore.com.au/product/bear-lm6uu/), and if you can't find any local to yourself then use the links provided in the table below and pick up extras.

For the yoke bearings, the naming scheme is inconsistent across sellers, so purchase based off [dimensions](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/Yoke-Bearing.png) if the part number doesn't resemble what's listed in the table below. 

For the 6mm smooth rod there are a few ways you can purchase them, one example has been linked. The length required is 145mm +/- 5mm, and you can usually find stores which sell them pre cut to 150mm which works just fine, or if you can only find greater lengths then just cut them down to size. Alternatively some suppliers will let you request a specific length, in which case have them cut to 145mm. No matter how you arrive at the 145mm +/- 5mm, you should check both ends and make sure they're smooth/free of burrs. If the ends aren't smooth there's a chance that the rod will catch on the bearing balls inside the linear bearing, which will break it.

| Name          | Quantity | Optional |    Description    |                                                                             Link                                                                              |
|:--------------|:--------:|:--------:|:-----------------:|:-------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| JGA25-370     |    1     |    NO    |  24V 300/282RPM   |                     [link](https://www.aliexpress.com/i/32987942205.html)/[alternative](https://item.taobao.com/item.htm?id=691467377622)                     |
| SS-01GL2      |    1     |   YES    |  Counter Switch   | [link](https://www.lcsc.com/product-detail/Microswitches_Omron-Electronics_C231399.html)/[alternative](https://www.aliexpress.com/item/1005005708872538.html) |
| LM6UU         |    4     |    NO    |  Linear Bearing   |                                                 [link](https://www.aliexpress.com/item/1005004774546723.html)                                                 |
| Yoke Bearing  |    2     |    NO    | C1L6M3 or 3C1L6M3 |                 [link](https://www.aliexpress.com/item/1005005223529401.html)/[alternative](https://item.taobao.com/item.htm?id=672727759613)                 |
| Cable Harness |    2     |   YES    |    36920-0202     |                                                 [link](https://au.mouser.com/ProductDetail/Molex/36920-0202)                                                  |

#### Fasteners
| Size  | Quantity |    Type    |
|:------|:--------:|:----------:|
| M2x4  |    3     | Hex Socket |
| M2x10 |    2     | Hex Socket |
| M3x5  |    2     | Hex Socket |
| M3x6  |    2     | Hex Socket |
| M3x6  |    1     | Grub Screw |
| M3x8  |    4     | Hex Socket |
| M3    |    3     |  Hex Nut   |

### Assembly

This drawing should be referenced throughout the assembly process. It tells you what screws go where.

![Alt text](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/Assembly-Guide.PNG)

#### Tools Needed:
- H1.5 Hex Bit/Key
- H2.5 Hex Bit/Key
- Soldering Iron 
- Hammer (optional)
