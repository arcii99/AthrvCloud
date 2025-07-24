//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>

int main() {
  float income, savings, expenses, goal;
  printf("Enter your monthly income: ");
  scanf("%f", &income);
  printf("Enter your monthly savings: ");
  scanf("%f", &savings);
  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);
  printf("Enter your financial goal: ");
  scanf("%f", &goal);

  float monthly_budget = income - expenses;
  float monthly_savings_percentage = (savings / income) * 100;
  float time_remaining_to_goal = goal / (savings - expenses);

  printf("\n\n------PERSONAL FINANCE PLANNER RESULTS------\n\n");
  printf("Monthly Budget: $%.2f\n", monthly_budget);
  printf("Monthly Savings Percentage: %.2f%%\n", monthly_savings_percentage);
  printf("Time Remaining To Achieve Goal: %.2f months\n", time_remaining_to_goal);
  
  return 0;
}