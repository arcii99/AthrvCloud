//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare our function to calculate the checksum
unsigned char calculateChecksum(char* message);

int main() {
  // Get user input for the message to calculate the checksum of
  char message[100];
  printf("Enter message to calculate checksum of: ");
  fgets(message, 100, stdin);

  // Calculate the checksum of the message using our function
  unsigned char checksum = calculateChecksum(message);

  // Print the checksum in hexadecimal format
  printf("Checksum: 0x%02x\n", checksum);

  return 0;
}

unsigned char calculateChecksum(char* message) {
  // Initialize our checksum variable
  unsigned char checksum = 0;

  // Loop through the characters in the message
  for (int i = 0; i < strlen(message); i++) {
    // Add the ASCII value of the current character to the checksum
    checksum += (unsigned char) message[i];
  }

  // Return the checksum
  return checksum;
}