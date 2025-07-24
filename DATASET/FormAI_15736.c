//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>

int main() {
  //initializing variables
  float monthly_income, monthly_expenses, savings_goal;
  int months_to_reach_goal;
  
  //gathering user input
  printf("Enter your monthly income: ");
  scanf("%f", &monthly_income);

  printf("Enter your monthly expenses: ");
  scanf("%f", &monthly_expenses);

  printf("Enter your savings goal: ");
  scanf("%f", &savings_goal);

  //calculating how long it will take to reach savings goal
  float monthly_savings = monthly_income - monthly_expenses;
  months_to_reach_goal = (int)(savings_goal / monthly_savings);

  //displaying results
  printf("You need to save $%.2f each month to reach your goal of $%.2f in %d months.\n", monthly_savings, savings_goal, months_to_reach_goal);

  return 0;
}