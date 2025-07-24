//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Checksum Calculator!\n");

  int input;
  
  printf("Please enter the number of integers you would like to calculate the checksum for: ");
  scanf("%d", &input);

  int sum = 0;

  // Input validation
  if (input < 1) {
    printf("Invalid input: Please enter a positive integer.\n");
    return 1;
  }

  int i;
  for (i = 0; i < input; i++) {
    int num;
    printf("Enter integer %d: ", i + 1);
    scanf("%d", &num);
    sum += num;
  }

  int checksum = 255 - (sum % 256);
  printf("Checksum for input is: %d\n", checksum);

  return 0;
}