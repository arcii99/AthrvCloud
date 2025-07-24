//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  // initialize variables
  int choice, quantity;
  float total = 0.0;

  printf("Welcome to the C Cafe!\n");

  // display menu
  printf("Menu:\n");
  printf("1. Espresso - $2.50\n");
  printf("2. Cappuccino - $3.00\n");
  printf("3. Latte - $3.50\n");

  // take user input for choice and quantity
  printf("Enter choice (1-3): ");
  scanf("%d", &choice);
  printf("Enter quantity: ");
  scanf("%d", &quantity);

  // calculate total based on choice and quantity
  switch (choice) {
    case 1:
      total += quantity * 2.5;
      break;
    case 2:
      total += quantity * 3.0;
      break;
    case 3:
      total += quantity * 3.5;
      break;
    default:
      printf("Invalid Choice\n");
      exit(0);
  }

  // display total
  printf("Total: $%.2f\n", total);

  return 0;
}