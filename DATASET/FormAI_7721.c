//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>

int main() {
  float income, rent, utilities, groceries, transportation, misc_expenses, savings;
  
  printf("Welcome to your Personal Finance Planner!\n");
  
  printf("Please enter your monthly income: ");
  scanf("%f", &income);
  
  printf("Please enter your monthly rent/mortgage payment: ");
  scanf("%f", &rent);
  
  printf("Please enter your monthly utility bills: ");
  scanf("%f", &utilities);
  
  printf("Please enter your monthly grocery expenses: ");
  scanf("%f", &groceries);
  
  printf("Please enter your monthly transportation expenses: ");
  scanf("%f", &transportation);
  
  printf("Please enter your other monthly expenses: ");
  scanf("%f", &misc_expenses);
  
  savings = income - rent - utilities - groceries - transportation - misc_expenses;
  
  printf("\n----------\n");
  printf("Your monthly budget breakdown:\n");
  printf("Income: $%.2f\n", income);
  printf("Rent/Mortgage: $%.2f\n", rent);
  printf("Utilities: $%.2f\n", utilities);
  printf("Groceries: $%.2f\n", groceries);
  printf("Transportation: $%.2f\n", transportation);
  printf("Other Expenses: $%.2f\n", misc_expenses);
  printf("Savings: $%.2f\n", savings);
  
  printf("\nBased on your income, recommended savings amount is $%.2f\n", (income * 0.2));
  
  return 0;
}