//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: distributed
#include <stdio.h>

int main() {
  float budget, expenses, total_expenses = 0;
  int num_items = 0;
  char item_name[20];

  printf("Enter your budget for the month: ");
  scanf("%f", &budget);

  while (1) {
    printf("Enter the name of the item (or enter 'done' to finish): ");
    scanf("%s", item_name);

    if (strcmp(item_name, "done") == 0) {
      break; // exit loop
    }

    printf("Enter the cost of the item: ");
    scanf("%f", &expenses);
    total_expenses += expenses;
    num_items++;
  }

  printf("\n===== Monthly Budget Report =====\n");
  printf("Total Budget: $%.2f\n", budget);
  printf("Total Expenses: $%.2f\n", total_expenses);
  printf("Number of Items: %d\n", num_items);

  float remaining_budget = budget - total_expenses;

  if (remaining_budget < 0) {
    printf("You are over budget by $%.2f\n", remaining_budget*-1);
  } else {
    printf("Remaining Budget: $%.2f\n", remaining_budget);
  }

  return 0;
}