//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>

int main() {
  float income, expenses, savings, total_expenses = 0.0;
  int num_of_expenses;

  printf("\nWelcome to your Personal Finance Planner!\n");
  printf("Please enter your monthly income: ");
  scanf("%f", &income);

  printf("\nPlease enter the number of expenses you have this month: ");
  scanf("%d", &num_of_expenses);

  float individual_expense[num_of_expenses];
  for(int i = 0; i < num_of_expenses; i++) {
    printf("\nEnter expense cost #%d: ", i+1);
    scanf("%f", &individual_expense[i]);
    total_expenses += individual_expense[i];
  }

  expenses = total_expenses;
  savings = income - expenses;

  printf("\nYour Financial Planner\n");
  printf("----------------------\n");
  printf("Income: $%.2f\n", income);
  printf("Expenses: $%.2f\n", expenses);
  printf("Savings: $%.2f\n", savings);

  int option;
  printf("\nWhat else can I help you with today?\n");
  printf("1. Calculate your monthly savings goal\n");
  printf("2. Calculate the percentage of your income that goes towards expenses\n");
  printf("3. Exit\n");

  printf("\nEnter your selected option: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
      float goal;
      printf("\nHow much would you like to save monthly? ");
      scanf("%f", &goal);

      if(goal > savings) {
        printf("\nYou need to save $%.2f more to reach your goal\n", goal - savings);
      } else {
        printf("\nCongratulations! You are on track to reach your monthly saving goal.\n");
      }
      break;

    case 2:
      float expense_percentage;
      expense_percentage = (expenses / income) * 100;
      printf("\n%.2f%% of your income goes towards expenses.\n", expense_percentage);
      break;

    case 3:
      printf("\nThank you for using your Personal Finance Planner. Have a great day!\n");
      return 0;

    default:
      printf("\nInvalid option selected\n");

  }
  return 0;
}