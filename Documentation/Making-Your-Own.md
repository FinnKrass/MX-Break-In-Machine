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

It's a good idea to make the prints rugged, so for each item in the print BoM there will be a corresponding *suggested* material. These can be changed, but I can't guarantee the longevity if substituted for a weaker material. I've only tested the off centre plates in TPU, so I can't guarantee functionality if printed in standard materials. It's important that you have your TPU print profiles dialled in for the off centre plates, there are a handful of bridges and some steep overhangs. Where applicable, alternative materials are listed. 

When selecting the print settings, make sure you use ~6 perimeters and 25% (gyroid) infill. For some parts this strength isn't critical, so feel free to make changes at your own liberty. I've also selected the primary material choices to be attainable at a reasonable price and printable by beginners, but if any Nylon filaments are listed as an alternative and you have some on hand, then use that!  The last thing to note is that supports are not needed for any part, there's a few short bridges and mild overhangs, but all printers should be able to handle that. Screw bores that are on the bottom surface are modelled with sequential bridging, these print cleanly without supports but your slicer may automatically add them without you realising *so make sure to disable automatic supports*.

#### Print BoM

| Name                 | Quantity | Material | Optional | Alternative     |
|:-------------------- |:--------:|:--------:|:--------:|:---------------:|
| Switch Tray          | 2        | PLA      | NO       | PETG/PLA-CF/ABS |
| Back Plate           | 2        | TPU      | NO       | PLA/PETG/ABS    |
| Machine Housing      | 1        | PETG-CF  | NO       | PETG/PLA-CF/ABS |
| Motor Mounting Plate | 1        | PETG-CF  | NO       | PA-CF/PAHT-CF   |
| Motor Yoke           | 1        | PETG-CF  | NO       | PA-CF/PAHT-CF   |
| Piston               | 2        | PETG-CF  | NO       | PLA-CF/ABS      |
| Rod Cap              | 2        | PLA      | NO       | PETG/PLA-CF/ABS |
| OC Back Plate        | 2        | TPU      | YES      | N/A             |
| OC Piston Sleeve     | 2        | TPU      | YES      | N/A             |

OC = Off Centre, PA = Nylon

*NOTE:*

Please keep in mind that print tolerances vary between printers (and even print settings). Each piston requires bearings to be pressure fitted for the linear rails. Test first by cutting one of the holes off the model in your slicer, if the bearing fits snug then you're good to go, but if it's too tight or too loose then you can tweak it using the X-Y hole compensation setting in your slicer. This can be very sensitive, so adjust in +/- 50 micron steps.

#### Additional Hardware

*Sourcing Notes:* 

There are dedicated documents covering the BoM for the entire project to make sourcing easier. If you're find purchasing from the AliExpress links provided, you can mostly ignore the following notes as they cover things to look out for when sourcing elsewhere.

