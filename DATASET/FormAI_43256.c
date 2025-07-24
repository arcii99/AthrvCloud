//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  float salary, expenses;
  
  printf("Enter your monthly salary: ");
  scanf("%f", &salary);
  
  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);
  
  float savings = salary - expenses;
  printf("Your monthly savings: $%.2f\n", savings);
  
  float yearly_savings = savings * 12;
  printf("Your yearly savings: $%.2f\n", yearly_savings);
  
  float investment_rate, investment_return, investment_years;
  
  printf("Enter the annual rate of return on your investments: ");
  scanf("%f", &investment_rate);
  
  printf("Enter the number of years you plan to invest: ");
  scanf("%f", &investment_years);
  
  float future_value = yearly_savings * ((pow(1.0f + investment_rate/100.0f, investment_years) - 1.0f) / (investment_rate/100.0f));
  printf("The future value of your investments after %f years: $%.2f\n", investment_years, future_value);
  
  return 0;
}