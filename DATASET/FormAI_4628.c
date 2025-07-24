//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>

int main() {
  // Introspection
  printf("Welcome to Personal Finance Planner!\n");
  printf("This program will help you manage your finances.\n");
  printf("Please enter your name: ");
  char name[50];
  scanf("%s", name);
  printf("Hello, %s!\n", name);

  // Input
  printf("Please enter your monthly income: $");
  float monthly_income;
  scanf("%f", &monthly_income);
  printf("Please enter your monthly expenses: $");
  float monthly_expenses;
  scanf("%f", &monthly_expenses);

  // Calculation
  float monthly_savings = monthly_income - monthly_expenses;
  float annual_savings = monthly_savings * 12;

  // Output
  printf("Based on your inputs, your monthly savings are: $%.2f\n", monthly_savings);
  printf("That means you can save $%.2f per year!\n", annual_savings);

  // Recommendations
  if (monthly_savings >= monthly_income * 0.1) {
    printf("Congratulations! You are saving at least 10%% of your monthly income.\n");
  } else if (monthly_savings >= monthly_income * 0.05) {
    printf("It's good that you are saving, but try to save at least 10%% of your monthly income.\n");
  } else {
    printf("You need to make some adjustments to your expenses to be able to save at least 5%% of your monthly income.\n");
  }

  return 0;
}