//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>

int main() {
  float monthly_income, expenses, savings;
  int num_of_months, i;
  
  printf("Welcome to Personal Finance Planner\n");
  printf("----------------------------------\n");
  
  printf("Enter your monthly income: $");
  scanf("%f", &monthly_income);
  
  printf("Enter your monthly expenses: $");
  scanf("%f", &expenses);
  
  printf("Enter the number of months to plan for: ");
  scanf("%d", &num_of_months);
  
  printf("\nMONTHLY BUDGET PLANNER\n");
  printf("----------------------\n");
  
  printf("Starting Balance: $%.2f\n", monthly_income);
  
  for (i = 1; i <= num_of_months; i++) {
    savings = monthly_income - expenses;
    printf("Month %d: $%.2f\n", i, savings);
    monthly_income += savings;
  }
  
  printf("----------------------\n");
  printf("Ending Balance: $%.2f\n\n", monthly_income);
  
  return 0;
}