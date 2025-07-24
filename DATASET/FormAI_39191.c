//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>

int main() {
  float income, expenses, saving_goal;
  int months, total_expenses = 0, total_savings = 0;
  
  // User input for monthly income, expenses, and saving goals
  printf("Enter your monthly income: ");
  scanf("%f", &income);
  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);
  printf("Enter your savings goal: ");
  scanf("%f", &saving_goal);
  printf("Enter the number of months you want to plan for: ");
  scanf("%d", &months);
  
  // Calculate total expenses and total savings for the duration of the plan
  total_expenses = expenses * months;
  total_savings = (income - expenses) * months;
  
  // Output of the calculation to the user
  printf("\nFor %d months:\n\n", months);
  printf("Total expected expenses: $%d\n", total_expenses);
  printf("Total expected savings: $%d\n", total_savings);
  
  // Determine if the user can reach their savings goal
  if (total_savings >= saving_goal) {
    printf("\nCongratulations! You will reach your savings goal in %d months.", months);
  } else {
    printf("\nYou will not reach your savings goal in %d months.", months);
  }
  
  return 0;
}