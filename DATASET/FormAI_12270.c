//FormAI DATASET v1.0 Category: Educational ; Style: portable
#include <stdio.h>

/* This is a program that reads in a sequence of integers,
and output how many of them are positive, negative, and zero, respectively. */

int main() {
  int num, pos_count = 0, neg_count = 0, zero_count = 0;

  printf("Enter integers, one per line, terminated by zero:\n");

  while (1) {
    scanf("%d", &num);
    if (num == 0) break;
    if (num < 0) neg_count++;
    else if (num > 0) pos_count++;
    else zero_count++;
  }

  printf("The number of positive integers is %d.\n", pos_count);
  printf("The number of negative integers is %d.\n", neg_count);
  printf("The number of zeros is %d.\n", zero_count);

  return 0;
}