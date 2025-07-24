//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Product {
  char name[25];
  int quantity;
  float price;
};

struct Warehouse {
  struct Product products[MAX_SIZE];
  int count;
};

void addProduct(struct Warehouse *warehouse, char name[], int quantity, float price) {
  if (warehouse == NULL) return;
  if (warehouse->count == MAX_SIZE) {
    printf("The warehouse is full!\n");
    return;
  }

  struct Product product;
  strcpy(product.name, name);
  product.quantity = quantity;
  product.price = price;

  warehouse->products[warehouse->count] = product;
  warehouse->count++;

  printf("Product with name '%s' successfully added to the warehouse.\n", product.name);
}

void removeProduct(struct Warehouse *warehouse, char name[]) {
  if (warehouse == NULL) return;
  int i;
  for (i = 0; i < warehouse->count; i++) {
    if (strcmp(warehouse->products[i].name, name) == 0) {
      break;
    }
  }
  if (i == warehouse->count) {
    printf("Product with name '%s' not found in the warehouse.\n", name);
    return;
  }
  for (; i < warehouse->count-1; i++) {
    warehouse->products[i] = warehouse->products[i+1];
  }
  warehouse->count--;
  printf("Product with name '%s' successfully removed from the warehouse.\n", name);
}

void searchProduct(struct Warehouse *warehouse, char name[]) {
  if (warehouse == NULL) return;
  int i;
  for (i = 0; i < warehouse->count; i++) {
    if (strcmp(warehouse->products[i].name, name) == 0) {
      printf("Product with name '%s' found. Quantity: %d, Price: %0.2f\n",
        name, warehouse->products[i].quantity, warehouse->products[i].price);
      return;
    }
  }
  printf("Product with name '%s' not found in the warehouse.\n", name);
}

int main() {
  struct Warehouse warehouse;
  warehouse.count = 0;

  addProduct(&warehouse, "Apple", 100, 0.60);
  addProduct(&warehouse, "Orange", 50, 0.40);
  addProduct(&warehouse, "Pear", 75, 0.50);

  searchProduct(&warehouse, "Apple");
  searchProduct(&warehouse, "Banana");

  removeProduct(&warehouse, "Orange");
  removeProduct(&warehouse, "Grapes");

  return 0;
}