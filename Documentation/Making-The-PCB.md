## Building or Manufacturing the PCB

In terms of keeping track and managing batches of switches, the PCB has been an invaluable part of this project. Though it isn't necessary, it is incredibly helpful if you're looking for even results throughout a large batch. The firmware and final design are still a work in progress, lately it has taken a back seat as I've been working on other (volt-nut related) projects, but as I learn new things I come back and improve on different areas. 

#### Notes:

The PCB was mostly designed around Mouser's inventory, so despite my efforts there are certain components that simply aren't available for JLCPCB assembly. Comparing the JLCPCB BoM (/PCB/jlcpcb/production_files/BOM-Boost-Converter.csv) to the iBoM (/bom/ibom.html), you'll notice that some component values have been changed. This is completely fine and should have no impact on operation. The closest value was chosen for components where values were critical, and for less critical components, values were chosen based on availability. 

Alternative parts have been listed where applicable, though currently the AP33772 is not available for JLCPCB asembly and will need to be sourced elsewhere. This chip can be omitted at the expense of USB-PD, not ideal but you can just use a beefy 5V charger and be fine.

If you choose to source all of the components and assemble it yourself, the SDB628 (boost converter) can be had for around 20 cents each in low quantity from either Taobao or LCSC. This isn't ideal, but the price to performance of this chip is amazing, they're great to have on hand for any projects.

### To Do:

- Tidy up the firmware to make it a more user friendly / smooth experience.

- BoM optimisations for JLCPCB assembly.
  
  - Possibly replace the SDB628

- Change to a more readily available USB-PD controller.
  
  - Looking at resistor configurable options.

### Ordering from JLCPCB

### Operation

It's relatively simple in it's operation. On start-up the RP2040 waits for the AP33772 to check for PD capabilities and negotiate the 9V, then the RP2040 sets itself up and checks it's flash memory to restore any information on the break-in process that was present before losing power. During the wake up process the RP2040 enables the boost converter, starting the motor. The screen displays the amount of actuations it has counted and saves this value to the flash memory every 10 seconds to avoid wearing down the memory write cycles. After 250,000 actuations are counted, the motor is disabled and the screen will prompt you to rotate the switch trays and press the reset (top right) button to continue. This is especially useful considering the off centre implementation. The angle the switches are actuated at isn't too aggressive, so running in off centre at all times was a very tempting idea. The only issue was ensuring each side received an even distribution of actuations, hence the introduction of the load disconnect function. The screen will tell you which rotation of the switch trays you are on, corresponding with the number on the side of the trays. 
