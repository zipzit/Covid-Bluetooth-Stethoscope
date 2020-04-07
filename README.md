# A low cost open source DIY stethoscope design

(from [https://helpwithcovid.com/projects/252-bluetooth-stethoscope-pulse-oximeter](https://helpwithcovid.com/projects/252-bluetooth-stethoscope-pulse-oximeter))

This is a collaborative volunteer driven project to develop designs for low-cost stethoscopes, with designs for a basic amplifier + speaker model (<10 USD) and a Bluetooth model (<20 USD).

## The problem

High-quality stethoscopes are expensive, and stethoscopes in general are hard to sterilize.  This results in a use model where cheap stethoscopes are acquired by the hospital/clinic and one is assigned to each patient, with every professional who works with that patient using the same stethoscope.  This can result in cross-contamination as someone touches many stethoscopes.  Cheap stethoscopes also wear out quickly and have short hoses, resulting in professionals getting physically closer to the patient than necessary, particularly if they have to put their arm around the patient and listen to positions on the back.

With Covid-19 this is an even greater problem because medical professionals may be wearing full PPE and so would struggle to get a traditional stethoscope into their ears.

Like N95 masks and face shields, there is concern that stethoscopes may become a scarce commodity as the pandemic continues to spread, and poorer countries with weaker healthcare systems will particularly struggle to source in demand equipment.

## Our goal

To create stethoscope designs that reduce the risk of infection during use and cost of manufacture, and that can be built and validated by enthusiasts or manufacturers around the world, at price points that are viable in a variety of markets.

Current digital stethoscopes on the market start at $300-$500, and can go as high as $2700/unit. We are working towards the units being effectively disposable, to the point where if a hospital *had* to assign one to each patient and then throw it away when done it wouldn’t be a financial hardship.

In designing several different models we are targeting different price points and are able to deliver the simplest design fast.

## Our solutions

In order to reduce close physical contact between patient and medical professional we need a simple electronic device which can amplify or transmit the sound recorded by a microphone attached to a diaphragm. The simplest design just amplifies this sound to a speaker, contained in a single unit. A more advanced design will transmit that sound via Bluetooth to a headset worn by the medical professional. The units might either be disinfected between use on multiple patients, or simply discarded after use.

This project is developing rapidly and constantly evolving. We are starting with the simple amplifier + speaker, then moving to the Bluetooth design. All designs are intended to be constructed by anyone with some basic electronics knowledge and a soldering iron, and possibly access to a 3D printer.

Costs to build and timeframes for prototypes are very rough estimates.

### "Quick-and-dirty" speaker puck (~10USD, prototypes expected mid April)

The simplest possible design doesn’t use a headset at all - simply a single unit with a cup/microphone, a AA-battery-powered amplifier, and a speaker. We’re currently in the prototyping stage for this using off-the-shelf electronic components that anyone should be able to order online.  If possible, we would like to use existing containers - reusing standard pill bottles for instance - to avoid having to 3D-print a housing.

Sterilization is a factor as well.  If possible, using something like a pill bottle would provide a housing that can be easily sterilized.  If not possible, we can resort to putting units in ziploc bags that can be sterilized between patients.  

We still have some basic questions to answer to prove this solution will work - we have to be able to reliably reproduce the sounds that a sick patients’ lungs make.  We are doing research to develop an audio test library, but ultimately won’t be certain until we can get some units into the hands of professionals for testing.

### "Smarter" speaker puck (~20USD, prototypes expected late April - mid May)

One step up from there is to replace our simple analog electronics with some digital logic and a microprocessor.  We’re looking at the ESP32, which is common and relatively cheap, and there are a number of good development platforms on the market.  It comes with integrated bluetooth and wifi (which we would use for the next model), as well as lithium-ion battery charging logic.  This would allow us to potentially do some digital signal processing of the sound, to clear up noise or amplify certain frequencies.

This will build on the knowledge we gather about microphones and speakers and housings, and will likely require some software development.  It will take longer, so is the second stage solution.

### Smart Bluetooth puck (~30USD, prototypes expected May-June)

One step up from there is to enable bluetooth and the ability to pair with a set of over-the-ear headphones, worn by the medical professional over their PPE gear.  This will require some case redesign to allow for a small screen and some buttons, to allow selection of the bluetooth device to pair with.  Again, it builds off what we’ve learned from the previous design, and may require more software development.

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
