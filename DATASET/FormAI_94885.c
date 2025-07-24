//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {

  char data[100];
  int checksum = 0;
  int length = 0;

  printf("Welcome to the Happy Checksum Calculator!\n");
  printf("Please enter the data to calculate the checksum:\n");

  // Get input from user
  fgets(data, 100, stdin);

  // Calculate length of input data
  length = strlen(data);

  // Loop through each character in the input data
  for (int i = 0; i < length; i++) {
    // Add the ASCII value of the character to the running checksum total
    checksum += (int)data[i];
  }

  // Output the calculated checksum value
  printf("The checksum for the input data is: %d\n", checksum);

  printf("Thank you for using the Happy Checksum Calculator!\n");

  return 0;
}