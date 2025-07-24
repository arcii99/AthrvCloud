//FormAI DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>

// define a struct to hold expense details
struct Expense {
  int id;
  char description[100];
  float amount;
};

int main() {
  // define variables to store input from user
  int numExpenses;
  char desc[100];
  float amt;

  // ask user for number of expenses to track
  printf("How many expenses do you want to track today? ");
  scanf("%d", &numExpenses);

  // define an array of Expense structs to hold expense details
  struct Expense expenses[numExpenses];

  // loop through the number of expenses entered by user
  for (int i = 0; i < numExpenses; i++) {
    // ask for expense description
    printf("Enter a description for expense #%d: ", i+1);
    scanf("%s", desc);

    // ask for expense amount
    printf("Enter the amount for expense #%d: ", i+1);
    scanf("%f", &amt);

    // create a new Expense struct with id, description, and amount
    struct Expense expense = {i+1, desc, amt};

    // add the new Expense struct to the expenses array
    expenses[i] = expense;
  }

  // print out a table of all the expenses entered by user
  printf("\nExpense ID\tDescription\tAmount\n");
  printf("---------------------------------------------------\n");
  for (int i = 0; i < numExpenses; i++) {
    struct Expense expense = expenses[i];
    printf("%d\t\t%s\t\t$%.2f\n", expense.id, expense.description, expense.amount);
  }

  return 0;
}