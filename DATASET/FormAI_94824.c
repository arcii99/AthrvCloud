//FormAI DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
  char name[100];
  int cost;
  char description[255];
};

void printExpenses(struct Expense *expenses, int numOfExpenses);
int getTotalExpenses(struct Expense *expenses, int numOfExpenses);
int getMaxExpense(struct Expense *expenses, int numOfExpenses);

int main() {
  int numOfExpenses = 0;
  struct Expense expenses[100];
  char input[255];

  printf("Welcome to the Medieval Expense Tracker!\n");

  while (1) {
    printf("Enter expense name (or 'done' to exit): ");
    fgets(input, 255, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "done") == 0) {
      break;
    }

    strcpy(expenses[numOfExpenses].name, input);

    printf("Enter expense cost in gold coins: ");
    fgets(input, 255, stdin);
    input[strcspn(input, "\n")] = '\0';

    expenses[numOfExpenses].cost = atoi(input);

    printf("Enter a brief description of the expense: ");
    fgets(input, 255, stdin);
    input[strcspn(input, "\n")] = '\0';

    strcpy(expenses[numOfExpenses].description, input);

    printf("Expense recorded!\n");

    numOfExpenses++;
  }

  printf("\nExpenses:\n");
  printExpenses(expenses, numOfExpenses);

  printf("\nTotal Expenses: %d gold coins\n", getTotalExpenses(expenses, numOfExpenses));

  printf("\nHighest Expense: %d gold coins on ", getMaxExpense(expenses, numOfExpenses));
  for (int i = 0; i < numOfExpenses; i++) {
    if (expenses[i].cost == getMaxExpense(expenses, numOfExpenses)) {
      printf("%s\n", expenses[i].name);
    }
  }

  return 0;
}

void printExpenses(struct Expense *expenses, int numOfExpenses) {
  for (int i = 0; i < numOfExpenses; i++) {
    printf("- %s: %d gold coins - %s\n", expenses[i].name, expenses[i].cost, expenses[i].description);
  }
}

int getTotalExpenses(struct Expense *expenses, int numOfExpenses) {
  int total = 0;

  for (int i = 0; i < numOfExpenses; i++) {
    total += expenses[i].cost;
  }

  return total;
}

int getMaxExpense(struct Expense *expenses, int numOfExpenses) {
  int maxExpense = 0;

  for (int i = 0; i < numOfExpenses; i++) {
    if (expenses[i].cost > maxExpense) {
      maxExpense = expenses[i].cost;
    }
  }

  return maxExpense;
}