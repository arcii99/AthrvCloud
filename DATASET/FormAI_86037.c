//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100]; // declare an array to hold input data
  printf("Enter the data to be compressed: ");
  scanf("%s", input); // get input data from user

  int length = strlen(input); // get length of input data
  int compressed_length = length / 2 + 1; // calculate length of compressed data

  char compressed[compressed_length]; // declare an array to hold compressed data

  int i, j; // initialize variables for loops
  for (i = 0, j = 0; i < length; i+=2, j++) {
    compressed[j] = input[i]; // copy every other character from input to compressed
  }
  compressed[j] = '\0'; // terminate compressed string with null character

  printf("Compressed data: %s\n", compressed); // print compressed data

  return 0; // end the program
}