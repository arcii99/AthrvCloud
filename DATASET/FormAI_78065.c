//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include <stdio.h>

int main() {
  // declare variables
  float income, expenses, savings, debt;
  
  // get user input
  printf("Please enter your monthly income: ");
  scanf("%f", &income);
  
  printf("Please enter your monthly expenses: ");
  scanf("%f", &expenses);
  
  printf("Please enter your monthly savings: ");
  scanf("%f", &savings);
  
  printf("Please enter your total debt: ");
  scanf("%f", &debt);
  
  // calculate net income
  float net_income = income - expenses;
  
  // calculate debt-to-income ratio
  float debt_to_income_ratio = debt / income;
  
  // display results
  printf("Your net income is: $%.2f\n", net_income);
  printf("Your savings rate is: %.2f%%\n", (savings / income) * 100);
  printf("Your debt-to-income ratio is: %.2f\n", debt_to_income_ratio);
  
  // make financial recommendation based on debt-to-income ratio
  if (debt_to_income_ratio < 0.3) {
    printf("\nCongratulations! Your debt-to-income ratio is below 30%%, which is a healthy level.\n");
  } else if (debt_to_income_ratio >= 0.3 && debt_to_income_ratio < 0.5) {
    printf("\nYour debt-to-income ratio is between 30%% and 50%%. While this is not ideal, it's still manageable.\n");
    printf("Consider paying down your debt faster to improve your financial health.\n");
  } else {
    printf("\nYour debt-to-income ratio is above 50%%, which is a cause for concern.\n");
    printf("Consider seeking professional financial advice to help you get your debt under control.\n");
  }

  return 0;
}