//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  float total = 0;
  printf("Welcome to the Dream Cafe Apothecary. Our menu is inspired by your deepest dreams.\n\n");
  printf("Please enter the number of items you would like to order from the menu: ");
  int numItems;
  scanf("%d", &numItems);

  char* items[numItems];
  float prices[numItems];

  for (int i = 0; i < numItems; i++) {
    printf("\nEnter the name of the dream dish: ");
    char itemName[50];
    scanf("%s", itemName);
    items[i] = itemName;

    printf("Enter the price of the dream dish: ");
    float price;
    scanf("%f", &price);
    prices[i] = price;

    total += price;
  }

  printf("\n\nYour order summary: \n\n");
  for (int i = 0; i < numItems; i++) {
    printf("%s - $%.2f\n", items[i], prices[i]);
  }

  printf("\nTotal: $%.2f\n", total);
  printf("Thank you for visiting the Dream Cafe Apothecary. Sweet Dreams!\n");

  return 0;
}