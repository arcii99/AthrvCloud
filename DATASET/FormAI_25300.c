//FormAI DATASET v1.0 Category: Expense Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int expense[31];
  int total = 0;
  printf(
    "Welcome to the Happy Expense Tracker! \n\n"
    "Keep track of your daily expenses in a fun and easy way!\n"
    "Let's start the month with a blank slate!\n\n");

  for (int i = 0; i < 31; i++) {
    printf("Enter today's expense for Day %d: $", i + 1);
    scanf("%d", &expense[i]);
    total += expense[i];
  }

  printf("\nGreat! Here is your expense report for the month:\n\n");

  for (int i = 0; i < 31; i++) {
    printf("Day %d: $%d\n", i + 1, expense[i]);
  }

  printf("\n\nYour total expenses for the month is: $%d\n", total);
  printf("\n\nStay Happy and Save Money!\n");

  return 0;
}