//FormAI DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

/*
This program is an example of calculating the sum of all numbers from 1 to N,
where N is taken as input from the user.
*/

int main() {
  int num;
  printf("Enter a positive integer: ");
  scanf("%d", &num);

  if (num <= 0) {
    printf("Error! Please enter a positive integer.\n");
    return 1;
  }

  int i = 1;
  int sum = 0;

  while (i <= num) {
    sum += i;
    i++;
  }

  printf("The sum of all numbers from 1 to %d is %d.\n", num, sum);
  return 0;
}