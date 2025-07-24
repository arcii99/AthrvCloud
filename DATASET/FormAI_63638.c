//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {
  float monthly_income, monthly_expenses, savings_goal;
  int months_to_achieve;

  printf("Welcome to the Personal Finance Planner!\n");
  printf("Please input your monthly income: ");
  scanf("%f", &monthly_income);
  printf("Please input your monthly expenses: ");
  scanf("%f", &monthly_expenses);
  printf("Please input your savings goal: ");
  scanf("%f", &savings_goal);

  float monthly_savings = monthly_income - monthly_expenses;
  if (monthly_savings < 0) {
    printf("Warning: You are spending more than you are earning! Please review your finances.\n");
  } else {
    printf("You are currently saving $%.2f per month.\n", monthly_savings);
  }

  if (savings_goal <= 0) {
    printf("You have already achieved your savings goal!\n");
  } else {
    months_to_achieve = ceil(savings_goal / monthly_savings);
    printf("At your current savings rate, it will take %d months to achieve your savings goal of $%.2f.\n",  months_to_achieve, savings_goal);
  }

  return 0;
}