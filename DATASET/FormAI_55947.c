//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>

int main() {
  float income, rent, utilities, food, transportation, savings;
  
  // Welcome prompt
  printf("Welcome to the Personal Finance Planner!\n\n");
  
  // Income input
  printf("Please enter your monthly income: $");
  scanf("%f", &income);
  
  // Expenses input
  printf("Please enter your monthly rent: $");
  scanf("%f", &rent);
  
  printf("Please enter your monthly utilities bill: $");
  scanf("%f", &utilities);
  
  printf("Please enter your monthly food expenses: $");
  scanf("%f", &food);
  
  printf("Please enter your monthly transportation expenses: $");
  scanf("%f", &transportation);
  
  // Calculation of remaining income and recommended savings
  float totalExpenses = rent + utilities + food + transportation;
  float remainingIncome = income - totalExpenses;
  
  if (remainingIncome >= 0 && remainingIncome <= (0.2 * income)) {
    savings = 0.05 * income;
  } else if (remainingIncome > (0.2 * income) && remainingIncome <= (0.5 * income)) {
    savings = 0.1 * income;
  } else if (remainingIncome > (0.5 * income)) {
    savings = 0.15 * income;
  } else {
    printf("Your expenses exceed your income!");
    return 1;
  }
  
  // Output of results and recommended savings
  printf("\nIncome: $%.2f\n", income);
  printf("Expenses: $%.2f\n", totalExpenses);
  printf("Remaining income: $%.2f\n", remainingIncome);
  printf("Recommended monthly savings: $%.2f\n", savings);
  
  return 0;
}