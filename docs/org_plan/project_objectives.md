## Project objectives

This project was created by Dr. Brian L, a frontline doctor in San Diego, because of problems he was facing using standard stethoscopes while utilizing full-body PPE gear.  Our goal is simply to rectify these problems with cheap, easily-constructed designs that can be assembled and donated by the maker community.

## Current objectives
Our current focus is on prototyping our concept ideas and making sure they work well enough to become a development platform.  Once they do, we will create a bill of materials and documentation and make them available to volunteer developers and makerspaces.  We may possibly batch-order parts that could be made into development kits that could be sent to maker spaces or individuals, possibly including basic electronic equipment (soldering irons, etc) for developers unable to access tools currently.

Our primary "product" is the open-source designs and documentation needed to construct, program, and test devices that can be provided to medical professionals.

A secondary goal may be to source and provide development kits to makerspaces or individuals that can construct and test devices before donation.

Below are details on the problems, goals, and current designs:


### Problems with current stethoscope solution: ###
  - Stethoscopes are expensive and hard to disinfect, resulting in a situation where cheap, disposable stethoscopes are often left with
      a single patient for the duration of their stay (in developed countries). 
  - Cheap stethoscopes are quite short, forcing the medical professional's head closer to the patient, and for a longer time, than necessary.
  - A medical professional in full-head PPE gear will have a hard time getting a stethoscope into their ears in a safe manner.
  - Cheap stethoscopes are low-quality (poorer sound).
  - Cheap stethoscopes wear out quickly.

### The goals for our stethoscope solutions are: ###
  - A doctor *must* be able to hear a patient's lungs and heart in a hospital setting.
  - The device must be easily functional while the doctor is fully dressed in PPE.
  - Easily sterilizeable between patient contacts.
  - Constructed from parts we can source to make a sizeable quantity.
  - Get it done - as quick a turnaround as possible.
  
### Design constraints: ###
  - Allows the medical professional to maintain at least arm-length distance, and be easy to use while intubating.
  - Relatively inexpensive.  Such as, in the range where parts of the device(s) that come in contact with the patient
    are effectively disposable.
  - Easily sterilizeable, or be placed in a container/wrapping that is easily sterilizeable while still functioning.
  - Able to handle many sterilization cycles without degrading.
  - Battery life sufficient to handle a 10-hour shift before recharging or changing AA batteries.
  - Dead simple to configure, as few failure points as possible.
  - Constructed of easily-sourced or 3D-printed parts and able to be constructed with basic electronics tools and knowledge. 

### Other: ###
- If something works or doesn't work in the hospital setting currently, there's probably a really good reason for it.
- Don't re-engineer anything we don't have to.


## Current Solutions

In order to meet the design requirements above we need an electronic device which can amplify or transmit the internal sounds created by the heart and lungs. Our lowest-tech concept design is a single hand-held device which picks up the sounds with a microphone and amplifies it to a speaker. More advanced designs will transmit that sound via Bluetooth to an over-the-ear headset worn by the medical professional.

We are starting the simple amplifier + speaker and Bluetooth designs in parallel with the plan that learnings from one design can be applied to others. All designs are intended to be constructed by anyone with some basic electronics knowledge and a soldering iron, and possibly access to a 3D printer.

### "Quick-and-dirty" speaker puck

The simplest concept doesn’t use a headset at all - simply a single unit with a cup/microphone, a AA-battery-powered amplifier, and a speaker. We’re currently in the prototyping stage for this using off-the-shelf electronic components that anyone should be able to order online.  If possible, we would like to use existing containers - reusing standard pill bottles for instance - to avoid having to 3D-print a housing.

Sterilization is a factor as well.  If possible, using something like a pill bottle would provide a housing that can be easily sterilized.  If not possible, units can be placed in ziploc bags that can be sterilized between patients.  

#### Current status:
We still have some basic questions to answer to prove this solution can reliably reproduce and amplify lung sounds.  We have constructed a concept unit, but decent sound quality without creating feedback is proving to be a significant roadblock.  We are testing different directional microphones, mimicing stethoscope architecture, adding insulation between microphone and speaker, and exploring a setup with two units separated by a short cable.

Standard stethoscopes are highly specialized pieces of equipment that have been refined continually over the last 200 years.  We have been learning a great deal about why they are the way they are and the frequency filtering functions inherent in the design. 


### "Smarter" speaker puck

One step up from there is to replace our simple analog electronics with some digital logic and a microprocessor.  We’re looking at the ESP32, which is common and relatively cheap, and there are a number of good development platforms on the market.  It comes with integrated bluetooth and wifi (which we would use for the next model), as well as lithium-ion battery charging logic.  This would allow us to potentially do some digital signal processing of the sound, to clear up noise or amplify certain frequencies.

This will build on the knowledge we gather about microphones and speakers and housings, and will likely require some software development.  It will take longer, so is the second stage solution.

#### Current status:

We have been working with two different ESP32 development boards - the ESP32-LoRa, and the ESP32 Lyra-T Mini:

Using the Lyra-T Mini we have constructed a prototype which uses a microphone inside a standard stethoscope bell and broadcasts via bluetooth to a standard bluetooth-enabled speaker.  Heart sounds appear clear and audible though a Bose Soundlink bluetooth speaker, we need more work to determine if we can reproduce decent sound quality with an onboard speaker.  The Lyra-T Mini is approximately $22/unit and has extra on-board audio codecs and ADCs.

<img src="/images/bt_prototype_1.jpg" data-canonical-src="/images/bt_prototype_1.jpg" width="400" >

Using the LoRa, we have tested that we can pair reliably with most standard bluetooth devices, and recover the connection if one side of the link is reset.  We have modified the Espressif-provided open-source software to do this.  The LoRa has also had issues with the I2S DMA ADC operating while bluetooth is functional.  We filed a support ticket with Espressif and they have been responsive and provided a fix.  The LoRa is slightly cheaper and smaller than the Lyra-T and comes with an onboard screen.  We would like this board as a development option, but it would require adding an addition codec/ADC chip - likely the ES8388, which is approximately $.90. 


### Smart bluetooth puck

One step up from the quick-and-dirty speaker puck is to include an enable bluetooth and include a small screen for the ability to pair with a set of over-the-ear headphones, worn by the medical professional over their PPE gear.  This will require some case redesign to allow for a small screen and some buttons, to allow selection of the bluetooth device to pair with, and some additional software development.

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

### Other
We have been looking more at developing a custom PCB-based design with the specific components we need for the bluetooth-enabled solutions.

We have also evaluated some product solutions that are currently on the market.  They are either prohibitively expensive ($200-$2000), require an expensive phone/tablet as part of the solution, or don't provide the required sound quality.

### Unit testing collateral

Ultimately people who are constructing units will want standard metrics to test their units against.  We have audio recordings of lung sounds that we can devleop into an audio test library.  Another open-source medical devices organization (glia.org) has developed some promising-looking testing procedures using water balloons to mimic a human body.

For initial devices we will simply try to get them in the hands of trained medical professionals for testing, but ultimately want to develop a standardized test plan.

