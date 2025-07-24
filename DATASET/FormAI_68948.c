//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  char name[50];
  int quantity;
  float price;
};

struct Warehouse {
  struct Item inventory[100];
  int num_items;
  char name[50];
};

void add_item(struct Warehouse *w, struct Item i) {
  w->inventory[w->num_items] = i;
  w->num_items++;
}

void remove_item(struct Warehouse *w, char *name) {
  for (int i = 0; i < w->num_items; i++) {
    if (strcmp(w->inventory[i].name, name) == 0) {
      for (int j = i; j < w->num_items - 1; j++) {
        w->inventory[j] = w->inventory[j+1];
      }
      w->num_items--;
      break;
    }
  }
}

void display_inventory(struct Warehouse w) {
  printf("Inventory for warehouse %s:\n\n", w.name);
  printf("%-20s %-10s %-10s\n", "Item", "Quantity", "Price");
  printf("--------------------------------------\n");
  for (int i = 0; i < w.num_items; i++) {
    printf("%-20s %-10d $%-9.2f\n", w.inventory[i].name, w.inventory[i].quantity, w.inventory[i].price);
  }
}

int main() {
  struct Warehouse w = { .num_items = 0, .name = "Warehouse 1" };
  
  struct Item i1 = { .name = "Apples", .quantity = 10, .price = 1.99 };
  struct Item i2 = { .name = "Oranges", .quantity = 5, .price = 2.50 };
  struct Item i3 = { .name = "Bananas", .quantity = 20, .price = 0.99 };
  
  add_item(&w, i1);
  add_item(&w, i2);
  add_item(&w, i3);
  
  display_inventory(w);
  
  remove_item(&w, "Oranges");
  
  display_inventory(w);
  
  return 0;
}