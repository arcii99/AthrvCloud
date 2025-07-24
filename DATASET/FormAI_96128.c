//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
  char name[50];
  int id;
  int quantity;
  float price;
};

struct Inventory {
  struct Product products[MAX_PRODUCTS];
  int count;
};

struct Inventory inventory;

void addProduct(char *name, int id, int quantity, float price);
void removeProduct(int id);
void printInventory();

int main() {
  inventory.count = 0;

  addProduct("Product A", 1001, 10, 5.99);
  addProduct("Product B", 1002, 15, 9.99);
  addProduct("Product C", 1003, 20, 12.99);

  printInventory();

  removeProduct(1002);

  printInventory();

  return 0;
}

void addProduct(char *name, int id, int quantity, float price) {
  if (inventory.count < MAX_PRODUCTS) {
    struct Product product;
    strcpy(product.name, name);
    product.id = id;
    product.quantity = quantity;
    product.price = price;
    inventory.products[inventory.count++] = product;
  } else {
    printf("Error: inventory is full\n");
  }
}

void removeProduct(int id) {
  int i, found = 0;
  for (i = 0; i < inventory.count; i++) {
    if (inventory.products[i].id == id) {
      found = 1;
      break;
    }
  }

  if (found) {
    inventory.count--;
    for (; i < inventory.count; i++) {
      inventory.products[i] = inventory.products[i + 1];
    }
  } else {
    printf("Error: product not found\n");
  }
}

void printInventory() {
  int i;
  for (i = 0; i < inventory.count; i++) {
    printf("Name: %s\n", inventory.products[i].name);
    printf("ID: %d\n", inventory.products[i].id);
    printf("Quantity: %d\n", inventory.products[i].quantity);
    printf("Price: $%.2f\n", inventory.products[i].price);
    printf("\n");
  }
}