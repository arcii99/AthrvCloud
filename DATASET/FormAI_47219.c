//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>

int main() {
  float monthlyIncome, monthlyExpenses, savingsGoal;
  int monthsUntilGoal;
  printf("Welcome to the Personal Finance Planner.\n\n");
  printf("Please enter your monthly income: ");
  scanf("%f", &monthlyIncome);
  printf("Please enter your monthly expenses: ");
  scanf("%f", &monthlyExpenses);
  printf("Please enter your savings goal: ");
  scanf("%f", &savingsGoal);
  printf("Please enter the number of months you want to achieve your savings goal in: ");
  scanf("%d", &monthsUntilGoal);

  float monthlySavings = monthlyIncome - monthlyExpenses;
  float totalSavings = monthlySavings * monthsUntilGoal;

  if (totalSavings >= savingsGoal) {
    printf("\nCongratulations! You will achieve your savings goal in %d months if you continue to save %f per month.\n", monthsUntilGoal, monthlySavings);
  }
  else {
    int extraMonths = (savingsGoal - totalSavings) / monthlySavings;
    printf("\nYou need to save at least %f per month to reach your goal in %d months.\n", (savingsGoal - totalSavings) / (float)monthsUntilGoal, monthsUntilGoal + extraMonths);
  }

  return 0;
}