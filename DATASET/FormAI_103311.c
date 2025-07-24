//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>

int main() {
  
  // Initializing the variables
  float income, savings, expenses, remaining_balance;
  
  // Taking inputs from the user
  printf("Enter your monthly income: ");
  scanf("%f", &income);

  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);

  printf("Enter the amount you want to save each month: ");
  scanf("%f", &savings);

  // Calculation of remaining balance
  remaining_balance = income - expenses - savings;

  // Displaying the results
  printf("\nMonthly Income: $%.2f", income);
  printf("\nMonthly Expenses: $%.2f", expenses);
  printf("\nMonthly Savings: $%.2f", savings);
  
  if (remaining_balance > 0 ) {
      printf("\nRemaining Balance: $%.2f\n",remaining_balance);
  } else if (remaining_balance == 0) {
      printf("\nYou have no remaining balance.\n");
  } else {
      printf("\nYou have exceeded your monthly budget.\n");
  }
  
  return 0;
}