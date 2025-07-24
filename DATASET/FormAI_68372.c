//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  char customer_name[50];
  int item_count;
  float unit_price, total_price, grand_total = 0;

  printf("Welcome to The Baker's Cafe!\n");
  printf("Please enter your name: ");
  scanf("%s", &customer_name);
  printf("\n");

  do {
    printf("How many items would you like to order, %s?\n", customer_name);
    scanf("%d", &item_count);
    printf("\n");
    if (item_count <= 0) {
      printf("Please enter a valid number of items.\n");
    }
  } while (item_count <= 0);

  printf("Please enter the unit price for each item: ");
  scanf("%f", &unit_price);
  printf("\n");

  total_price = item_count * unit_price;
  grand_total += total_price;

  printf("Your order summary:\n");
  printf("Customer Name: %s\n", customer_name);
  printf("No. of items: %d\n", item_count);
  printf("Unit Price: %.2f\n", unit_price);
  printf("Total Price: %.2f\n", total_price);
  printf("\n");
  printf("Grand Total: %.2f\n", grand_total);

  printf("\nThank you for your patronage!");

  return 0;
}