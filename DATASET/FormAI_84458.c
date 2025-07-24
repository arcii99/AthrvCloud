//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Claude Shannon
#include <stdio.h>

int main() {
  // Define variables
  float salary, rent, utilities, groceries, savings, totalExpenses;
  
  // User Interface
  printf("Welcome to your Personal Finance Planner!\n");

  // Ask user for input
  printf("Please enter your monthly salary: $");
  scanf("%f", &salary);
  
  printf("Please enter your monthly rent: $");
  scanf("%f", &rent);
  
  printf("Please enter your monthly utility bills: $");
  scanf("%f", &utilities);
  
  printf("Please enter your monthly grocery expenses: $");
  scanf("%f", &groceries);
  
  printf("Please enter your desired monthly savings: $");
  scanf("%f", &savings);

  // Calculate total expenses
  totalExpenses = rent + utilities + groceries + savings;
  
  // Display results to the user
  printf("\n--Your Monthly Expense Breakdown--\n");
  printf("Rent: $%.2f\n", rent);
  printf("Utility Bills: $%.2f\n", utilities);
  printf("Groceries: $%.2f\n", groceries);
  printf("Savings: $%.2f\n", savings);
  printf("Total Expenses: $%.2f\n", totalExpenses);

  // Check if total expenses exceed salary
  if (totalExpenses > salary) {
    printf("\nWarning: Your expenses exceed your salary! Please consider reducing your expenses.\n");
  }
  
  return 0;
}