//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  int num_expenses, i;
  float expense, total = 0.0;

  printf("Greetings, my dear Watson.\n");
  printf("I have created a program to track our expenses.\n");
  printf("Please enter the number of expenses: ");
  scanf("%d", &num_expenses);

  for (i = 1; i <= num_expenses; i++) {
    printf("\nPlease enter the expense amount %d: ", i);
    scanf("%f", &expense);
    total += expense;
  }

  printf("\nThank you, dear Watson.\n");
  printf("Our total expenses amount to: $%.2f\n", total);
  printf("This will help us solve our mysteries more efficiently.\n");

  return 0;
}