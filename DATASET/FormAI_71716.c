//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  unsigned char data[1024];
  int length;
  int i;
  unsigned char checksum = 0;

  // Prompt user for input
  printf("Enter data (up to 1024 bytes): ");
  fgets(data, 1024, stdin);

  // Calculate length of input data
  length = strlen(data);

  // Calculate checksum
  for (i = 0; i < length; i++) {
    checksum += data[i];
  }

  // Display checksum
  printf("Checksum: 0x%X\n", checksum);

  return 0;
}