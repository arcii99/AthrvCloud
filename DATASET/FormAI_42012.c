//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include <stdio.h>

int main() {
  // User inputs initial financial information
  double salary;
  printf("Enter your salary: ");
  scanf("%lf", &salary);

  double expenses;
  printf("Enter your monthly expenses: ");
  scanf("%lf", &expenses);

  double savingsGoal;
  printf("Enter your savings goal: ");
  scanf("%lf", &savingsGoal);

  double currentSavings = 0.0;
  double monthlySavings = salary - expenses;
  int monthsUntilGoalReached = 0;

  // Calculate months until savings goal is reached
  while (currentSavings < savingsGoal) {
    if (monthsUntilGoalReached == 0) { // print on the first month only
      printf("\nStarting balance: $%.2lf\n", currentSavings);
    }

    // Add monthly savings and interest
    currentSavings += monthlySavings;
    currentSavings += currentSavings * 0.02 / 12; // assuming 2% annual interest

    // Print current balance each month
    monthsUntilGoalReached += 1;
    printf("Month %2d:", monthsUntilGoalReached);
    printf(" $%.2lf\n", currentSavings);
  }

  // Output results
  printf("\nCongratulations, you have reached your savings goal in %d months!\n", monthsUntilGoalReached);
  printf("\nFinal balance: $%.2lf\n", currentSavings);

  return 0;
}