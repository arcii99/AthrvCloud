//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
  char input[50];
  printf("Enter the string you want to calculate checksum for: ");
  scanf("%s", input);

  int sum = 0;
  int i;
  for(i = 0; input[i] != '\0'; i++) {
    sum += (int)(input[i]);
  }

  int checksum = sum % 256;
  printf("The checksum of the input string is %d", checksum);

  return 0;
}