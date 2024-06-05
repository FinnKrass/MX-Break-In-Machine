## Powering Your Machine

Though the machine is capable of being powered from a standard 5V wall wart/charger, I advise against it for reasons discussed in this document. A charger such as [this](https://www.amazon.com.au/HEBA-Charger-Adapter-Delivery-certified/dp/B096WF4SF2), rated for 20W or greater is more than ample. 

### Reasons for Using USB-PD

Due to the design of the machine, the motor has to exert a *lot* of force when it first starts compared to when it's in operation. This results in a small (~30mA) initial current draw while the RP2040 wakes up, followed by an immediate spike as the boost converter is enabled and the motor receives power. Many low powered / cheap wall wart chargers don't handle this well, causing the motor to stall and controller to lose power. This presents itself in the form of the motor 'pulsating' as it attempts to start, getting caught in that cycle. 

There are two strong advantages to using USB Power Delivery:

- PD capable chargers can supply more power out of the gate, giving the machine more room to breath during the start up process. 

- Boosting 5V to 24V is relatively inefficient in both conversion and conversion losses. Using PD to provide 9V means the switching duty cycle is at a more comfortable level and the range of current consumption is smaller and thus more manageable by the charger.
  
  - USB-PD chargers are also more capable of dealing with dynamic loads such as this.

Though the Power Delivery standard allows for much more power than we utilize, including up to 24V which could directly power the motor, 9V has been selected in order to keep the simple (and low cost) LDO regulator used for supplying 3.3V to the micro-controller. Additionally, using a boost converter allows us to set the speed of the motor via a simple switch which selects between two resistors in the boost converter's feedback network. The boost converter outputs 18V when the switch is set to *75%*, and 24V when set to *100%*.

To **visualize** this, I've compared the *input* current and output voltages for 5V and 9V input. This was just a quick test performed to help explain the reasoning behind the decision to use USB-PD. The sampling rate of my power supply is painfully slow and misses some of the more insightful behaviour.

#### 5V Input

![5Vin](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/Boost-Converter-Characteristics/Current-Consumption-5Vin.png)

#### 9V Input

![9V Input](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/Boost-Converter-Characteristics/Current-Consumption-9Vin.png)

#### Current Limited Stall

![Current Limited](https://github.com/FinnKrass/MX-Break-In-Machine/blob/main/Images/Boost-Converter-Characteristics/Current-Limited-Stall-Start.png)
