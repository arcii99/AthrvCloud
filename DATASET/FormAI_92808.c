//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include<stdio.h>

int main() {

  float monthly_income, monthly_expenses, monthly_savings, annual_income, annual_expenses, annual_savings;
  int age, retirement_age, years_to_retire;
  
  printf("Welcome to the Personal Finance Planner\n\n");
  
  printf("Please enter your monthly income: ");
  scanf("%f", &monthly_income);
  
  printf("Please enter your monthly expenses: ");
  scanf("%f", &monthly_expenses);
  
  monthly_savings = monthly_income - monthly_expenses;
  annual_income = monthly_income * 12;
  annual_expenses = monthly_expenses * 12;
  annual_savings = monthly_savings * 12;
  
  printf("\nYour monthly savings is $%.2f\n", monthly_savings);
  printf("Your annual income is $%.2f\n", annual_income);
  printf("Your annual expenses is $%.2f\n", annual_expenses);
  printf("Your annual savings is $%.2f\n\n", annual_savings);
  
  printf("Please enter your age: ");
  scanf("%d", &age);
  
  printf("Please enter the age you plan to retire at: ");
  scanf("%d", &retirement_age);
  
  years_to_retire = retirement_age - age;
  
  printf("\nYou plan to retire in %d years\n\n", years_to_retire);
  
  float monthly_savings_goal = annual_expenses / 12;
  float total_savings_goal = monthly_savings_goal * years_to_retire * 12;
  
  printf("To retire in %d years at the age of %d, you need to save $%.2f per month\n", years_to_retire, retirement_age, monthly_savings_goal);
  printf("Your total savings goal is $%.2f\n\n", total_savings_goal);
  
  return 0;
}