//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  float income, expenses, savings;
  
  // Get user income
  printf("Enter your monthly income: ");
  scanf("%f", &income);
  
  // Get user expenses
  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);
  
  // Calculate savings
  savings = income - expenses;
  
  // Display results
  printf("\nINCOME: $%.2f", income);
  printf("\nEXPENSES: $%.2f", expenses);
  printf("\nSAVINGS: $%.2f\n", savings);
  
  // Determine savings goal
  float goal;
  printf("What is your monthly savings goal? ");
  scanf("%f", &goal);
  
  // Determine time to reach goal
  int time;
  printf("How many months do you want to take to reach your goal? ");
  scanf("%d", &time);
  
  // Determine required monthly savings
  float monthly_savings = goal / time;
  
  // Determine if goal is achievable
  if (monthly_savings <= savings) {
    printf("\nCONGRATULATIONS! You can achieve your savings goal in %d months by saving $%.2f each month.", time, monthly_savings);
  } else {
    printf("\nSORRY, you cannot achieve your savings goal in %d months by saving $%.2f each month.\n", time, monthly_savings);
    
    // Determine necessary income increase to reach goal
    float increase = monthly_savings - savings;
    printf("You would need to increase your monthly income by $%.2f to achieve your savings goal.\n", increase);
  }
  
  return 0;
}