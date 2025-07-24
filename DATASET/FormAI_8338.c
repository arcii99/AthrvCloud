//FormAI DATASET v1.0 Category: Educational ; Style: relaxed
#include <stdio.h>

int main() {
  int num, sum = 0, i;

  printf("Enter a positive integer: ");
  scanf("%d", &num); // Getting input from user

  for (i = 1; i <= num; ++i) {
      sum += i; // Adding the value of i to sum each time the loop iterates
  }

  printf("Sum of first %d natural numbers is %d\n", num, sum);
  return 0;
}