//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
  float income, monthlyExpenses, savings;
  
  // User Input
  printf("Enter your monthly income: ");
  scanf("%f", &income);
  
  printf("Enter your monthly expenses: ");
  scanf("%f", &monthlyExpenses);
  
  // Calculating Savings
  savings = income - monthlyExpenses;
  
  // Checking for Savings
  if (savings > 0) {
    printf("\nCongratulations! You are saving $%.2f each month.", savings);
  } 
  else if (savings == 0) {
    printf("\nYour income and expenses are balanced. Try increasing your income or reducing your expenses.");
  } 
  else {
    printf("\nYou are spending more than your income. You need to reduce your expenses.");
  }
  
  return 0;
}