//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
  double monthly_income, monthly_expenses, savings_goal;
  int months_to_reach_goal;
  printf("Welcome to Personal Finance Planner!\n");
  printf("Please enter your monthly income: ");
  scanf("%lf", &monthly_income); // User inputs monthly income
  printf("Please enter your monthly expenses: ");
  scanf("%lf", &monthly_expenses); // User inputs monthly expenses
  printf("Please enter your savings goal: ");
  scanf("%lf", &savings_goal); // User inputs savings goal
  months_to_reach_goal = (int)(savings_goal / (monthly_income - monthly_expenses)); // Calculates months needed to reach savings goal
  printf("In order to reach your savings goal of $%.2lf, you need to save for %d months.\n", savings_goal, months_to_reach_goal);
  double current_savings = 0.0;
  int i;
  for (i = 1; i <= months_to_reach_goal; i++) {
    current_savings += monthly_income - monthly_expenses; // Calculates savings after each month
    printf("After month %d, your current savings is $%.2lf\n", i, current_savings);
  }
  printf("Congratulations! You have reached your savings goal!\n");
  return 0;
}