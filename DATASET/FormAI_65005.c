//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>

int main() {
  //declare variables
  float monthly_income, monthly_expenses, savings_rate, savings_amount, remaining_income;
  
  //ask user for input
  printf("Enter your monthly income: ");
  scanf("%f", &monthly_income);
  printf("Enter your monthly expenses: ");
  scanf("%f", &monthly_expenses);
  
  //calculate savings rate
  savings_rate = (monthly_income - monthly_expenses) / monthly_income * 100;
  
  //calculate savings amount
  savings_amount = monthly_income - monthly_expenses;
  
  //calculate remaining income
  remaining_income = monthly_income - savings_amount;
  
  //print out results
  printf("Your savings rate is: %.2f%%\n", savings_rate);
  printf("Your monthly savings amount is: $%.2f\n", savings_amount);
  printf("Your remaining monthly income is: $%.2f\n", remaining_income);
  
  return 0;
}