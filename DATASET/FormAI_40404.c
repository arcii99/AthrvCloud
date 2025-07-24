//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
  char name[50];
  int id;
  float price;
} Item;

typedef struct {
  Item items[MAX_ITEMS];
  int count;
} Inventory;

void add_item(Inventory* inv, Item item) {
  if (inv->count < MAX_ITEMS) {
    inv->items[inv->count] = item;
    inv->count++;
  }
}

void print_item(Item item) {
  printf("Name: %s\n", item.name);
  printf("ID: %d\n", item.id);
  printf("Price: $%.2f\n", item.price);
}

void print_inventory(Inventory* inv) {
  for (int i = 0; i < inv->count; i++) {
    printf("Item #%d:\n", i+1);
    print_item(inv->items[i]);
    printf("\n");
  }
}

int main() {
  Inventory inv;
  inv.count = 0;

  Item item1 = {"Apple", 123, 0.99};
  Item item2 = {"Orange", 456, 1.50};
  Item item3 = {"Banana", 789, 0.50};

  add_item(&inv, item1);
  add_item(&inv, item2);
  add_item(&inv, item3);

  printf("Current Inventory:\n");
  print_inventory(&inv);

  printf("Searching for item with ID 456...\n");
  for (int i = 0; i < inv.count; i++) {
    if (inv.items[i].id == 456) {
      printf("Item found:\n");
      print_item(inv.items[i]);
      break;
    }
  }

  return 0;
}