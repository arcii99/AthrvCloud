//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>

int main() {
  double monthly_income, rent, utilities, groceries, transportation, entertainment, saving_goal;
  double total_expenses, leftover_income;
  
  // Get inputs from the user
  printf("Enter your monthly income: ");
  scanf("%lf", &monthly_income);
  
  printf("Enter your monthly rent: ");
  scanf("%lf", &rent);
  
  printf("Enter your monthly utilities bill: ");
  scanf("%lf", &utilities);
  
  printf("Enter your monthly groceries expense: ");
  scanf("%lf", &groceries);
  
  printf("Enter your monthly transportation expense: ");
  scanf("%lf", &transportation);
  
  printf("Enter your monthly entertainment expense: ");
  scanf("%lf", &entertainment);
  
  printf("Enter your monthly saving goal: ");
  scanf("%lf", &saving_goal);
  
  // Calculate the total expenses and leftover income
  total_expenses = rent + utilities + groceries + transportation + entertainment;
  leftover_income = monthly_income - total_expenses;

  // Show the results to the user
  printf("\n\n");
  printf("Your total monthly expenses are: %.2lf\n", total_expenses);
  printf("Your leftover monthly income is: %.2lf\n", leftover_income);
  
  if(leftover_income >= saving_goal) {
    printf("You have met your monthly saving goal! Congrats!\n");
  } else {
    printf("You have not met your monthly saving goal. You need to save at least $%.2lf more.\n", saving_goal - leftover_income);
  }

  return 0;
}