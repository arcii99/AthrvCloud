//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>

int main() {
  float total_income, total_expenses = 0;
  int num_expenses;

  printf("Welcome to the Personal Finance Planner!");

  printf("\n\nHow much money do you make (per month)? $");
  scanf("%f", &total_income);

  printf("\nHow many expenses do you have each month? ");
  scanf("%d", &num_expenses);

  for (int i = 1; i <= num_expenses; i++) {
    float expense;
    printf("\nEnter expense #%d amount: $", i);
    scanf("%f", &expense);
    total_expenses += expense;
  }

  printf("\n\n********** FINANCIAL REPORT **********\n\n");

  printf("INCOME: $%.2f\n\n", total_income);
  printf("EXPENSES: $%.2f\n\n", total_expenses);

  if (total_income - total_expenses > 0) {
    printf("Congratulations! You have a surplus of $%.2f in your monthly budget.\n\n", total_income - total_expenses);
  } else if (total_income - total_expenses < 0) {
    printf("Uh-oh! You have a deficit of $%.2f in your monthly budget. You need to cut back on your expenses.\n\n", total_expenses - total_income);
  } else {
    printf("Your income and expenses are equal. You need to start saving more for the future.\n\n");
  }

  return 0;
}