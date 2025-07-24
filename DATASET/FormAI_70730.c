//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
  float salary, rent, food, transport, savings, total_expenses;
  
  printf("Welcome to your Personal Finance Planner! Let's get started...\n");
  
  printf("Please enter your monthly salary: ");
  scanf("%f", &salary);
  
  printf("Please enter your monthly rent: ");
  scanf("%f", &rent);
  
  printf("Please enter your monthly food expenses: ");
  scanf("%f", &food);
  
  printf("Please enter your monthly transport expenses: ");
  scanf("%f", &transport);
  
  printf("Please enter the amount you would like to save each month: ");
  scanf("%f", &savings);
  
  total_expenses = rent + food + transport;
  
  if (total_expenses > salary) {
    printf("\nUh-oh! It looks like your expenses are higher than your income. You might need to consider making some adjustments.\n");
  } else {
    printf("\nGreat job! You're living below your means. Keep up the good work!\n");
  }
  
  float disposable_income = salary - total_expenses - savings;
  
  if (disposable_income <= 0) {
    printf("\nLooks like you have no disposable income left over for fun stuff. Maybe consider finding ways to cut back on expenses.\n");
  } else {
    printf("\nCongratulations! You have $%.2f left over each month for fun stuff. Time to treat yourself!\n", disposable_income);
  }
  
  printf("\nThank you for using your Personal Finance Planner. Have a great day!\n");
  
  return 0;
}