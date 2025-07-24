//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: happy
#include <stdio.h>

int main() {
  printf("\n\nWelcome to the Happy Checksum Calculator!\n\n");

  long long int number;
  int digit, sum = 0, count = 0;

  printf("Please enter a positive integer below:\n");
  scanf("%lld", &number);

  // Checksum Calculation
  while (number != 0) {
    digit = number % 10;
    sum += digit;
    number /= 10;
    count++;
  }

  // Displaying Results
  printf("\nThe Sum of the Digits is: %d", sum);

  int checksum = (sum * 10) % 9;
  printf("\nThe Checksum is: %d\n\n", checksum);

  printf("Hooray! Your checksum has been calculated successfully!\n\n");

  return 0;
}