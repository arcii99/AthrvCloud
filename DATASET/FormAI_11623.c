//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
  float price;
  int quantity;
} Item;

typedef struct Warehouse {
  Item inventory[MAX_ITEMS];
  int num_items;
} Warehouse;

void add_item(Warehouse *warehouse, Item item) {
  if (warehouse->num_items == MAX_ITEMS) {
    printf("Warehouse is full!\n");
    return;
  }
  
  warehouse->inventory[warehouse->num_items] = item;
  warehouse->num_items++;
}

void remove_item(Warehouse *warehouse, char *name) {
  bool found = false;
  
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->inventory[i].name, name) == 0) {
      found = true;
      
      for (int j = i; j < warehouse->num_items - 1; j++) {
        warehouse->inventory[j] = warehouse->inventory[j+1];
      }
      
      warehouse->num_items--;
      break;
    }
  }
  
  if (!found) {
    printf("Item not found in warehouse!\n");
  }
}

void print_inventory(Warehouse *warehouse) {
  printf("Warehouse Inventory:\n");
  
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("%s - $%.2f - Quantity: %d\n", warehouse->inventory[i].name, warehouse->inventory[i].price, warehouse->inventory[i].quantity);
  }
}

int main() {
  Warehouse warehouse = { .num_items = 0 };
  
  Item item1 = { .name = "Book", .price = 10.99, .quantity = 5 };
  Item item2 = { .name = "DVD", .price = 7.50, .quantity = 10 };
  Item item3 = { .name = "CD", .price = 5.99, .quantity = 7 };
  
  add_item(&warehouse, item1);
  add_item(&warehouse, item2);
  add_item(&warehouse, item3);
  
  print_inventory(&warehouse);
  
  remove_item(&warehouse, "CD");
  
  print_inventory(&warehouse);
  
  return 0;
}