//FormAI DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>

int main() {

  // declare variables
  int x, y, i;
  int first_term, common_diff;
  int sum = 0;

  // get the input from the user
  printf("Enter the value of the first term: ");
  scanf("%d", &first_term);
  printf("Enter the value of the common difference: ");
  scanf("%d", &common_diff);
  printf("Enter the value of number of terms to be found: ");
  scanf("%d", &x);

  // calculate the sum of the arithmetic series
  for (i = 0; i < x; i++) {
    y = first_term + (i * common_diff);
    sum += y;
  }

  // display the sum of the arithmetic series
  printf("The sum of the first %d terms of the arithmetic series is: %d", x, sum);

  return 0;
}