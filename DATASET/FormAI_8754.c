//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: artistic
#include <stdio.h>

int main() {
  float monthly_income, monthly_expenses, savings_rate, annual_salary, bonus_percentage, taxes;

  printf("Welcome to your Personal Finance Planner!\n");
  printf("Please enter your monthly income: ");
  scanf("%f", &monthly_income);
  printf("Please enter your monthly expenses: ");
  scanf("%f", &monthly_expenses);
  printf("Please enter your desired savings rate (as a decimal): ");
  scanf("%f", &savings_rate);
  
  annual_salary = monthly_income * 12;
  taxes = annual_salary * 0.25;

  if (annual_salary > 75000) {
    bonus_percentage = 0.10;
  } else if (annual_salary > 50000 && annual_salary <= 75000) {
    bonus_percentage = 0.08;
  } else {
    bonus_percentage = 0.05;
  }

  float bonus = annual_salary * bonus_percentage;

  printf("\nThank you for your input! Here are your results:\n");
  printf("Annual Salary: $%.2f\n", annual_salary);
  printf("Taxes: $%.2f\n", taxes);
  printf("Annual Bonus: $%.2f\n", bonus);
  printf("Monthly Savings: $%.2f\n", monthly_income * savings_rate);
  printf("Monthly Spending: $%.2f\n", monthly_expenses);

  return 0;
}