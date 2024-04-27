<!-- Introduction -->
<p>This file is a crucial component of the GoKart Project at Hochschule Rhein-Waal.</p>

<p>The steering system incorporates a potentiometer to track the rotation angle of the steering wheel. Within this file, the StPot class is implemented to read analog data and convert it into two bytes: the Most Significant Byte (MSB) and the Least Significant Byte (LSB), facilitating transmission via CAN communication.</p>

<!-- Setup -->
<ul>
  <li>
    <p>StPot has one private attribute: the attached pin, set during the instance's creation:</p>
    <code>StPot pot(A0);</code>
  </li>
  <li>
    <p>Two private attributes, <b>msb</b> and <b>lsb</b>, are utilized for processing.</p>
  </li>
</ul>

<!-- Class Methods -->
<ul>
  <li>
    <p><code>angleRead()</code>:</p>
    <p>This method wraps up the standard Arduino function <code>AnalogRead</code>, retrieving data from the assigned pin during the instance's creation. It returns an integer number.</p>
  </li>
  <li>
    <p><code>conv2bytes(int angle)</code>:</p>
    <p>This method separates the analog value into two bytes. The input parameter, an integer number, represents the measurement from the potentiometer. While the method doesn't return anything, it updates the private attributes <b>msb</b> and <b>lsb</b> of the respective instance.</p>
  </li>
</ul>

<!-- Transmitting Analog Value with CAN BUS -->
<p>To transmit data via CAN communication, the 10-bit ADC in the AVR ATmega328p is utilized to receive data from the potentiometer, producing an integer number ranging from 0 to 1023. Given that the CAN bus can include 8 data bytes for transmission, only 2 bytes are used to transmit the analog value.</p>

<p><b>Most Significant Byte (MSB)</b>:</p>
<p>The MSB represents the largest place value in the binary number, significantly contributing to the total value. It's extracted using bitwise operations.</p>

<p><b>Least Significant Byte (LSB)</b>:</p>
<p>The LSB is obtained by applying a mask, ensuring only the last two bits remain unchanged while others are set to 0.</p>

<p>Both MSB and LSB variables are declared as <b>uint8_t</b>:</p>
<ul>
  <li>Size: Guaranteed to be 8 bits.</li>
  <li>Range: Can represent values from 0 to 255.</li>
  <li>Signedness: Represents only non-negative numbers.</li>
  <li>Platform Independence: Maintains a consistent size across different architectures.</li>
  <li>Header: Defined in the <code>&lt;stdint.h&gt;</code> or <code>&lt;cstdint&gt;</code> header files in C, and in the <code>&lt;cstdint&gt;</code> header file in C++.</li>
</ul>
