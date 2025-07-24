//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to the Happy Checksum Calculator! Let's get started on making some checksums that will make you smile :)\n");
  printf("Enter a sequence of numbers separated by spaces: ");

  int sum = 0; // initialize sum variable

  // read in sequence of numbers
  int num;
  while (scanf("%d", &num) == 1) {
    sum += num;
  }

  // calculate and print checksum
  int checksum = sum % 256;
  printf("\nYour checksum is: %d :) \n", checksum);

  printf("Thanks for using the Happy Checksum Calculator! We hope we made your day a little brighter!\n");

  return 0;
}