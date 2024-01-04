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

  //how can I set that bit at that "index" without a left shift operator and more efficiently?

  int lightSwitch = 1;
  lightSwitch = lightSwitch << idx;
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
  //Use 26 bits to represent whether there exists a letter a-z 
  //in this line. 1 means the character at this "index" in the alphabet
  //exists in this line, 0 means it doesn't
  //for ex. "abcdef" could be represented by "00000000000000000000111111"
  //iterate through each char in the line
  //if char is in the alphabet
  //convert to lowercase version
  //turn the bit corresponding to this lowercase letter that is one of the letters from a-z on 
  //at that index
  __uint32_t counts = 0b00000000000000000000000000;
  __uint32_t pangramCounts = 0b11111111111111111111111111;
  char* t = s;
  for (char c = *t; c != '\0'; c=*(++t)) {
    if (isalpha(c)) {
      char lowercaseLetter = tolower(c);
      int ascii = (int) lowercaseLetter;
      int idx = ascii - 97;
      // printf("letter: %c, ascii normalized: %d\n", lowercaseLetter, idx);
      counts = turnBitAtIndexOn(counts, idx);
    }
  }

  return counts == pangramCounts;
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
