power_measure_tool
==================

An Arduino setup to measure the voltage and current of a load.

<a href="misc/front.jpg"><img src="misc/front-small.jpg" align="centre" ></a>

<a href="misc/schematic.png"><img src="misc/schematic.png" align="centre" width="500" height="615" ></a>

This logical schematic differs slightly from the physical curcuit layout. The motor here acts as the load. The barrel jack is to indicate that the load is powered independently from the Arduino (USB) power supply.

##Parts List:
1. Arduino Uno R3
2. Adafruit INA219 High Side DC Current Sensor Breakout
3. Adafruit 1.3" 128x64 OLED set to I2C

##Results output:
The results are dynamically written to the Arduino serial port at 115200 baud, 8 data bits, no parity and 1 stop bit. A sample result is:  
1.987 5.080 0.3911 0.03805 5.118

1. Output power: 1.987 watts
2. Output voltage: 5.080 volts
3. Output current: 0.3911 amperes
4. Shunt voltage: 0.03805 volts
5. Input voltage: 5.118 volts (= output voltage + shunt voltage)

The output power is smoothed with the last 10 values (equivalent to 1 second worth of readings). The other readings are in their raw form.

##References
1. [Smoothing algorithm](http://arduino.cc/en/Tutorial/Smoothing)
