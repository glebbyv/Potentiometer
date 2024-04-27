# INTRO
This module is a part of the GoKart Project in Hochschule Rhein-Waal.

The steering system has a potentiometer, which tracks rotation angle of the steering wheel. The class StPot presented in this file reads analog data and converts in into 2 Bytes: Most Significant(MSB) and Least Significant(LSB), in order to sent it with help of CAN communication.


# Set up
<ul>
  <li><p>StPot has 1 private attribute - attached pin. set during creation of an instance :</li>
    <code>StPot pot(A0);</code></p>
</ul>
