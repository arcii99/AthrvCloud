//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>

int main() {
  printf("Welcome to your Personal Finance Planner!\n");
  printf("Let's get started:\n");

  float balance, income, expenses; // declare variables for balance, income and expenses
  int choice = 0; 

  printf("Enter your current balance: ");
  scanf("%f", &balance);
  printf("Enter your monthly income: ");
  scanf("%f", &income);
  printf("Enter your estimated monthly expenses: ");
  scanf("%f", &expenses);

  printf("\nYour current balance is: $%.2f\n", balance);
  printf("Your monthly income is: $%.2f\n", income);
  printf("Your estimated monthly expenses are: $%.2f\n", expenses);

  float savings = income - expenses; // calculate savings
  printf("Your estimated monthly savings is: $%.2f\n", savings);

  while (choice != 4) { // loop until the user exits the program
    printf("\nWhat would you like to do?\n");
    printf("1. Add to your balance\n");
    printf("2. Subtract from your balance\n");
    printf("3. Calculate your projected savings\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: // add to balance
        float addAmount;
        printf("\nEnter the amount you would like to add: $");
        scanf("%f", &addAmount);
        balance += addAmount;
        printf("Your new balance is: $%.2f\n", balance);
        break;

      case 2: // subtract from balance
        float subAmount;
        printf("\nEnter the amount you would like to subtract: $");
        scanf("%f", &subAmount);
        balance -= subAmount;
        printf("Your new balance is: $%.2f\n", balance);
        break;

      case 3: // calculate projected savings
        float months;
        printf("\nHow many months would you like to project? ");
        scanf("%f", &months);
        float projectedSavings = savings * months;
        printf("Your projected savings after %d months is: $%.2f\n", (int)months, projectedSavings);
        break;

      case 4: // exit program
        printf("\nThank you for using your Personal Finance Planner.\n");
        break;

      default: // handle invalid input
        printf("\nInvalid input. Please enter a number between 1 and 4.\n");
        break;
    }
  }
  return 0;
}