//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>

#define MAX_ITEMS 100

struct Item {
  char name[20];
  int quantity;
};

struct Inventory {
  struct Item items[MAX_ITEMS];
  int count;
};

void add_item(struct Inventory *inv, char *name, int quantity);
void remove_item(struct Inventory *inv, char *name, int quantity);
void display_inventory(struct Inventory *inv);

int main() {
  struct Inventory inv = {0};

  add_item(&inv, "Widget A", 10);
  add_item(&inv, "Widget B", 5);
  add_item(&inv, "Widget C", 7);
  remove_item(&inv, "Widget A", 3);
  display_inventory(&inv);

  return 0;
}

void add_item(struct Inventory *inv, char *name, int quantity) {
  if (inv->count == MAX_ITEMS) {
    printf("Error: Inventory is full\n");
    return;
  }

  for (int i = 0; i < inv->count; i++) {
    if (strcmp(inv->items[i].name, name) == 0) {
      inv->items[i].quantity += quantity;
      return;
    }
  }

  strcpy(inv->items[inv->count].name, name);
  inv->items[inv->count].quantity = quantity;
  inv->count++;
}

void remove_item(struct Inventory *inv, char *name, int quantity) {
  for (int i = 0; i < inv->count; i++) {
    if (strcmp(inv->items[i].name, name) == 0) {
      inv->items[i].quantity -= quantity;
      if (inv->items[i].quantity < 0) {
        inv->items[i].quantity = 0;
      }
      return;
    }
  }

  printf("Error: Item not found\n");
}

void display_inventory(struct Inventory *inv) {
  printf("Inventory:\n");
  for (int i = 0; i < inv->count; i++) {
    printf("%s - %d\n", inv->items[i].name, inv->items[i].quantity);
  }
}