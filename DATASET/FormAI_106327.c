//FormAI DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <string.h>

struct Expense {
  char item[20];
  float cost;
};

int main() {

  struct Expense expenses[10];
  int count = 0;
  char choice = 'y';

  printf("\n***** RETRO EXPENSE TRACKER *****\n\n");

  while (choice == 'y') {

    printf("Enter item name: ");
    scanf("%s", expenses[count].item);
    printf("Enter cost: ");
    scanf("%f", &expenses[count].cost);

    count++;

    printf("\nAdd another item? (y/n): ");
    scanf(" %c", &choice);

    // Limit to 10 expenses
    if (count == 10) {
      printf("Maximum number of expenses reached.\n\n");
      break;
    }
  }

  // Print summary of expenses
  printf("\n***** EXPENSE TRACKER SUMMARY *****\n\n");
  printf("%-20s %s\n", "Item", "Cost");
  printf("----------------------------------\n");
  float total = 0;
  for (int i = 0; i < count; i++) {
    printf("%-20s $%.2f\n", expenses[i].item, expenses[i].cost);
    total += expenses[i].cost;
  }
  printf("----------------------------------\n");
  printf("%-20s $%.2f\n", "TOTAL", total);

  return 0;
}