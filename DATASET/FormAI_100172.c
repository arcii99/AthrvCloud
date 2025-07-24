//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_ITEM_NAME_LENGTH 50

struct Item {
    int id;
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int size;
};

void add_item(struct Warehouse* warehouse, int id, char* name, int quantity) {
    if (warehouse->size >= MAX_ITEMS) {
        printf("Warehouse is already full!\n");
        return;
    }
    struct Item item = { id, "", quantity };
    strncpy(item.name, name, MAX_ITEM_NAME_LENGTH);
    warehouse->items[warehouse->size++] = item;
}

void remove_item(struct Warehouse* warehouse, int id) {
    for (int i = 0; i < warehouse->size; ++i) {
        if (warehouse->items[i].id == id) {
            memmove(&warehouse->items[i], &warehouse->items[i+1], sizeof(struct Item) * (warehouse->size-i-1));
            warehouse->size--;
            printf("Item removed from warehouse!\n");
            return;
        }
    }
    printf("Item not found in warehouse!\n");
}

void print_all_items(struct Warehouse* warehouse) {
    printf("Items in warehouse:\n");
    for (int i = 0; i < warehouse->size; ++i) {
        printf("  %d: %s (%d)\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    struct Warehouse warehouse = { .size = 0 };
    add_item(&warehouse, 1, "Computer", 10);
    add_item(&warehouse, 2, "Keyboard", 20);
    add_item(&warehouse, 3, "Mouse", 30);
    print_all_items(&warehouse);
    remove_item(&warehouse, 2);
    print_all_items(&warehouse);
    return 0;
}