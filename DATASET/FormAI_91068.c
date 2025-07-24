//FormAI DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  char name[50];
  int quantity;
  float price;
};

int main() {
  int num_products;
  
  printf("How many products will you be adding to the inventory system? ");
  scanf("%d", &num_products);

  struct product products[num_products];

  for (int i = 0; i < num_products; i++) {
    printf("\nProduct %d\n", i+1);

    printf("Name: ");
    scanf("%s", products[i].name);

    printf("Quantity: ");
    scanf("%d", &products[i].quantity);

    printf("Price: ");
    scanf("%f", &products[i].price);
  }

  // Print out the product inventory
  printf("\nInventory:\n");

  for (int i = 0; i < num_products; i++) {
    printf("%s - Quantity: %d - Price: $%.2f\n", products[i].name, products[i].quantity, products[i].price);
  }

  return 0;
}