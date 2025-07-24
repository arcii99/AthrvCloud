//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: brave
#include <stdio.h>

int main() {
  // Variables to store user input and financial data
  double salary, expenses, savings, debt, net_worth;
  int age, retirement_age;
  
  // Getting user input to fill in the variables
  printf("Please enter your salary: ");
  scanf("%lf", &salary);
  
  printf("Please enter your monthly expenses: ");
  scanf("%lf", &expenses);
  
  printf("Please enter the amount of debt you have: ");
  scanf("%lf", &debt);
  
  printf("Please enter your age: ");
  scanf("%d", &age);
  
  printf("Please enter the age you plan to retire: ");
  scanf("%d", &retirement_age);
  
  // Calculating financial data
  savings = salary * 0.2;
  net_worth = (salary - expenses) * 12 - debt;
  
  // Printing out financial data
  printf("Your savings each month should be at least $%.2lf.\n", savings);
  printf("Your net worth is $%.2lf.\n", net_worth);
  
  // Checking if user can retire based on financial data and retirement age
  if (net_worth >= 1000000 && age <= retirement_age) {
    printf("Congratulations, you can retire!\n");
  } else {
    printf("Sorry, you cannot retire yet.\n");
  }
  
  return 0;
}