//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: romantic
#include <stdio.h>

int main() {
  int checksum = 0;
  char str[100];

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  for (int i = 0; str[i] != '\0'; ++i) {
    checksum += (int) str[i];
  }

  printf("\nChecksum of the string is %d", checksum);
  return 0;
}