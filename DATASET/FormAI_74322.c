//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>

int main() {
  int numItems = 0;
  float totalCost = 0.00;
  char itemName[50];
  
  printf("Welcome to the Cafe of Infinite Possibility! What would you like to order?\n");
  printf("Enter '0' to stop ordering.\n\n");

  while(1) {
    printf("Item %d: ", numItems + 1);
    scanf("%s", itemName);

    if (strcmp(itemName, "0") == 0) {
      break;
    }

    float itemCost = ((numItems * 0.01) + 1.00) * strlen(itemName); //Cost formula. Don't ask.
    printf("%s will cost $%.2f.\n", itemName, itemCost);

    numItems++;
    totalCost += itemCost;
  }

  printf("\nThank you for your order!\n\n");

  printf("Total cost of your order is: $%.2f\n", totalCost);
  printf("Have a great day in this impossible cafe!");

  return 0;
}