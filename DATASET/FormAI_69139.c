//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ada Lovelace
// Ada's Unique Checksum Calculator Program
// By [Your Name]
// Inspired by Ada Lovelace

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function calculates the checksum of the given string
unsigned char calculateChecksum(char string[]) {
  unsigned char checksum = 0; // Initialize checksum to zero
  int i;
  for (i = 0; i < strlen(string); i++) {
    checksum ^= string[i]; // XOR operation with each character in the string
  }
  return checksum;
}

int main() {
  char inputString[100];
  printf("Enter the input string: ");
  gets(inputString); // Get the input string from the user

  // Print the input string
  printf("Input String: %s\n", inputString);

  // Calculate the checksum of the input string
  unsigned char checksum = calculateChecksum(inputString);

  // Print the checksum
  printf("Checksum: %d\n", checksum);

  return 0;
}