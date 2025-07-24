//FormAI DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50

typedef struct {
  float amount;
  char category[20];
  char description[100];
} Expense;

int main() {
  int numExpenses = 0;
  Expense expenses[MAX_EXPENSES];

  while (1) {
    printf("Enter expense ($0.00 to quit):\n");
    scanf("%f", &expenses[numExpenses].amount);
    if (expenses[numExpenses].amount == 0.00) {
      break;
    }

    printf("Enter category:\n");
    scanf("%s", expenses[numExpenses].category);

    printf("Enter description:\n");
    scanf(" %[^\n]%*c", expenses[numExpenses].description);

    numExpenses++;

    if (numExpenses >= MAX_EXPENSES) {
      printf("Maximum number of expenses reached.\n");
      break;
    }
  }

  // Print expenses
  printf("\nExpense tracker:\n");
  printf("------------------------------\n");
  printf("%-10s %-20s %s\n", "Amount", "Category", "Description");
  printf("------------------------------\n");
  for (int i = 0; i < numExpenses; i++) {
    printf("$%-9.2f %-20s %s\n", expenses[i].amount, expenses[i].category, expenses[i].description);
  }
  printf("------------------------------\n");

  return 0;
}