//FormAI DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Declare variables for tracking expenses
  int numExpenses;
  float expenses[1000];
  float total = 0.0;

  // Ask user for number of expenses and store it
  printf("Enter the number of expenses: ");
  scanf("%d", &numExpenses);

  // Loop through and ask for each expense, then add it to the total
  for(int i=0; i<numExpenses; i++) {
    printf("Enter expense #%d: ", i+1);
    scanf("%f", &expenses[i]);
    total += expenses[i];
  }

  // Display the total expenses
  printf("Total expenses: $%.2f\n", total);

  return 0;
}