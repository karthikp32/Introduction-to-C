Ones' Complement

Class of Problems/Use Cases that Ones' Complement Is Useful For:
1) Used to calculate Internet Checksum in internet protocols like Internet Protocol version 4 (IPv4),
Transmission Control Protocol (TCP), and User Datagram Protocol (UDP)
2) Lot of machines like the US Government machines where the CPU was implemented with One's Complement

To find Ones' Complement, flip of all of the bits

For ex. 0010 ---> 2 becomes 1101 ---> -2 when using Ones' Complement notation
and allows us to represent negative numbers



Two's Complement

Class of Problems/Use Cases that Ones' Complement Is Useful For:
1) Circuitry for addition and subtraction can be consolidated into one adder unit 
within the Arithmetic Logic Unit

To Find Two's Complement
1) Flip the bits and add 1

In Two's Complement Notation
2 ---> 0010
-2 --> 1101 + 1 = 1110

Left most bit can be considered "biased" bit where it is the negative
of its usual value. 

    -8 4 2 1
     | | | |
     1 1 1 0

  2^3 digit represents -2^3 = 8
  2^2 digit represents 2^2 = 4
  2^1 digit represents 2^1 = 2
  2^0 digit represents 2^0 = 1
  
In this case, 1110 can be convert to decimal by -8 + 4 + 2 = -2   


When does integer overflow happen?
Integer overflow is when you try to store a number in bits
larger than the bits can support.

For ex. Integer overflow can happen when you try to 16 in a 4 bits
since that is larger than the largest number you can store in 4 bits,
1111 which is 8 + 4 + 2 + 1 = 15

