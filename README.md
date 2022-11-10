# ESPhome-IZAR-meter-reader
Measuring water consumption from a meter with IZAR interface using esphome simplicity.


Water meter reading solution with IZAR interface, without installing wmbusmeters. All you need is ESP826 or ESP32 and CC1101 radio chip.
I used the libraries:
https://github.com/maciekn/izar-wmbus-esp

File: izar_meter.h, place in esphome/custom_components/ directory. 
Copy the data from the water-meter.yaml file to the .yaml file generated in esphome's own sensor.... 
