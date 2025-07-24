//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>

int main() {
  // initialize variables
  int numItems, itemPrice, total = 0;
  char itemName[30];

  // prompt user for number of items
  printf("Enter the number of items: ");
  scanf("%d", &numItems);

  // loop through each item
  for (int i = 0; i < numItems; i++) {
    // prompt user for item name and price
    printf("\nEnter the name of item %d: ", i+1);
    scanf("%s", &itemName);
    printf("Enter the price of item %d: ", i+1);
    scanf("%d", &itemPrice);

    // add item price to total
    total += itemPrice;
    printf("%s added for %d dollars.\n", itemName, itemPrice);
  }

  // print total and end program
  printf("\nTotal bill: %d dollars\n", total);
  return 0;
}