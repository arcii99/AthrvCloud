//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Checksum Calculator!\n");
  printf("Enter a string: ");

  char input[100];
  scanf("%s", input);

  // Calculate checksum
  int sum = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    sum += input[i];
  }

  // Output checksum
  printf("Checksum: %d\n", sum);

  return 0;
}