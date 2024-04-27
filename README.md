# INTRO
This module is a part of the GoKart Project in Hochschule Rhein-Waal.

The steering system has a potentiometer, which tracks rotation angle of the steering wheel. The class StPot presented in this file reads analog data and converts in into 2 Bytes: Most Significant(MSB) and Least Significant(LSB), in order to sent it with help of CAN communication.


# Set up
<ul>
  <li><p>StPot has 1 private attribute - attached pin. set during creation of an instance :</li>
    <code>StPot pot(A0);</code></p>
  <li>2 privite atrributes <b>msb</b> and <b>lsb</b> for processing</li>
</ul>

# Class methods
<ul>
  <li><p><code>int angleRead();</code></p></li>
    A wrap up for Standard Arduino method AnalodRead. Data is took from the pin assigned during creation of an instance of the class.
    Returns integer number.
  <li><p><code>void conv2bytes(int angle);</code></p></li>
    separates analog value into 2 Bytes. Input parameter - one integer number - measures from potentiometer. The method doesn't return anything, but rewrites private attributes of the rescpectful instance: <b>msb</b> and <b>lsb</b>.
</ul>

# Transmiting Analog Value with CAN BUS
by meance of 10-bit ADC in AVR ATmega 328p recieveing data from potentiometer is stored in an integer number in range 0-1023. Thus, required amount of bits in order to sent the value is 10.Since Bus can include 8 data bytes to send, only 2 bytes should be used for transmiting the analog value.
|0 | 0 | 0 | 0 | 0 | 0| 0 | 0 | 0 | 0 | 
| -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | --------- |
| |  | Most Significant Byte |  |  | | |  | Least Significant byte |  | 
