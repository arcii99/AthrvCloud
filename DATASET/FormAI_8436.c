//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: genious
#include <stdio.h>

int main() {
  float income, expenses;
  float savings_rate, savings_amount, balance;
  int months;

  printf("Enter your monthly income: ");
  scanf("%f", &income);

  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);

  printf("Enter the number of months you want to plan for: ");
  scanf("%d", &months);

  printf("\n");

  balance = income - expenses;
  savings_rate = (balance / income) * 100;
  savings_amount = balance * months;

  printf("Income: $%.2f\n", income);
  printf("Expenses: $%.2f\n", expenses);
  printf("Balance per month: $%.2f\n", balance);
  printf("Savings Rate: %.2f%%\n", savings_rate);
  printf("Savings amount after %d months: $%.2f\n", months, savings_amount);

  return 0;
}