## Building or Manufacturing the PCB

In terms of keeping track and managing batches of switches, the PCB has been an invaluable part of this project. Though it isn't necessary, it is incredibly helpful if you're looking for even results throughout a large batch. The firmware and final design are still a work in progress, lately it has taken a back seat as I've been working on other (volt-nut related) projects, but as I learn new things I come back and improve on different areas. 

![PCB 3D Render](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/PCB_3D.png)

**Who is this page for?** 

This page is primarily for those unacquainted with the process of ordering from JLCPCB. The ordering process is quite standard so those who understand it may skip the majority of this page, however I do suggest reading the notes section below as it contains some information on sourcing components for the BoM which are applicable to those assembling themselves AND through JLCPCB.

#### Notes:

The PCB was *mostly* designed around Mouser's inventory, so despite my efforts there are certain components that simply aren't available for JLCPCB assembly. Comparing the JLCPCB BoM (/PCB/jlcpcb/production_files/BOM-Boost-Converter.csv) to the iBoM (/bom/ibom.html), you'll notice that some component values have been changed. This is completely fine and should have no impact on operation. The closest value was chosen for components where values were critical, and for less critical components, values were chosen based on availability. 

Alternative parts have been listed where applicable, though currently the AP33772 is not available for JLCPCB assembly and will need to be sourced elsewhere. This chip can be omitted at the expense of USB-PD, not ideal but you can just use a beefy 5V charger and be fine. The biggest hurdle here is soldering its QFN package, which may be difficult/impossible depending on tools and skill. I am looking at changing this to a more convenient PD controller, but for now you can either bring your own or omit it entirely. Another component that needs to be sourced elsewhere is the AP7370-33W5 LDO, responsible for providing 3.3V to the RP200. This component is much easier to solder by hand, and is available from mouser along with the AP33772.

The SSD1306 display needs to be sourced and soldered by the user. I have ordered [these](https://www.aliexpress.com/item/32638662748.html) in bulk since they're so cheap, but they can be readily found from local hobby stores in most countries. It's important that you ensure the pinout is the same as the one linked, pin 1 being "GND" and pin 4 being "SDA", as there are some on the marked which have GND and VCC inverted. If sourcing this configuration is an issue in your country, it's easy enough to swap the pins in the design files, however I suggest ordering the correct configuration through AliExpress/TaoBao since they are significantly cheaper.

If you choose to source all of the components and assemble it yourself, the SDB628 (boost converter) can be had for around 20 cents each in low quantity from either AliExpress, Taobao or LCSC. Occasionally it can be sourced elsewhere, and there are several "drop in replacements" which seem to be the same silicon with a different label. One of these has been listed as an alternative, I haven't listed others as I have not personally verified they are the same (at least in function). Of course, this isn't ideal and I may change to an IC which can be sourced from mouser/digikey, but the price to performance of this chip is amazing and they're great to have on hand for other projects, so pick up some spares while you're at it!

### To Do:

- Tidy up the firmware to make it a more user friendly / smooth experience (I was still very new to programming & completely new to embedded programming, it ***needs*** to be cleaned up or re-written entirely when I have time).

- BoM optimisations for JLCPCB assembly.
  
  - Possibly replace the SDB628 with a more widely (mouser, digikey, etc.) available chip.

- Change to a more readily available USB-PD controller.
  
  - Looking at resistor configurable options.

### Ordering from JLCPCB

#### The PCB

Production files for JLCPCB can be found in the '/jlcpcb/production_files' directory. Navigate to the JLCPCB home page [jlcpcb.com](jlcpcb.com) and create / log into your account. Drag the zip file 'GERBER-Machine-Controller.zip' into the 'Add gerber file' drop box on the home page, or upload the file after clicking 'Instant Quote'. Once the upload has finished, you should be taken to the order page which will let you specify how the PCB is manufactured. All options can be left as default except for 'Remove Order Number' which should be set to 'Specify a location'. If you choose to order through another fab service, make sure you replace the silkscreen on the PCB (under the USB-C port) to correspond with that of your fab house. The order number will be hidden once the board is assembled, so don't feel you need to pay extra to have it removed.  Optionally select ENIG for the surface finish if you're happy to splurge a bit, I like doing this since it's easier to work with when assembling and the pads can take a bit more heat, but HASL is absolutely fine as well.

If you're assembling the PCB yourself, don't forget to order a stencil! I've done this more times than I care to admit, and hand soldering everything takes hours. You can save to cart and order now.

#### JLCPCB Assembly

At the bottom of the configuration page you'll find an option "PCB Assembly" which should be ticked. Initially the design was double sided, but for the sake of convenience and saving an extra set-up to assemble 5 parts, everything has been moved to the front layer. 

- For reference, one sided assembly is roughly 17 AUD and the price for both sides assembled was roughly 100 AUD, this is *before* component sourcing and fees. 

Tick the "Confirm Parts Placement" if you want to play on the safe side, sometimes JLCPCB's positioning tool which we come across later can show components rotated incorrectly or mirrored entirely (this is just a bug in their API, it happens no matter how I export production files/CPL file). Usually they fix this even if the option isn't ticked, but I can't guarantee that (logically they should fix any issues with placement since PNP would be impossible otherwise, I just don't want to promise something that I have no involvement in). Click the blue confirm button to proceed. 

You should have the options to upload the BOM (bill of materials) and CPL (component placement list) files. These can be found in the same location as the GERBER zip file uploaded earlier, upload these and select "Process BOM & CPL". The next page 

### Operation

It's relatively simple in it's operation. On start-up the RP2040 waits for the AP33772 to check for PD capabilities and negotiate the 9V, then the RP2040 sets itself up and checks it's flash memory to restore any information on the break-in process that was present before losing power. During the wake up process the RP2040 enables the boost converter, starting the motor. The screen displays the amount of actuations it has counted and saves this value to the flash memory every 10 seconds to avoid wearing down the memory write cycles. After 250,000 actuations are counted, the motor is disabled and the screen will prompt you to rotate the switch trays and press the reset (top right) button to continue. This is especially useful considering the off centre implementation. The angle the switches are actuated at isn't too aggressive, so running in off centre at all times was a very tempting idea. The only issue was ensuring each side received an even distribution of actuations, hence the introduction of the load disconnect function. The screen will tell you which rotation of the switch trays you are on, corresponding with the number on the side of the trays. 
