# IOT-Home-Security-System-with-Particle-Argon

With this project Home Security is at the touch of your fingers! Get notifications when your house door opens.
https://youtu.be/Q6tn-Bt9kHM

My basic purpose is to analyze which, why and how things are used in this project along with the code...

Hardware components

* 3 Particle Argon
* 3 Breadboard (generic)
* 2 Digilent Small Solderless Breadboard Kit
* 1 Jumper wires (generic)
* 3 Adafruit USB Li Ion Battery Charger
* 1 Laser Transmitter
* 1 Photo resistor
* 3 Buzzer
* 1 LED (generic)
* 1 Resistor 220 ohm

Software apps and online services

* Particle Build Web IDE
* Maker service	
* IFTTT Maker service
* Google Sheets	

Overview

Home security systems can be so expensive these days. It would be great if there was an easier, cheaper way to protect your home while you are away. Thankfully, you have arrived at the right place. This security-based project was chosen due to its continuous practicality. As long as there are houses whose owners like to monitor the activity in and outside, there is a need for a system to record and document that information. This project outlines how you can use a Particle Argon, IFTTT, and Google Sheets to create a simple, cheap home security system.

Hardware

This project requires three Argon boards with three different tasks. The first of which, Argon 1, is a laser emitting circuit, shown below. This Circuit contains a buzzer and a laser emitting diode.

The second circuit, Argon 2 is the laser receiving circuit, shown below. Consisting of a photo resistor, led, and buzzer this Argon communicates bidirectionally with both Argon 1 and Argon 3.

The final circuit, Argon 3, the data acquisition and transmission circuit is shown below. This circuit is much more simple, consisting of only an active buzzer. This Argon communicates with Argon 2 and IFTTT.

It is recommended that Argon 1 and 2 are each powered by a 3.7V Lipo battery with an amperage around 1000mah. For the sake of convenience and demonstration these items were not used in this project. The use of such batteries would allow the system to be compacted into a smaller, eye friendly application.

Project Construction Manual

1. Laser Transmission Circuit

* Connect Particle Argon to the main breadboard
* Connect Argon 3v3 to positive power rail and Argon ground to negative power rail
* Connect laser emitter to small breadboard and jump laser ports to power, ground, and pin D0, respectively
* Connect buzzer to main breadboard and jump buzzer ports to power, ground, and pin D4, respectively

2. Laser Receiving Circuit
* Connect Particle Argon to the main breadboard
* Connect Argon 3v3 to positive power rail and Argon ground to negative power rail
* Connect photoresistor to small breadboard and jump laser ports to power, ground, and pin D0, respectively
* Connect buzzer to main breadboard and jump buzzer ports to power, ground, and pin D8, respectively
* Connect led to main breadboard, with the positive lead in pin D9, the negative lead in a row on its own, and a resistor jumping the negative lead to the ground rail

3. Data Acquisition and Transmission Circuit
* Connect ParticleArgon to the main breadboard
* Connect Argon 3v3 to positive power rail and Argon ground to negative power rail
* Connect buzzer to main breadboard and jump buzzer ports to power, ground, and pin D4, respectively
**Note: active or passive buzzers may be used in the setup

IFTTT Integration

IFTTT was used in order to import data into a google spreadsheet and receive notifications on a cellular device.

Thank you
