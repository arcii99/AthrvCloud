//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>
int main() {
  float income, fixed_expenses, variable_expenses, remaining_balance, financial_goal, goal_progress;
  
  // Get user input for monthly income and expenses
  printf("Enter your monthly income: $");
  scanf("%f", &income);
  
  printf("Enter your fixed monthly expenses: $");
  scanf("%f", &fixed_expenses);
  
  printf("Enter your variable monthly expenses: $");
  scanf("%f", &variable_expenses);
  
  // Calculate remaining balance and show to user
  remaining_balance = income - fixed_expenses - variable_expenses;
  printf("Your remaining monthly balance is: $%.2f\n", remaining_balance);
  
  // Get user input for financial goal and calculate progress
  printf("Enter your financial goal: $");
  scanf("%f", &financial_goal);
  
  goal_progress = financial_goal / 12; // Assuming a 1 year time frame
  printf("To reach your goal, you need to set aside $%.2f each month.\n", goal_progress);
  
  printf("Your progress towards your goal is: $%.2f\n", remaining_balance - goal_progress);
  
  return 0;
}