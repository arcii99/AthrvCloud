//FormAI DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>

/* This program takes inputs from the user
   and calculates the sum and average of the numbers.*/

int main(void) {
  int num, i, sum = 0;
  float avg;

  printf("How many numbers do you want to enter? ");
  scanf("%d", &num);

  int num_array[num];

  // Taking input from user
  for (i = 0; i < num; i++) {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &num_array[i]);
    sum += num_array[i];
  }

  // Calculating average
  avg = (float) sum / num;

  printf("\nSum of numbers: %d\n", sum);
  printf("Average of numbers: %.2f\n", avg);

  return 0;
}