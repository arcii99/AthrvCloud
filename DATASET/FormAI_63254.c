//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
  char data[1000];
  unsigned int checksum = 0;

  printf("Enter the data string: ");
  fgets(data, sizeof(data), stdin);

  int i;
  for (i = 0; i < strlen(data); i++) {
    checksum += data[i];
  }

  printf("Checksum value is: %u\n", checksum);

  return 0;
}