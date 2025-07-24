//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>

int main() {

  // Welcome message
  printf("Welcome to Personal Finance Planner!\n");

  // Variable declaration
  float initialBalance, monthlyIncome, monthlyExpense, monthlySavings;

  // Take user input
  printf("Enter your initial balance: ");
  scanf("%f", &initialBalance);

  printf("Enter your monthly income: ");
  scanf("%f", &monthlyIncome);

  printf("Enter your monthly expenses: ");
  scanf("%f", &monthlyExpense);

  // Calculate monthly savings
  monthlySavings = monthlyIncome - monthlyExpense;

  // Display monthly savings and remaining balance
  printf("Your monthly savings: $%.2f\n", monthlySavings);
  printf("Your remaining balance after one month: $%.2f\n", initialBalance + monthlySavings);

  // Calculate savings after 6 months
  float sixMonthSavings = monthlySavings * 6;
  printf("Your savings after 6 months: $%.2f\n", sixMonthSavings);

  // Calculate remaining balance after 6 months
  float sixMonthRemainingBalance = initialBalance + sixMonthSavings - (monthlyExpense * 6);
  printf("Your remaining balance after 6 months: $%.2f\n", sixMonthRemainingBalance);

  return 0;
}