//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>

int main() {
  int num, i, j, flag;
  printf("This program generates prime numbers!\n");
  printf("Enter the maximum range: ");
  scanf("%d", &num);
  printf("Prime numbers between 1 to %d are:\n", num);

  // Loop through all the numbers between 1 and num
  for (i = 2; i <= num; i++) {
    flag = 0; // Flag to check if the number is prime
    // Check if the number is divisible by any number between 2 and i/2
    for (j = 2; j <= i/2; j++) {
      if (i % j == 0) {
        flag = 1; // Set flag to 1 if the number is not prime
        break;
      }
    }
    if (flag == 0 && i != 1) {
      printf("%d ", i); // Print the number if it is prime
    }
  }
  return 0;
}