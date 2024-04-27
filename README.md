# Introduction
This module is a component of the GoKart Project at Hochschule Rhein-Waal.

The steering system incorporates a potentiometer to track the rotation angle of the steering wheel. Within this file, the StPot class is implemented to read analog data and convert it into two bytes: the Most Significant Byte (MSB) and the Least Significant Byte (LSB), facilitating transmission via CAN communication.

# Transmitting Analog Value with CAN BUS
To transmit data via CAN communication, the 10-bit ADC in the AVR ATmega328p is utilized to receive data from the potentiometer, producing an integer number ranging from 0 to 1023. Given that the CAN bus can include 8 data bytes for transmission, only 2 bytes are used to transmit the analog value.


- **Most Significant Byte (MSB)**:
    The MSB represents the largest place value in the binary number, significantly contributing to the total value. It's extracted using bitwise operations.

- **Least Significant Byte (LSB)**:
    The LSB is obtained by applying a mask, ensuring only the last two bits remain unchanged while others are set to 0.

  
Both MSB and LSB variables are declared as **uint8_t**:
- **Size**: Guaranteed to be 8 bits.
- **Range**: Can represent values from 0 to 255.
- **Signedness**: Represents only non-negative numbers.
- **Platform Independence**: Maintains a consistent size across different architectures.
- **Header**: Defined in the <stdint.h> or <cstdint> header files in C, and in the <cstdint> header file in C++.

# Setup
- StPot has one private attribute: the attached pin, set during the instance's creation:
    ```cpp
    StPot pot(A0);
    ```
- Two private attributes, **msb** and **lsb**, are utilized for processing.

# Class Methods
- **angleRead()**:
    This method wraps up the standard Arduino function AnalogRead, retrieving data from the assigned pin during the instance's creation. It returns an integer number.

- **conv2bytes(int angle)**:
    This method separates the analog value into two bytes. The input parameter, an integer number, represents the measurement from the potentiometer. While the method doesn't return anything, it updates the private attributes **msb** and **lsb** of the respective instance.

<ul>
  <li><b>MSB:</b> Obtained through bitwise right shift operation.</li>
  <p><code>msb = angle >> 2;</code></p>
  <p>Each bit is shifted two positions to the right. Consequently, only the first (leftmost) bits are retained and stored in the variable <code>msb</code>.</p>
  
  <li><b>LSB:</b> Obtained by applying a bit mask.</li>
      <p><code>lsb = angle & 3;</code></p>
  Alternatively represented in binary as: 
     <p><code>lsb = angle & 0b00000011;</code></p>
  <p>As a result, only the two rightmost bits remain unchanged, while all other bits are set to 0.</p>
</ul>
