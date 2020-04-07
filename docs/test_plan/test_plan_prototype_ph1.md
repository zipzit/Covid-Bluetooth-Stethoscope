#  Quick and Dirty Speaker
*(Note, Quick and Dirty Speaker design only uses analog components)*

## Prototype Test Plan

### Equipment

Received first shipment of Digikey component parts.  7Apr2020
 - Access to Shop Power supply, Model: GPC-3020
 - Analog oscilloscope
 - Basic Electronic Hand Tools
 - Decent volt-ohmmeter
 - 3D Printer (PLA & ABS material)

### Target Goals
Understand if initial design decisions are sound
 - Was 3 watts the right power target for amplified audio system?
 - Is feedback between Microphone and Speaker an issue for us?
 - Understand the relationship between battery power and amplification.  What system voltage should we be using (3.0v or 4.5v or something else).
 - Quantify current draw in different use conditions, predict expected battery life for our use case.
 - Does a variation in microphone supply power affect audio output?


Understand which microphone makes the most sense for us
 - Analog MEMS vs Electret Condenser Element?
 - UniDirectional vs OmniDirectional?
 - Noise filtering vs not?
 - CUI Mic Dev Kit, MIC5=MEMS Omni, MIC6=Electret Noise Cancelling, MIC7=Electret Uni , MIC8=Electret Omni

### Question for EE folks... can we look at microphone circuit output on an oscilloscope with a focus on amplitude peak height and use that as a quantifiable indicator of microphone performance ?? ###

 Take an initial stab at the input bell 3d Design
 - Shallow cone (like the GliaX Design)
 - Deeper cone


 Figure out the resistance value for the volume adjust potentiometer.
 Spec sheet for the AdaFruit amplifier suggested 50KΩ, but we were unable to find any of those parts available with convenient integral on-off switch.  Although that design exists, suppliers are all out of stock. 10KΩ and 100KΩ Logarithmetic on-off & potentiometer components are available.

 - 10KΩ Logarithmetic
 - 50KΩ Logarithmetic
 - 100kΩ Logarithmetic


 Was Logarithmetic potentiometer the correct choice for our analog design?  *If necessary* borrow linear components from friend and test:
 - Logarithmetic
 - Linear  


 Speaker Manufacturer?  We picked two different 3 watt speakers.  Does that make a difference?
 - 	PUI Audio, Inc.	Mfgr PN: AS04004PR-R
 - 	DB Unlimited  Mfgr PN: SP520104-1


## Lets Start Testing
 - Figure out who's going where and when.  
 - Add soldered on pins or sockets to each component accordingly. Plug and Play !!


 ### Dual Power Supply testing
 Setup dual power supply.  Power microphone separately from audio amp. Simple benchtop testing.  The intent is to optimize power choices, then test, lock that in, go to one power supply and measure current draws in next phase.  

#### #Prototype_phase_one_#1
 - PUI speaker
 - Adafruit audio amp (4.5v input power)
 - MIC5, no hockey puck cone  (target 2.0v supply power, min=1.6v, max=3.6v)
 - Vary audio input voltage from 3v to 6v.  What happens?  Take notes...
 - Vary mic power, results?

#### #Prototype_phase_one_#2
 - PUI speaker
 - Adafruit audio amp (4.5v input power)
 - MIC6, no hockey puck cone  (target audio amp Vdd as mic supply power, min=2.0v, max=10v)
 - Vary audio input voltage from 3v to 6v.  What happens?  Take notes...
 - Vary mic power, results?

#### #Prototype_phase_one_#3
 - PUI speaker
 - Adafruit audio amp (4.5v input power)
 - MIC7, no hockey puck cone  (target audio amp Vdd as mic supply power, min=2.0v, max=10v)
 - Vary audio input voltage from 3v to 6v.  What happens?  Take notes...
 - Vary mic power, results?

#### #Prototype_phase_one_#4
 - PUI speaker
 - Adafruit audio amp (4.5v input power)
 - MIC8, no hockey puck cone  (target audio amp Vdd as mic supply power, min=2.0v, max=10v)
 - Vary audio input voltage from 3v to 6v.  What happens?  Take notes...
 - Vary mic power, results?
