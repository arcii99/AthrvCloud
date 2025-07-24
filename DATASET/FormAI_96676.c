//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  int input, checksum = 0;

  printf("Enter a string to calculate checksum: ");

  while ((input = getchar()) != '\n') {
    checksum += input;
    if (checksum > 32767) {
      checksum = -(65535 - checksum) - 1;
    }
  }

  printf("The checksum is = %d\n", checksum);

  return 0;
}