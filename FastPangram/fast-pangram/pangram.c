#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <assert.h>

int turnBitAtIndexOn(int number, int idx) {
  //Example 1: Input: number = 0b00000000000000000000000000, idx = 0
  //Output: number = 0b00000000000000000000000001

  //Example 2: number = 0b00000000000000000000000000, idx = 3
  //Output: number = 0b00000000000000000000001000

  //Algorithm:
  //initialize int lightSwitch = 1
  //lightSwitch << idx
  //number &= 

  //Example: input: number = 0, idx = 3
  //output: 1000


  int lightSwitch = 1 << idx;
  number |= lightSwitch;
  return number;
}


//Pangrams Problem: Does the given text contain every letter of the alphabet, a-z, where uppercase/lowercase doesn't matter
bool ispangram(char *s) {
  // Algorithm:
  //Check if there is atleast one occurrence of the each letter 
  //in the set of lower case english alphabet letters
  //in the string that *s points to

  //Approach 1:
  //initialize int[] counts of size 26
  //Iterate memory address by memory address starting from the first char
  //of the line that char pointer s points to 
  //convert each char to lowercase
  //get ascii value of lowercase char
  //normalize ascii value to range 0-25
  //if isalpha(), increment value at counts[idx]
  //iterate through counts
  //if counts[i] == 0
  //return false
  //at the end, return true


  //Approach 2:
  //bitset - data structure of N bits where 1 represents true and 0 represents false and can be used 
  //in problems similar to how a bloom filter can be used
  //Use bitset of size 26 to represent whether there exists a letter a-z 
  //in a line. 1 means the character at this "index" in the alphabet
  //exists in this line, 0 means it doesn't
  //for ex. "abcdef" could be represented by "00000000000000000000111111"
  //iterate through each char in the line
  //if char is in the alphabet
  //convert to lowercase version
  //turn the bit corresponding to this lowercase letter that is one of the letters from a-z on 
  //at that index

  //Optimized Approach to improve latency even more:
  //Don't use the toLower() function
  //and don't subtract
  //Use the binary representation of the ASCII values
  //and clear all of the bits expect the 5 rightmost bits
  //to whether a character is a letter in the alphabet a-z
  //For ex. The binary number of A's ASCII value of 65 = 01000001
  //The binary number of a's ASCII value of 97 = 01100001
  //If you apply a bitmask that clears all of the bits 
  //except the right most bits, A's and a's ASCII value in binary
  //will be 00001.
  //then left shifting 1 by 00001=1 will set the bit at the "index"
  //corresponding to A and a, which is the bit at "index" 1 of a
  //32 bit number 
  //then check if the values at "indices" 1-26 are set in a 32 bit number
  //and the other bits are cleared 



  __uint32_t pangramCounts = 0x00000000;
  #define MASK 0x07fffffe
  char* t = s;
  for (char c = *t; c != '\0'; c=*(++t)) {
      if (c < '@')
        continue;
      int idx = (c & 0x1f); //This will clear all bits except 5 rightmost bits. For ex. A = 1000001 will be becomes 00001 = 1 in decimal
      // printf("letter: %c, ascii normalized: %d\n", lowercaseLetter, idx);
      pangramCounts = turnBitAtIndexOn(pangramCounts, idx);
  }

  return (pangramCounts & MASK) == MASK;
}




int main() {

  // int number = 4;
  // int idx = 1;
  // int expectedNumber = 6;
  // int actualNumber = turnBitAtIndexOn(number, idx);
  // assert(expectedNumber == actualNumber);

  // char* test1 = "abcdef";
  // assert(ispangram(test1) == false);
  // printf("ok\n");

  // char* test2 = "Mr. Jock, TV quiz PhD, bags few lynx.";
  // assert(ispangram(test2) == true);
  // printf("ok");

  size_t len;
  ssize_t read;
  char *line = NULL;
  while ((read = getline(&line, &len, stdin)) != -1) {
    if (ispangram(line))
      printf("%s", line);
  }

  if (ferror(stdin))
    fprintf(stderr, "Error reading from stdin");

  free(line);
  fprintf(stderr, "ok\n");
}
