//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_STRING_LENGTH 20

struct Item {
    char name[MAX_STRING_LENGTH];
    int quantity;
    float cost;
};

struct Inventory {
    struct Item items[MAX_ITEMS];
    int count;
};

void add_item(struct Inventory* inventory, char* name, int quantity, float cost) {
    if (inventory->count == MAX_ITEMS) {
        printf("Error: inventory is full.");
        return;
    }
    struct Item item = {0};
    strcpy(item.name, name);
    item.quantity = quantity;
    item.cost = cost;
    inventory->items[inventory->count++] = item;
}

void print_inventory(struct Inventory* inventory) {
    printf("Inventory:\n");
    printf("| %-20s| %-10s| %-10s|\n", "Name", "Quantity", "Cost");
    printf("+---------------------+-----------+-----------+\n");
    for (int i = 0; i < inventory->count; i++) {
        struct Item item = inventory->items[i];
        printf("| %-20s| %-10d| $%-9.2f|\n", item.name, item.quantity, item.cost);
    }
}

int main() {
    struct Inventory inventory = {0};
    
    add_item(&inventory, "Apples", 50, 0.50);
    add_item(&inventory, "Bananas", 25, 0.75);
    add_item(&inventory, "Oranges", 30, 0.60);
    
    print_inventory(&inventory);
    
    return 0;
}