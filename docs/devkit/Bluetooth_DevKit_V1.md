# Bluetooth Development Kit v1 #

This development kit is intended to put together the basic components of the initial bluetooth stethosope design into a platform that can be used for software development, microphone testing, and form-factor development.

It currently looks similar to this, with the addition of a screen:
<img src="/docs/devkit/images/devkit_breadboard.jpg" data-canonical-src="/docs/devkit/images/devkit_breadboard.jpg" width="400">

### Parts List:   (Product links are for examples, may not reflect the best source or price) ###
  - ESP32-WROOM-32 Development Board [Amazon] (https://smile.amazon.com/MELIFE-Development-Dual-Mode-Microcontroller-Integrated/dp/B07Q576VWZ)
  - I2C SPI Serial 128X64 OLED LCD Display [Amazon](https://smile.amazon.com/gp/product/B06XRBTBTB/)
  - Rotary Encoder [Amazon](https://smile.amazon.com/gp/product/B07R456WJ9/)
  - Adafruit Electret Microphone Amplifier - MAX9814 [Amazon](https://smile.amazon.com/gp/product/B00SLYAI9K)
  - Breadboards and wires [Amazon](https://smile.amazon.com/Standard-Jumper-Solderless-Prototype-Breadboard/dp/B07H7V1X7Y)
  - Micro-USB Cable [Amazon](https://smile.amazon.com/eTECH-Collection-MicroUSB-Cable-Motorola/dp/B07GH7Y4N8)
  - Stethoscope [Amazon](https://smile.amazon.com/Ever-Ready-First-Aid-Stethoscope/dp/B008BTYQQG/)
  - TODO:  Headphone jack interface for wand and wired headphones.
  - TODO:  Li-ION battery charging controller

### Software:  ###
  - Our fork of the ESP-IDF source [GitHub](https://github.com/admiralmaggie/esp32_bt_escope)
  
### Hardware Development ###
  - Would like to find a cost-effective way to acquire quality stethoscope bells without having to sacrifice entire stethoscopes.
  - The MEMS microphone doesn't actually fit inside the cut-off stethoscope tube, so is held on with electrical tape and hot glue.  Need to find a durable solution that allows a more integrated "wand" design, similar to this - a larger tube, a smaller microphone, a connector or shrink tubing:
    <img src="/docs/devkit/images/devkit_wand_concept_1.png" data-canonical-src="/docs/devkit/images/devkit_wand_concept_1.png" width="400">
  - The ESP32-WROOM platforms do not have an integrated lithium-ion battery controller (like the [ESP32 LoRa](https://smile.amazon.com/gp/product/B0781CPHT1/) does), need to work out a solution.

### Software Development ###
  - Need to port the U8glibv2 Arduino library to ESP-IDF for running the display, or find an existing port:  [GitHub](https://github.com/olikraus/u8g2)
  - Need to find or develop code to interface with the rotary encoder.

### Notes ###
  - Any ESP32 board with the ESP-WROOM-32 chip should work.
  - Any display with SSD13xx display controller should work.
  - The MEMSS microphone seems to give the best quality so far, although we have had good luck with a 2.6kHz or 1kHz piezo microphone attached to a MAX9814.
  