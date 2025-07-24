//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>

int main()
{
  float income, rent, groceries, transportation, utilities, other_expenses;
  
  printf("Enter your monthly income: ");
  scanf("%f", &income);
  
  printf("Enter your monthly rent or mortgage payment: ");
  scanf("%f", &rent);
  
  printf("Enter your monthly groceries expenses: ");
  scanf("%f", &groceries);
  
  printf("Enter your monthly transportation expenses: ");
  scanf("%f", &transportation);
  
  printf("Enter your monthly utilities expenses: ");
  scanf("%f", &utilities);
  
  printf("Enter any other monthly expenses: ");
  scanf("%f", &other_expenses);
  
  float total_expenses = rent + groceries + transportation + utilities + other_expenses;
  float remaining_income = income - total_expenses;
  
  printf("Total monthly expenses: %.2f\n", total_expenses);
  printf("Remaining income: %.2f\n", remaining_income);
  
  if (remaining_income < 0) {
    printf("You are spending more than you're earning. You need to cut back on your expenses.\n");
  } else if (remaining_income == 0) {
    printf("You are spending all of your income, consider making some changes to increase your savings.\n");
  } else {
    printf("You have some extra income leftover. Consider saving or investing it.\n");
  }
  
  return 0;
}