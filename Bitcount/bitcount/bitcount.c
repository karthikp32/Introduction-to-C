#include <assert.h>
#include <stdio.h>
#include <nmmintrin.h>

//count number of bits that are on = 1 bits
//designating number as an unsigned int
//changes it from being a signed int as ints 
//are by default and prevents 1 from being 
//added to the leftmost bit to keep the "negative"
//sign for signed negative ints
//>> acts as arithmetic right shift operator on signed ints
//as it rights shifts the bits N positions and keeps the sign
//>> acts as logical  right shift operator on unsigned ints
//and only right shifts the bit N positions and doesn't keep the sign
int bitcount(unsigned int number) {
    //Example:
    //7 % 2 = 1
    //3 % 2 = 1
    //1 % 2 = 1
    //111 equals 7 in binary

    //7
    //111
    //& 1
    //001

    //8
    //1000
    // & 1
    //0000   

  //Example:
    //8 % 2 = 0
    //4 % 2 = 0
    //2 % 2 = 0
    //1 % 2 = 1
    //0
    //1000


    //while decimal is > 0
    //mod decimal by 2 and store in currRem
    //if currRem == 1, onBitCount++
    //dividing decimal by 2
    //time: O(log2n)
    //space: O(1)


    return __builtin_popcount(number);
}


//Problem: X &= X - 1 deletes the rightmost 1 bit. Explain why.
//Use this observation to write a faster version of bitcount()
//Explanation: It's X - 1 will have 0 in the same position 
//as the rightmost 1 of X
int fasterbitcount(unsigned int number) {
//Examples:
//  1000  <-- 8
//& 0111  <-- 7
//  0000


//  0101  <-- 5
//& 0010  <-- 4
//  0000

//  0110  <-- 6
//& 0101  <-- 5
//  0100

//Approach 1:
//Keep deleting the rightmost 1's until number equals 0
//while number > 0
//  X &= X - 1
//  bitCount++

//there would only be 3 iterations in the while loop instead of 32 iterations
//for counting bits of 11100000000000000000000000000000
    int onBitCount=0;
    while (number > 0) {
        number &= number - 1;
        onBitCount++;
    }
    return onBitCount;

}

int main() {
    assert(bitcount(0) == 0); //0
    assert(bitcount(1) == 1); //1
    assert(bitcount(3) == 2); //11
    assert(bitcount(8) == 1); //1000
    // harder case:
    assert(bitcount(0xffffffff) == 32);
    printf("OK\n");

    assert(fasterbitcount(0) == 0); //0
    assert(fasterbitcount(1) == 1); //1
    assert(fasterbitcount(3) == 2); //11
    assert(fasterbitcount(8) == 1); //1000
    // harder case:
    assert(fasterbitcount(0xffffffff) == 32);
    printf("OK\n");
}
