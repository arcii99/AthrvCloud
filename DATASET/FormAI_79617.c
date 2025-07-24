//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  // Declare variables
  float income, expenses, savings_goal, savings_percent, monthly_savings;
  
  // Get user inputs
  printf("Enter your monthly income: ");
  scanf("%f", &income);
  
  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);
  
  printf("Enter your savings goal: ");
  scanf("%f", &savings_goal);
  
  printf("Enter the percentage of your income you want to save: ");
  scanf("%f", &savings_percent);
  
  // Calculate monthly savings required
  monthly_savings = (income * savings_percent) / 100;
  
  // Print results
  printf("\n=============================\n");
  printf("Monthly Income: $%.2f\n", income);
  printf("Monthly Expenses: $%.2f\n", expenses);
  printf("Savings Goal: $%.2f\n", savings_goal);
  printf("Savings Percentage: %.2f%%\n", savings_percent);
  printf("=============================\n");
  printf("Monthly Savings Required: $%.2f\n", monthly_savings);
  
  // Check if savings goal is achievable
  if (monthly_savings >= savings_goal) {
    printf("Congratulations! Your savings goal is achievable.\n");
  } else {
    printf("Sorry, your savings goal is not achievable with your current savings percentage.\n");
  }
  
  return 0;
}