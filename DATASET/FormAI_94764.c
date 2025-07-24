//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned char message[1000];
  int i, j, len;
  unsigned char checksum = 0;

  printf("Please enter the message to generate the checksum:\n");
  fgets(message, 1000, stdin);

  len = strlen(message);

  for (i = 0; i < len; i++) {
    checksum ^= message[i];
  }

  printf("The checksum is: %d\n", checksum);

  return 0;
}