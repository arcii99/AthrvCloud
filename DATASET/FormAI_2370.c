//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
  float income;
  float expense;
  float savings;

  // User input for monthly income and expenses
  printf("Enter your monthly income: ");
  scanf("%f", &income);
  
  printf("Enter your monthly expenses: ");
  scanf("%f", &expense);

  // Calculate monthly savings
  savings = income - expense;

  // Display results
  printf("\nMonthly Savings: $%.2f\n", savings);

  if (savings < 0) {
    printf("You are spending more money than you are earning. Consider reducing your expenses.\n");
  } else if (savings == 0) {
    printf("Your income and expenses are equal. You are not saving any money.\n");
  } else {
    printf("You are saving money each month. Great job!\n");

    // Calculate yearly savings based on monthly savings
    float yearlySavings = savings * 12;
    printf("Yearly Savings: $%.2f\n", yearlySavings);

    // Determine saving goals based on income
    float sixMonthSavings = income * 6;
    float oneYearSavings = income * 12;
    float twoYearSavings = income * 24;

    printf("To reach your savings goals:\n");
    printf("Save $%.2f for six months\n", sixMonthSavings);
    printf("Save $%.2f for one year\n", oneYearSavings);
    printf("Save $%.2f for two years\n", twoYearSavings);
  }

  return 0;
}