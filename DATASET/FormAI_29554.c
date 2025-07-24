//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>

int main() {
  // Declare variables
  float salary, expenses, savings, investment_percentage;
  int months;

  // Take user input
  printf("Enter your monthly salary: ");
  scanf("%f", &salary);
  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);

  // Calculate monthly savings
  savings = salary - expenses;

  // Display monthly savings
  printf("Your monthly savings is: $%.2f\n", savings);

  // Take user input for desired investment percentage
  printf("Enter the percentage of your savings you want to invest (e.g. 10 for 10%%): ");
  scanf("%f", &investment_percentage);

  // Convert investment percentage to decimal format
  investment_percentage /= 100;

  // Calculate amount to invest each month
  float investment = savings * investment_percentage;

  // Calculate projected savings after specified number of months
  printf("Enter the number of months you want to project your savings for: ");
  scanf("%d", &months);
  float projected_savings = savings * months;

  // Calculate projected investment earnings after specified number of months
  float projected_earnings = investment * months * 1.05; // assuming 5% annual interest rate

  // Display projection results
  printf("\nProjection Results:\n");
  printf("Savings after %d months: $%.2f\n", months, projected_savings);
  printf("Investment earnings after %d months: $%.2f\n", months, projected_earnings);

  return 0;
}