//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ada Lovelace
// Ada Lovelace Checksum Calculator in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare variables
  char input[100];
  int sum = 0;
  
  // Get user input
  printf("Enter a string to calculate checksum: ");
  fgets(input, sizeof(input), stdin);

  // Iterate through the string and calculate the sum
  for (int i = 0; i < strlen(input); i++) {
    sum += (int)input[i];
  }

  // Calculate the checksum
  int checksum = sum % 256;

  // Print the results
  printf("Input String: %s", input);
  printf("Checksum: %d\n", checksum);
  
  return 0;
}