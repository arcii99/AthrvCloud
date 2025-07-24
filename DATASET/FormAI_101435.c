//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: ephemeral
#include <stdio.h>

// This program calculates the 16-bit C checksum of a given string entered by the user

int main() {
  
  char str[100];
  printf("Enter a string: ");
  fgets(str, 100, stdin);

  int length = strlen(str);
  if (length == 0) {
    printf("Invalid input");
    exit(1);
  }

  unsigned int checksum = 0; // This will store the final checksum value

  for (int i=0; i<length; i++) {
    if (str[i] == '\n') {
      continue;
    }
    checksum += (unsigned int)str[i]; // Add each character to the checksum
    checksum = (checksum & 0xFFFF) + (checksum >> 16); // Fold the carry bits
  }

  checksum = ~checksum; // Compute the complement of the final checksum

  printf("C Checksum: %04X", checksum);

  return 0;
}