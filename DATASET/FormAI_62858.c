//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Donald Knuth
#include <stdio.h>

/* Personal Finance Planner */
/* by Donald Knuth */

int main() {
  float income, expenses, savings, investment;
  float total_expenses = 0.0, total_savings = 0.0, total_investment = 0.0;

  printf("Welcome to Personal Finance Planner. \n");
  printf("Please enter the following information for each month: \n");

  for(int i = 1; i <= 12; i++) {
    printf("\nMonth %d:\n", i);

    printf("Enter Income: $");
    scanf("%f", &income);

    printf("Enter Expenses: $");
    scanf("%f", &expenses);

    savings = income - expenses;
    printf("Savings: $%.2f\n", savings);

    printf("Enter Investment: $");
    scanf("%f", &investment);

    float current_month_balance = savings - investment;
    printf("Current Month Balance: $%.2f\n", current_month_balance);

    total_expenses += expenses;
    total_savings += savings;
    total_investment += investment;
  }

  printf("\n\n==========================\n");
  printf("      Yearly Summary \n");
  printf("==========================\n\n");

  printf("Total Expenses: $%.2f\n", total_expenses);
  printf("Total Savings: $%.2f\n", total_savings);
  printf("Total Investment: $%.2f\n", total_investment);

  float net_income = total_savings + total_investment;
  printf("Total Net Income: $%.2f\n", net_income);

  return 0;
}