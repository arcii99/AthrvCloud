//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: random
#include <stdio.h>

int main() {
  // Declare variables
  int checkSum = 0, i;
  char message[100];

  // Ask for user input
  printf("Enter message: ");
  scanf("%s", message);

  // Calculate checksum
  for (i = 0; message[i] != '\0'; i++) {
    checkSum += message[i];
  }

  // Output result
  printf("Checksum value: %d\n", checkSum);

  // Reverse checksum
  int remainder, reversedNum = 0;
  while (checkSum != 0) {
    remainder = checkSum % 10;
    reversedNum = reversedNum * 10 + remainder;
    checkSum /= 10;
  }

  // Output reversed checksum
  printf("Reversed Checksum value: %d\n", reversedNum);

  // Checksums comparison
  if (checkSum == reversedNum) {
    printf("Checksums match!\n");
  } else {
    printf("Checksums do not match!\n");
  }

  return 0;
}