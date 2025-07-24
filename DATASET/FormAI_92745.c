//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEM_DESCRIPTION_LENGTH 100

struct Item {
  char name[MAX_ITEM_NAME_LENGTH];
  char description[MAX_ITEM_DESCRIPTION_LENGTH];
  int quantity;
  float price;
};

struct Warehouse {
  struct Item items[MAX_ITEMS];
  int num_items;
};

void print_item(struct Item item);
void add_item(struct Warehouse *warehouse, struct Item item);
void remove_item(struct Warehouse *warehouse, int item_index);
void display_warehouse(struct Warehouse warehouse);
void update_quantity(struct Warehouse *warehouse, int item_index, int new_quantity);

int main() {
  // Initialize warehouse
  struct Warehouse warehouse;
  warehouse.num_items = 0;

  // Add initial items to warehouse
  struct Item item1 = {"Laptop", "Thin and powerful", 10, 999.99};
  add_item(&warehouse, item1);

  struct Item item2 = {"Smartphone", "Fast and reliable", 20, 499.99};
  add_item(&warehouse, item2);

  // Display warehouse
  display_warehouse(warehouse);

  // Remove an item
  remove_item(&warehouse, 0);

  // Display warehouse again
  display_warehouse(warehouse);

  // Update quantity of an item
  update_quantity(&warehouse, 0, 5);

  // Display warehouse again
  display_warehouse(warehouse);

  return 0;
}

void print_item(struct Item item) {
  printf("%s (%d) - %s - $%.2f\n", item.name, item.quantity, item.description, item.price);
}

void add_item(struct Warehouse *warehouse, struct Item item) {
  if (warehouse->num_items == MAX_ITEMS) {
    printf("Warehouse is full!\n");
    return;
  }

  warehouse->items[warehouse->num_items] = item;
  warehouse->num_items++;
}

void remove_item(struct Warehouse *warehouse, int item_index) {
  if (item_index < 0 || item_index >= warehouse->num_items) {
    printf("Invalid item index!\n");
    return;
  }

  for (int i = item_index; i < warehouse->num_items - 1; i++) {
    warehouse->items[i] = warehouse->items[i+1];
  }

  warehouse->num_items--;
}

void display_warehouse(struct Warehouse warehouse) {
  printf("Warehouse Contents:\n");
  printf("-------------------\n");

  for (int i = 0; i < warehouse.num_items; i++) {
    print_item(warehouse.items[i]);
  }

  printf("\n");
}

void update_quantity(struct Warehouse *warehouse, int item_index, int new_quantity) {
  if (item_index < 0 || item_index >= warehouse->num_items) {
    printf("Invalid item index!\n");
    return;
  }

  warehouse->items[item_index].quantity = new_quantity;
}