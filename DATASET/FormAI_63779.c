//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>

int main() {
  int total_items = 0;
  float subtotal = 0.0, discount_amount = 0.0, tax_amount = 0.0, grand_total = 0.0;
  char item_name[30];
  float item_price = 0.0;
  int quantity = 0;
  
  printf("Welcome to the Surreal Cafe!\n");
  printf("Enter the number of items you wish to order: ");
  scanf("%d", &total_items);
  
  for (int i = 1; i <= total_items; i++) {
    printf("\nItem %d\n", i);
    printf("Enter the name of the item: ");
    scanf("%s", item_name);
    printf("Enter the price of the item: ");
    scanf("%f", &item_price);
    printf("Enter the quantity of the item: ");
    scanf("%d", &quantity);
    
    printf("\n%s  %.2f  %d  %.2f", item_name, item_price, quantity, item_price*quantity);
    subtotal += item_price * quantity;
  }
  
  printf("\n----------------------------\n");
  printf("\nSubtotal: $%.2f\n", subtotal);
  
  if (subtotal >= 50.00) {
    discount_amount = (subtotal * 10) / 100;
    printf("Discount (10%% off total): $%.2f\n", discount_amount);
  }
  
  tax_amount = (subtotal - discount_amount) * 0.07;
  printf("Tax (7%%): $%.2f\n", tax_amount);
  
  grand_total = (subtotal - discount_amount) + tax_amount;
  printf("\nGrand Total: $%.2f\n", grand_total);
  
  printf("\nThank you for visiting the Surreal Cafe!\n");
  
  return 0;
}