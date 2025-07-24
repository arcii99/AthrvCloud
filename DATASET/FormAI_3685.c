//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>

int main() {
  float monthly_income, rent, bills, groceries, dining_out, transportation, insurance, entertainment, savings, total_expenses;
  
  // Input section
  printf("Enter your monthly income: ");
  scanf("%f", &monthly_income);
  printf("Enter your monthly rent expense: ");
  scanf("%f", &rent);
  printf("Enter your monthly bills expense: ");
  scanf("%f", &bills);
  printf("Enter your monthly groceries expense: ");
  scanf("%f", &groceries);
  printf("Enter your monthly dining out expense: ");
  scanf("%f", &dining_out);
  printf("Enter your monthly transportation expense: ");
  scanf("%f", &transportation);
  printf("Enter your monthly insurance expense: ");
  scanf("%f", &insurance);
  printf("Enter your monthly entertainment expense: ");
  scanf("%f", &entertainment);
  printf("Enter your monthly savings: ");
  scanf("%f", &savings);
  
  // Calculation section
  total_expenses = rent + bills + groceries + dining_out + transportation + insurance + entertainment;
  printf("\nTotal expenses: $%.2f\n", total_expenses);
  
  float leftover = monthly_income - total_expenses - savings;
  if (leftover < 0) {
    printf("\nYou are in a deficit of $%.2f\n", leftover);
  } 
  else {
    printf("\nLeftover money: $%.2f\n", leftover);
  }
  
  return 0;
}