The JGA25-370 is easy to find, I've linked product pages I've used but if it's easier to purchase elsewhere then just make sure you buy the correct voltage/speed. The same applies for the linear bearings (LM6UU), though there is a huge difference in quality comparing cheap to expensive. If you get the cheap ones (sub 50c each), buy a handful of extras in case bearings comes out or they're not gliding freely along the rod. The more expensive ones may be worth it if you're going for longevity, if you're in Australia use [these](https://www.makerstore.com.au/product/bear-lm6uu/), and if you can't find any local to yourself then use the links provided in the table below and pick up extras.

For the yoke bearings, the naming scheme is inconsistent across sellers, so purchase based off [dimensions](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/Yoke-Bearing.png) if the part number doesn't resemble what's listed in the table below. 

For the 6mm smooth rod there are a few ways you can purchase them, one example has been linked. The length required is 145mm +/- 5mm, and you can usually find stores which sell them pre cut to 150mm which works just fine, or if you can only find greater lengths then just cut them down to size. Alternatively some suppliers will let you request a specific length, in which case have them cut to 145mm. No matter how you arrive at the 145mm +/- 5mm, you should check both ends and make sure they're smooth/free of burrs. If the ends aren't smooth there's a chance that the rod will catch on the bearing balls inside the linear bearing, which will break it.

If you choose not to have the PCB and bring your own power source, you can omit the cable harnesses in favour of the correct cable for your power source. The cable linked below is used to connect the limit switch (which counts actuations) and motor to the circuit board.

| Name          | Quantity | Optional | Description       | Link                                                                                                                                                          |
|:------------- |:--------:|:--------:|:-----------------:|:-------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| JGA25-370     | 1        | NO       | 24V 300/282RPM    | [link](https://www.aliexpress.com/i/32987942205.html)/[alternative](https://item.taobao.com/item.htm?id=691467377622)                                         |
| SS-01GL2      | 1        | YES      | Limit Switch      | [link](https://www.lcsc.com/product-detail/Microswitches_Omron-Electronics_C231399.html)/[alternative](https://www.aliexpress.com/item/1005005708872538.html) |
| LM6UU         | 4        | NO       | Linear Bearing    | [link](https://www.aliexpress.com/item/1005004774546723.html)                                                                                                 |
| Yoke Bearing  | 2        | NO       | C1L6M3 or 3C1L6M3 | [link](https://www.aliexpress.com/item/1005005223529401.html)/[alternative](https://item.taobao.com/item.htm?id=672727759613)                                 |
| Cable Harness | 2        | YES      | 36920-0202        | [link](https://au.mouser.com/ProductDetail/Molex/36920-0202)                                                                                                  |
| Smooth Rod    | 2        | NO       | 6 mm              | [link](https://www.aliexpress.com/item/1005006293171727.html)                                                                                                 |

#### Fasteners

| Size  | Quantity | Type       |
|:----- |:--------:|:----------:|
| M2x4  | 3        | Hex Socket |
| M2x10 | 2        | Hex Socket |
| M3x5  | 2        | Hex Socket |
| M3x6  | 2        | Hex Socket |
| M3x6  | 1        | Grub Screw |
| M3x8  | 4        | Hex Socket |
| M3    | 3        | Hex Nut    |

### Assembly

This drawing should be referenced throughout the assembly process. It tells you what screws go where. There are also hyper-links to relevant images scattered throughout the assembly steps in case visual clarification is needed.

![Alt text](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/Assembly-Guide.PNG)

#### Tools Needed:

- H1.5 Hex Bit/Key
- H2.5 Hex Bit/Key
- Soldering Iron 
- Hammer (optional)
- Needle Nose Pliers (optional)
- Loctite (optional)

#### Preparing the Motor & Limit Switch

*NOTE:* Limit switch == SPDT switch

A good starting point is soldering the cable harnesses to the limit switch and motor. The orientation of the cable doesn't matter for either part, but the limit switch can be confusing since it has 3 pins. If your limit switch has the pin names de-bossed on it's case, e.g. "NC, NO, C" then the two pins we need are "NO" and "C". If it doesn't have the pin names on the casing, then position the switch on the machine housing as it should be when the unit is fully assembled (or see [here](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Limit-Switch.jpeg)). The bottom two pins are the ones we're interested in.

You can attach the limit switch to the machine housing now. It attaches using 2 M2x10 screws as shown in the drawing above.

#### Prepare the Motor Assembly

Insert the three M3 hex nuts into the [yoke](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/Hex-Nuts.jpeg). Depending on your printer tolerances, they may be difficult to get it. If that is the case, use a pair of needle nose pliers to *carefully* clamp each hex nut into plate. Once that's done, locate the hole on the side of the yoke for the M3x6 [grub screw](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Grub-Screw.jpeg) to go into. Screw in the grub screw using a H1.5 hex bit, don't fully insert it yet, just tighten until the threads engage with the hex nut. After that, you can insert the [yoke bearings](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Yoke-Bearings.jpeg) and tighten them fully. Set the yoke aside for the moment and move to the motor and mounting plate.

Place the motor into the mounting plate, lining up the two screw holes on the motor with the holes in the mounting plate. [Fasten the motor to the plate](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Mounting-Plate.jpeg) using two M3x6 screws, optionally adding a dab of loctite to each screw before tightening. Now you can slide the yoke onto the shaft of the motor, lining up the flat edge of the shaft with the hex nut/grub screw in the yoke. If you can't slide the yoke on, loosen the grub screw a little bit and try again. Then tighten the grub screw, securing the yoke on the shaft (tight enough that you can't full the yoke off, if the hex bit slips then you're more than good). The end product should look like [this](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Mounting-Plate-Finished.jpeg) / [this](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Mounting-Plate-Finished-B.jpeg). 

#### Prepare the Pistons

This step is very easy if you've tuned the print profile for the bearings to fit, but can be a bit of a pain otherwise. Since the bearings are press fit, the tolerances of the print are important. 

You just need to press fit the linear bearings (4 x LM6UU's) into the two pistons. The models current dimensions are perfect on my X1 Carbon and I can push them in by hand with a bit of force. If you can only get the bearing in partially by hand, use a hammer to very gently tap it in the rest of the way. Let gravity do the work with the hammer, too much force can break the print. If you find the bearing is too easy to push in, it's best if you go back and tune the print settings a bit more. Even though it may be difficult to pull the bearing back out, over time the plastic will stretch and you'll find the bearing comes out of the piston when in operation. You can add a dab of super-glue if you don't want to waste a print, but I don't recommend this since there may be room for the bearing to not be perfectly aligned.

If you have printed the off centre sleeves, attach them to the pistons now.

#### Install the Pistons

Keep in mind the orientation of the plates. The side with a chamfered slope should be facing the floor of the machine, and the flat edge should be facing upward.

Take one of the two 6 mm smooth rods and insert it into either of the openings just far enough to slide one of the pistons onto it, as shown [here](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Install-Pistons1.jpeg). After sliding the first piston onto the rod, push the rod through until it's approximately 3/4 of the distance to the socket on the other end. Slide on the second piston, then push the rod all the way into the socket as shown [here](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Install-Pistons1.jpeg). Install the second rod, lifting each piston and guiding it onto the rod, then install the two rod caps to secure them in place. The final result should look like [this](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Install-Pistons1.jpeg).

At this stage, test the pistons movement by sliding each back and forth. Push them from the centre of the plate, if there's uneven pressure the bearings won't move freely. If the pistons move back and forth with very little resistance, you're good to go! If they feel stiff or bumpy, check each bearing is sitting flat in the piston. If not, remove the piston and *very gently* tap the bearing with a hammer until it is sitting flat in the socket. 

#### Install the Motor Assembly

Twist the yoke so that it's [resting flat](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Mounting-Plate-Finished-B.jpeg). It's easiest if you insert the 4 M3x8 screws into the mounting plate before attempting to attach it. Screw them just far enough that the end of the screw is flush with the bottom of the mounting plate, then place the [motor assembly onto the posts](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/A_Install-Motor-Assembly.jpeg) before tightening it down. The screws will cut their own threads so don't worry if it feels difficult, just make sure that each screw is completely tightened down.

#### Install the PCB

*NOTE:* When connecting the switch and motor cables, make sure there are no MX switches in the machine and that the limit switch is completely open. Power the machine up once to confirm that the motor is spinning before inserting the switch trays. When switch trays are inserted, the limit switch will be held closed whilst the machine is off, meaning the boost converter output will be shorted to ground in the event that the cables are installed in the wrong positions.

Secure the PCB to the machine using 3 M2x4 screws. Connect the motor cable to the bottom right connector on the PCB labelled "MOTOR". Connect the limit switch cable to the connector labelled "COUNT", located directly above that of the motor.

### Testing & Notes

Your first time powering up the machine should be without any switches loaded. Supply power via a USB-C cable from a charger of your choice (chargers are discussed in the main readme). On first power up, the motor will remain off until the user holds down the top right button for 1 or more seconds. Hold the top right button for 1 second and then release it, the motor should start spinning. Press the limit switch down and confirm that the actuation counter incremented by 1. Pressing the top right button for less than 1 second will reset the count to 0. 

Once you have confirmed the machine is working, it's time to load it up with some switches and enjoy! For instructions and notes on general usage, please refer to the documentation on operation.
