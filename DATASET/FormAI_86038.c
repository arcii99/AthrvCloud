//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the Personal Finance Planner!\n");
  printf("Let's see how much money you've spent this month...\n");

  float income, rent, bills, food, entertainment;
  float totalExpenses = 0;

  printf("What's your income this month?: $");
  scanf("%f", &income);

  printf("How much is your rent?: $");
  scanf("%f", &rent);
  totalExpenses += rent;

  printf("How much are your bills?: $");
  scanf("%f", &bills);
  totalExpenses += bills;

  printf("How much have you spent on food?: $");
  scanf("%f", &food);
  totalExpenses += food;

  printf("How much have you spent on entertainment?: $");
  scanf("%f", &entertainment);
  totalExpenses += entertainment;

  float remainingBalance = income - totalExpenses;
  printf("\n\n\n");
  if (remainingBalance > 0) {
    printf("Congratulations! You still have $%.2f left to spend this month!\n", remainingBalance);
  } else if (remainingBalance == 0) {
    printf("Phew! You broke even this month!\n");
  } else {
    printf("Uh oh... you've spent more than you earned this month :( \n");
    printf("You're $%.2f over budget... maybe consider selling some of your useless items?\n", -remainingBalance);
  }

  return 0;
}