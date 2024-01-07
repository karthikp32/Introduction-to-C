4 Bitwise Operators: AND (&), OR (|), XOR(^), NOT(~)

Class of Problems that AND Operator Can Be Useful For:
1) keeping the same value, 0 or 1, for certain bits in the original binary number
2) Only keeping certain bits ON
3) Clear the original bits regardless of whether the original bit was 1 or 0 by ANDing with 0
4) Keep the original bit as 1 or 0 by ANDing with 1

To keep only certain bits ON, you can AND original number
by a new number with 1 in places corresponding to the bits you want to keep

For ex.     To keep the last two 1 bits of the original number on         10000011
            you can AND it by 00001111                              &     00001111
            which will clear the high-order/left most 1             =     00000011
            and only the last 2 bits will be on                                                                                           

To clear certain bits, you can AND original number
by a new number with 0 in places corresponding to the bits you want to clear

    1110
  & 0000
    0000

    
 Class of Problems that OR Operator Can Be Useful For:
1) To always keep some bit on. You might want always set the leftmost bit to be 1
because want all numbers to be negative and these numbers are part of a signed bit system


For ex. To turn 4 into -4 in a signed binary number system, you can do
   4 -> 0100
    |   1000
  -4 -> 1100

  2) Suppose you wanted to switch the owner of a file directory from having only user permissions to
admin permissions, you can use OR to set all of the bits

    001 --> Only allowed to read  <-- User
|   111 
=   111 --> allowed to read/write/execute <-- Admin


 Class of Problems that XOR Operator Can Be Useful For:
 1) Encryption - you can use a binary number with XOR as an encryption key to 
 encrypt the 1s and 0s of plaintext into 1s and 0s ciphertext.
 Your friend can use the same key as decryption to convert
 the ciphertext back into the plaintext. 

    For ex. 
                     Plaintext ---->  10110111
    Encryption-----> Key ----------> ^11111111
                     Ciphertext ----> 01001000

                     Ciphertext ----> 01001000
    Decryption-----> Key ----------> ^11111111
                     Plaintext -----> 10110111

 Class of Problems that NOT Operator Can Be Useful For:
1) Flip all of the bits

    NOT(~) 1011
         = 0100 


Bit Masking: You put a mask on the original binary number so it looks different and you
have cleared some bits and set some bits

For ex. 
    1001
 &  0001
 =  0001

 You have put a mask on the 3 leftmost/high-order bits and cleared them





Q: What is the Difference Between Signed Binary Numbers And Unsigned Binary Numbers?
A: Signed binary numbers can represent positive, 0, and negative numbers
while unsigned binary numbers can represent only 0 and positive numbers.