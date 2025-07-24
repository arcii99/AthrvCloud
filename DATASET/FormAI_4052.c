//FormAI DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>

int main() {
  int expense_count;
  float total_expenses = 0;

  printf("Welcome to your Expense Tracker!\n");

  printf("How many expenses would you like to track?\n");
  scanf("%d", &expense_count);

  printf("Enter your expenses below:\n");

  for (int i = 1; i <= expense_count; i++) {
    float expense;
    printf("Expense %d: $", i);
    scanf("%f", &expense);

    if (expense > 0) {
      total_expenses += expense;
    } else {
      printf("Invalid expense amount. Try again.\n");

      // repeat the same iteration of the loop
      i -= 1;
    }
  }

  printf("Thanks for tracking your expenses with us!\n");
  printf("You spent a total of $%.2f\n", total_expenses);

  return 0;
}