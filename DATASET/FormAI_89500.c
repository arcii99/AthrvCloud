//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>

int main(void) {
  int option;
  float balance = 0.00;
  printf("Welcome to Happy Personal Finance Planner!\n");

  while (1) {
    printf("\nWhat would you like to do today?\n");
    printf("1. View current balance\n");
    printf("2. Add income\n");
    printf("3. Add expense\n");
    printf("4. Exit\n");
    scanf("%d", &option);

    switch(option) {
      case 1:
        printf("\nYour current balance is: $%.2f\n", balance);
        break;
      case 2:
        float income;
        printf("\nEnter income amount: $");
        scanf("%f", &income);
        balance += income;
        printf("Income added successfully!\n");
        break;
      case 3:
        float expense;
        printf("\nEnter expense amount: $");
        scanf("%f", &expense);
        if (balance < expense) {
          printf("You don't have enough balance to add this expense. Please try a smaller amount.\n");
        } else {
          balance -= expense;
          printf("Expense added successfully!\n");
        }
        break;
      case 4:
        printf("\nThank you for using Happy Personal Finance Planner! Have a great day!\n");
        return 0;
      default:
        printf("\nInvalid option selected. Please try again.\n");
        break;
    }
  }
}