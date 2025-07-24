//FormAI DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
  char name[50];
  int quantity;
  float price;
} Product;

int num_products = 0;
Product products[MAX_PRODUCTS];

void add_product(char name[], int quantity, float price) {
  // Check if product already exists
  for(int i = 0; i < num_products; i++) {
    if(strcmp(products[i].name, name) == 0) {
      // Update existing product quantity and price
      products[i].quantity += quantity;
      products[i].price = price;
      return;
    }
  }

  // Add new product
  Product new_product;
  strcpy(new_product.name, name);
  new_product.quantity = quantity;
  new_product.price = price;

  // Check if we have space in the inventory
  if(num_products < MAX_PRODUCTS) {
    products[num_products++] = new_product;
  } else {
    printf("Inventory is full\n");
  }
}

void display_products() {
  printf("| %-30s | %-10s | %-10s |\n", "Name", "Quantity", "Price");
  printf("|--------------------------------+------------+------------|\n");

  for(int i = 0; i < num_products; i++) {
    printf("| %-30s | %-10d | $%-9.2f |\n", products[i].name, products[i].quantity, products[i].price);
  }
}

int main() {
  add_product("Apples", 10, 1.99);
  add_product("Bananas", 15, 0.79);
  add_product("Oranges", 20, 2.49);
  add_product("Milk", 5, 3.99);
  add_product("Bread", 2, 1.49);

  printf("Initial inventory:\n");
  display_products();

  add_product("Milk", 3, 2.99);
  add_product("Avocado", 8, 1.50);
  add_product("Oranges", 5, 1.99);

  printf("\nUpdated inventory:\n");
  display_products();

  return 0;
}