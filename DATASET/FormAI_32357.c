//FormAI DATASET v1.0 Category: Expense Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
  char name[50];
  float cost;
};

int main() {
  int numExpenses;
  float totalCost = 0.00;

  printf("How many expenses have you had this month? ");
  scanf("%d", &numExpenses);

  struct Expense expenses[numExpenses];

  for(int i = 0; i < numExpenses; i++) {
    printf("\nEnter the name of expense #%d: ", i+1);
    scanf("%s", expenses[i].name);
    printf("Enter the cost of %s: $", expenses[i].name);
    scanf("%f", &expenses[i].cost);
    totalCost += expenses[i].cost;
  }

  printf("\nYour expenses for the month are:\n");
  for(int i = 0; i < numExpenses; i++) {
    printf("%s: $%.2f\n", expenses[i].name, expenses[i].cost);
  }
  printf("\nTotal cost for the month: $%.2f\n", totalCost);
}