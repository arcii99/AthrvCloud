//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>

int main() {
  float current_balance, income, monthly_expenses;
  int months;

  printf("Welcome to the Personal Finance Planner.\n");
  printf("Please enter your current account balance: ");
  scanf("%f", &current_balance);
  printf("Please enter your monthly income: ");
  scanf("%f", &income);
  printf("Please enter your monthly expenses: ");
  scanf("%f", &monthly_expenses);
  printf("Please enter the number of months you want to plan: ");
  scanf("%d", &months);
  printf("\n\n");

  // calculate and display the financial plan for each month
  for (int i = 1; i <= months; i++) {
    printf("MONTH %d:\n", i);
    printf("Starting Balance: $%.2f\n", current_balance);
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", monthly_expenses);
    current_balance += income - monthly_expenses;
    printf("Ending Balance: $%.2f\n", current_balance);
    printf("\n");
  }
  printf("Thank you for using the Personal Finance Planner.\n");
  return 0;
}