//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
  float income, expense, saving, debt, netWorth;
  
  // Get user input
  printf("Enter your monthly income: ");
  scanf("%f", &income);
  
  printf("Enter your monthly expenses: ");
  scanf("%f", &expense);
  
  printf("Enter your monthly debt payments: ");
  scanf("%f", &debt);
  
  // Calculate the saving and net worth
  saving = income - expense;
  netWorth = income - expense - debt;
  
  // Print the result
  printf("Your monthly savings is: $%.2f\n", saving);
  printf("Your monthly net worth is: $%.2f\n", netWorth);
  
  // Determine if they are saving enough
  if (saving < 0) {
    printf("You are not saving enough!\n");
  } else if (saving < income/2) {
    printf("You are doing okay but aim to save more.\n");
  } else {
    printf("You are doing great! Keep it up.\n");
  }
  
  // Determine if they have too much debt
  if (debt > income/2) {
    printf("You have too much debt!\n");
  } else {
    printf("Your debt is under control.\n");
  }
  
  return 0;
}