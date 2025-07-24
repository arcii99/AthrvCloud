//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// structure for expenses
struct expense {
  char category[50];
  float amount;
};

// function to get expense details
void getExpense(struct expense *e) {
  printf("Enter expense category: ");
  scanf("%s", e->category);
  printf("Enter expense amount: ");
  scanf("%f", &e->amount);
}

// function to display expense details
void displayExpense(struct expense e) {
  printf("%s - $%.2f\n", e.category, e.amount);
}

int main() {
  // variables for total income and expenses
  float income, totalExpenses = 0;

  // get input from user for income
  printf("Enter monthly income: ");
  scanf("%f", &income);

  // get input from user for number of expenses
  int numExpenses;
  printf("Enter number of monthly expenses: ");
  scanf("%d", &numExpenses);

  // create array of expenses
  struct expense expenses[numExpenses];

  // get details for each expense and add to total expenses
  printf("\n-- Enter expense details --\n");
  for (int i = 0; i < numExpenses; i++) {
    printf("Expense #%d:\n", i+1);
    getExpense(&expenses[i]);
    totalExpenses += expenses[i].amount;
  }

  // calculate net income and output result
  float netIncome = income - totalExpenses;
  printf("\n-- Budget Summary --\n");
  printf("Net Income: $%.2f\n", netIncome);
  printf("Total Expenses: $%.2f\n", totalExpenses);

  // display each expense
  printf("\n-- Expenses --\n");
  for (int i = 0; i < numExpenses; i++) {
    printf("Expense #%d: ", i+1);
    displayExpense(expenses[i]);
  }

  return 0;
}