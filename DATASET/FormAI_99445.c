//FormAI DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  //Welcome the user to the Expense Tracker program.
  printf("Welcome to the Expense Tracker!\n");

  //Declare variables to hold the expense data.
  float rent, groceries, utilities, transportation, entertainment, total;

  //Prompt the user to input their monthly expenses.
  printf("Please input your monthly rent: ");
  scanf("%f", &rent);

  printf("Please input your monthly grocery expenses: ");
  scanf("%f", &groceries);

  printf("Please input your monthly utilities expenses: ");
  scanf("%f", &utilities);

  printf("Please input your monthly transportation expenses: ");
  scanf("%f", &transportation);

  printf("Please input your monthly entertainment expenses: ");
  scanf("%f", &entertainment);

  //Calculate the total monthly expenses.
  total = rent + groceries + utilities + transportation + entertainment;

  //Print out the total monthly expenses.
  printf("\nYour total monthly expenses are: $%.2f", total);

  //Inspiring quote to encourage saving.
  printf("\nRemember, every penny saved is a penny earned!");

  return 0;
}