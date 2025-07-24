//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>

int main() {
  float income, rent, bills, groceries, entertainment, savings, totalExpenses;
  
  printf("Welcome to Personal Finance Planner!\n");
  printf("Let's get started with some questions...\n\n");

  printf("What is your monthly income? $");
  scanf("%f", &income);

  printf("How much do you pay for rent? $");
  scanf("%f", &rent);

  printf("How much are your monthly bills (utilities, internet, phone, etc.)? $");
  scanf("%f", &bills);

  printf("How much do you typically spend on groceries each month? $");
  scanf("%f", &groceries);

  printf("How much do you typically spend on entertainment each month (movies, dining out, etc.)? $");
  scanf("%f", &entertainment);

  printf("How much are you planning to save each month? $");
  scanf("%f", &savings);

  totalExpenses = rent + bills + groceries + entertainment;

  printf("\n\n***** Summary *****\n");
  printf("Monthly Income: $%.2f\n", income);
  printf("Monthly Rent: $%.2f\n", rent);
  printf("Monthly Bills: $%.2f\n", bills);
  printf("Monthly Groceries: $%.2f\n", groceries);
  printf("Monthly Entertainment: $%.2f\n", entertainment);
  printf("Monthly Savings: $%.2f\n", savings);
  printf("Total Monthly Expenses: $%.2f\n", totalExpenses);

  if (totalExpenses > income) {
    printf("\n***** Warning! *****\n");
    printf("You are spending more than you are earning each month. Consider reducing your expenses or increasing your income.\n");
  } else {
    printf("\n***** Congratulations! *****\n");
    printf("You are living within your means and saving money each month.\n");
  }

  return 0;
}