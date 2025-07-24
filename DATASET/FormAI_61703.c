//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>

int main() {

  float income, rent, utilities, groceries, transportation, entertainment, savings, total_expenses;
  
  printf("Enter your monthly income: $");
  scanf("%f", &income);
  
  printf("Enter your monthly rent payment: $");
  scanf("%f", &rent);
  
  printf("Enter your average monthly utility bill: $");
  scanf("%f", &utilities);
  
  printf("Enter your average monthly grocery bill: $");
  scanf("%f", &groceries);
  
  printf("Enter your average monthly transportation costs: $");
  scanf("%f", &transportation);
  
  printf("Enter your average monthly entertainment expenses: $");
  scanf("%f", &entertainment);
  
  printf("Enter the percentage of your income you would like to save: ");
  scanf("%f", &savings);
  
  // Calculate total monthly expenses
  total_expenses = rent + utilities + groceries + transportation + entertainment;
  
  // Calculate how much money should be saved
  savings = (savings/100) * income;
  
  printf("\n----------Monthly Budget Breakdown----------\n");
  
  printf("Income: $%.2f\n", income);
  printf("Rent: $%.2f\n", rent);
  printf("Utilities: $%.2f\n", utilities);
  printf("Groceries: $%.2f\n", groceries);
  printf("Transportation: $%.2f\n", transportation);
  printf("Entertainment: $%.2f\n", entertainment);
  
  printf("\nTotal Monthly Expenses: $%.2f\n", total_expenses);
  printf("Recommended Monthly Savings: $%.2f\n", savings);
  
  return 0;
}