//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: random
#include <stdio.h>

int main() {
  char message[100];
  int checksum = 0;

  printf("Enter a message to calculate its checksum: ");
  fgets(message, 100, stdin);

  for (int i = 0; message[i] != '\0'; i++) {
    if (i % 2 == 0) {
      checksum += message[i] * 2;
    } else {
      checksum += message[i] / 2;
    }
  }

  printf("Checksum value: %d\n", checksum);

  return 0;
}