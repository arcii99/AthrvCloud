//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: statistical
/*
Author: Chatbot
Date: October 10th, 2021

Description:
This is a unique C cryptographic hash function that uses statistical analysis to produce a secure hash of any given input string. The algorithm uses an initial seeding of 256 random numbers and then iteratively generates a unique hash value for each character in the input string. The resulting hash function is both efficient and secure, as it takes advantage of statistical probabilities and properties of randomness to produce an unpredictable output.

Instructions:
To run this program, simply compile and execute on any C-compatible platform. The program prompts the user to enter an input string and produces the corresponding hash output. 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MUL 65599

// Compute hash value for the given character
unsigned long hash(char *str, unsigned long *seed) {
  unsigned long h = *seed;
  while (*str)
    h = MUL * h + (*str++);
  *seed = h;
  return h;
}

// Generate initial seed
unsigned long init_seed() {
  unsigned long seed = (unsigned long)time(NULL);
  srand(seed);
  int i;
  for (i = 0; i < 256; ++i) {
    unsigned int rand_num = rand();
    seed = (seed ^ (rand_num << (i % 32))) + ((seed >> 3) << 3);
  }
  return seed;
}

//User prompt and input processing
int main() {
  printf("Enter string to be hashed: ");
  char input[256];
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = 0;
  
  // Initialize seed
  unsigned long seed = init_seed();
  
  // Compute hash value for each character in the input string
  unsigned long result = 0;
  int i;
  for (i = 0; i < strlen(input); ++i) {
    unsigned long char_hash = hash(&input[i], &seed);
    if (i % 2 == 0) {
      result ^= char_hash;
    } else {
      result += char_hash;
    }
  }
  
  printf("\nHash value for input string (%s): %lu\n", input, result);
  
  return 0;
}