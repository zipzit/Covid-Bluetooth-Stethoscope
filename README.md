# Project description:  low-cost open-source DIY wireless stethoscope designs

(from [https://helpwithcovid.com/projects/252-bluetooth-stethoscope-pulse-oximeter](https://helpwithcovid.com/projects/252-bluetooth-stethoscope-pulse-oximeter))

This is a collaborative volunteer driven project to develop designs for low-cost wireless stethoscopes that can be constructed with hobbyist-level skill and tools and provided to medical professionals using the same volunteer-driven model current being used to create and donate face shield and masks world-wide.


## The problem

High-quality stethoscopes are expensive, and stethoscopes in general are hard to sterilize.  This results in a use model where cheap stethoscopes are acquired by the hospital/clinic and one is assigned to each patient, with every professional who works with that patient using the same stethoscope.  This can result in cross-contamination as someone touches many stethoscopes.  Cheap stethoscopes also wear out quickly and have short hoses, resulting in professionals getting physically closer to the patient than necessary, particularly if they have to put their arm around the patient and listen to positions on the back.

With Covid-19 this is an even greater problem because medical professionals may be wearing full PPE and struggle to get a traditional stethoscope into their ears safely.

Like N95 masks and face shields, there is concern that stethoscopes may become a scarce commodity as the pandemic continues to spread, and poorer countries with weaker healthcare systems will particularly struggle to source in-demand equipment.


## Our goal

To create stethoscope designs that reduce the risk of infection during use and cost of manufacture, and that can be built and validated by enthusiasts or manufacturers around the world, at price points that are viable in a variety of markets.

Current digital stethoscopes on the market start at $300-$500, and can go as high as $2700/unit. We are working towards the units being effectively disposable, to the point where if a hospital *had* to assign one to each patient and then throw it away when done it wouldn’t be a financial hardship.

In designing several different models we are targeting different price points and are able to deliver the simplest design fast.


## Our solutions

In order to reduce close physical contact between patient and medical professional we need an electronic device which can amplify or transmit the internal sounds created by the heart and lungs. Our lowest-tech concept design is a single hand-held device which picks up the sounds with a microphone and amplifies it to a speaker. More advanced designs will transmit that sound via Bluetooth to an over-the-ear headset worn by the medical professional. Our goal is to have the units be easily disinfected between uses so they can be utilized on multiple patients, but cheap enough that if necessary they could be assigned to a single patient as is the case with current stethoscopes.

This project is developing rapidly and constantly evolving. We are starting the simple amplifier + speaker and Bluetooth designs in parallel with the plan that learnings from one design can be applied to others. All designs are intended to be constructed by anyone with some basic electronics knowledge and a soldering iron, and possibly access to a 3D printer.


### "Quick-and-dirty" speaker puck

The simplest concept doesn’t use a headset at all - simply a single unit with a cup/microphone, a AA-battery-powered amplifier, and a speaker. We’re currently in the prototyping stage for this using off-the-shelf electronic components that anyone should be able to order online.  If possible, we would like to use existing containers - reusing standard pill bottles for instance - to avoid having to 3D-print a housing.

Sterilization is a factor as well.  If possible, using something like a pill bottle would provide a housing that can be easily sterilized.  If not possible, units can be placed in ziploc bags that can be sterilized between patients.  

#### Current status:
We still have some basic questions to answer to prove this solution can reliably reproduce and amplify lung sounds.  We have constructed a concept unit, but decent sound quality without creating feedback is proving to be a significant roadblock.  We are testing different directional microphones, mimicing stethoscope architecture, adding insulation between microphone and speaker, and exploring a setup with two units separated by a short cable. 


### "Smarter" speaker puck

One step up from there is to replace our simple analog electronics with some digital logic and a microprocessor.  We’re looking at the ESP32, which is common and relatively cheap, and there are a number of good development platforms on the market.  It comes with integrated bluetooth and wifi (which we would use for the next model), as well as lithium-ion battery charging logic.  This would allow us to potentially do some digital signal processing of the sound, to clear up noise or amplify certain frequencies.

This will build on the knowledge we gather about microphones and speakers and housings, and will likely require some software development.  It will take longer, so is the second stage solution.

#### Current status:
We have been working with two different ESP32 development boards - the ESP32-LoRa, and the ESP32 Lyra-T Mini:

Using the Lyra-T Mini we have constructed a prototype which uses a microphone inside a standard stethscope bell and broadcasts via bluetooth to a standard bluetooth-enabled speaker.  Heart sounds appear clear and audible though a Bose Soundlink bluetooth speaker, we need more work to determine if we can reproduce decent sound quality with an onboard speaker.  The Lyra-T Mini is approximately $22/unit and has extra on-board audio codecs and ADCs.

Using the LoRa, we have tested that we can pair reliably with most standard bluetooth devices, and recover the connection if one side of the link is reset.  We have modified the Espressif-provided open-source software to do this.  The LoRa has also had issues with the I2S DMA ADC operating while bluetooth is functional.  We filed a support ticket with Espressif and they have provided a fix.  The LoRa is slightly cheaper and smaller than the Lyra-T and comes with an onboard screen.  We would like this board as a development option, but it would require adding an addition codec/ADC chip - likely the ES8388, which is approx. $1. 


### Smart bluetooth puck

One step up from there is to enable bluetooth and the ability to pair with a set of over-the-ear headphones, worn by the medical professional over their PPE gear.  This will require some case redesign to allow for a small screen and some buttons, to allow selection of the bluetooth device to pair with.  Again, it builds off what we’ve learned from the previous design, and may require more software development.

To work towards a completed design we need to:
- Integrate the stethoscope cup or accept one attached by a short tube with a microphone.
- Develop whatever DSP (Digital Signal Processing) algorithms are necessary for noise/frequency filtering or shifting.
- Find an onboard amplifier/speaker solution that can reliably reproduce lung sounds with sufficient volume. 

#### Current status:
The "Smarter" Speaker Puck and Smart Bluetooth Puck are basically the same project at this point.  Our current prototype uses a standard stethoscope cup to pick up sounds, and a bluetooth link to connect to an external speaker.

To work towards a completed design we need to:
- Integrate the stethoscope cup or accept one attached by a short tube with a microphone.
- Integrate a screen that will show available bluetooth devices to pair with. (Requires software development)
- Test connections and audio quality with different bluetooth headsets (the cheaper the better).


### Unit testing collateral

Ultimately people who are constructing units will want standard metrics to test their units against.  We have audio recordings of lung sounds that we can devleop into an audio test library.  Another open-source medical devices organization (glia.org) has developed some promising-looking testing procedures using water balloons to mimic a human body.

For initial devices we will simply try to get devices in the hands of trained medical professionals for testing, but ultimately want to develop a standardized test plan.


### However...

Having said all of this, we are not inherently attached to these solutions.  We continue to look at alternate solutions (such as repurposing cheap earpods) to see if we can create better, cheaper, or more "quick-and-dirty" designs.


## What do we need?

We have a diverse, fast moving team of volunteers and are always looking for more support. If there is anything you are able to offer, please reach out to us, we are very welcoming of new team members.

Some skills we are particularly in need of:

* Electronics knowledge
* Software developers
* CAD engineers
* People who have 3D printers
* People to write documentation
* Fundraisers
* Project managers
* All-rounders!
* Manufacturers/distributors who think they could help

If you’re interested, please join through our [HelpWithCovid](https://helpwithcovid.com/projects/252-bluetooth-stethoscope-pulse-oximeter) page, and add us as a project you are interested in.  This will generate a message to us, and we can add you to the GitHub and you can join our Discord channel.

Thank you for reading this, and hope to see you soon!
