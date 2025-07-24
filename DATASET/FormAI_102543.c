//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
  char message[100];
  int checksum = 0;

  printf("Enter message to calculate checksum: ");
  scanf("%s", message);

  for(int i = 0; message[i] != '\0'; i++)
    checksum += message[i];

  printf("Checksum is: %d\n", checksum);

  return 0;
}