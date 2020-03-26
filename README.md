# Smart-Food-Monitor
It is an hardware project for Monitoring the environment where foods are being stored.
It monitors the Temperature , Humidity , Light Exposure and Odour presence in the environment and displays it in an LCD monitor.
It gives notification by making sound and glowing an "Warning" LED.

# Components Used
* Arduino UNO
* MQ3 Alcohol Sensor
* LDR
* DHT11 Temperature and Humidity Sensor
* 16 x 2 LCD Display
* Connecting Wire
* DC Power Supply

# Circuit Diagram
![](https://github.com/ArafatRohan93/Smart-Food-Monitor/blob/master/foodCircuitio.png)

# Arduino Code
**First make it sure you know about the sensors and Arduino.**

DHT11 library is [here](https://github.com/ArafatRohan93/Smart-Food-Monitor/tree/master/libraries).

[Click Here](https://github.com/ArafatRohan93/Smart-Food-Monitor/blob/master/food.ino) for the code!


# Project Photos

<img src="https://github.com/ArafatRohan93/Smart-Food-Monitor/blob/master/BadFood1st.png" width="700" height="400">
<img src="https://github.com/ArafatRohan93/Smart-Food-Monitor/blob/master/BadFood2nd.png" width="700" height="400">
<img src="https://github.com/ArafatRohan93/Smart-Food-Monitor/blob/master/1.jpg" width="700" height="400">
<img src="https://github.com/ArafatRohan93/Smart-Food-Monitor/blob/master/2.jpg" width="700" height="400">
<!--
![](https://github.com/ArafatRohan93/Smart-Food-Monitor/blob/master/BadFood1st.png =150x150)
![](https://github.com/ArafatRohan93/Smart-Food-Monitor/blob/master/BadFood2nd.png =150x150)
![](https://github.com/ArafatRohan93/Smart-Food-Monitor/blob/master/1.jpg =150x150)
![](https://github.com/ArafatRohan93/Smart-Food-Monitor/blob/master/2.jpg =150x150)
-->

# How it works

 DHT11 Temperature and Humidity Sensor is a digital sensor with inbuilt capacitive humidity sensor and Thermistor. It relays a real-time temperature and humidity reading every 2 seconds. The sensor operates on 3.5 to 5.5 V supply and can read temperature between 0° C and 50° C and relative humidity between 20% and 95%.The sensor cannot be directly interfaced to a digital pin of the board as it operates on 1-wire protocol which must be implemented only on the firmware. First the data pin is configured to input and a start signal is sent to it. The start signal comprises of a LOW for 18 milliseconds followed by a HIGH for 20 to 40 microseconds followed by a LOW again for 80 microseconds and a HIGH for 80 microseconds. After sending the start signal, the pin is configured to digital output and 40-bit data comprising of the temperature and humidity reading is latched out. Of the 5-byte data, the first two bytes are integer and decimal part of reading for relative humidity respectively, third and fourth bytes are integer and decimal part of reading for temperature and last one is checksum byte.  
 
For Arduino, standard library for DHT-11 sensor is already available. The data from the sensor can be easily ready by calling read11() method of the DHT class.  The LDR sensor is connected in a potential divider circuit and inputs a voltage at the analog input pin of the controller. The voltage is read and digitized using in-built ADC channel.  The MQ3 sensor detects the emission of ethanol type of gases. If the food/fruits get spoiled, they emit the ethanol type of gases. The MQ3 sensor detects the concentration of such gases and output an analog voltage proportional to the concentration of the gas. The analog output is passed to the analog pin of the Arduino which has inbuilt ADC that coverts the analog to digital value. The Arduino collects data from all the sensors and convert the values to the strings. The sensor data wrapped as proper strings are passed to the character LCD for display.      
 
