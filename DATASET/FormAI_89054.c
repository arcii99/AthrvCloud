//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>

int main() {

  // program variables
  float salary, expenses, savings, investments;
  char response;

  // display welcome message and prompt user to enter info
  printf("Welcome to the Personal Finance Planner!\n");
  printf("Enter your monthly salary: ");
  scanf("%f", &salary);
  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);

  // calculate savings and investments
  savings = salary - expenses;
  investments = 0.3 * savings;

  // display results
  printf("\n\nYour monthly savings: $%.2f\n", savings);
  printf("Amount to Invest(30%% of savings): $%.2f\n", investments);
  printf("\n\n");

  // prompt user to continue or exit
  printf("Would you like to calculate again? (Y/N) ");
  scanf(" %c", &response);

  // if user chooses to continue, run program again
  if (response == 'Y' || response == 'y') {
      main();
  } else {
      printf("Thank you for using the Personal Finance Planner!\n");
  }

  return 0;
}