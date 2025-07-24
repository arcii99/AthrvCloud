//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} InventoryItem;

typedef struct {
    InventoryItem items[MAX_ITEMS];
    int count;
} Inventory;

void add_item(Inventory *inventory, char *name, int quantity) {
    bool item_added = false;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            inventory->items[i].quantity += quantity;
            item_added = true;
            break;
        }
    }

    if (!item_added) {
        if (inventory->count >= MAX_ITEMS) {
            printf("Inventory is full. Cannot add any more items.\n");
            return;
        }
        InventoryItem new_item;
        strcpy(new_item.name, name);
        new_item.quantity = quantity;
        inventory->items[inventory->count++] = new_item;
    }
}

void remove_item(Inventory *inventory, char *name, int quantity) {
   for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            if (inventory->items[i].quantity >= quantity) {
                inventory->items[i].quantity -= quantity;
                if (inventory->items[i].quantity == 0) {
                    // Remove item if quantity becomes zero
                    for (int j = i; j < inventory->count - 1; j++) {
                        inventory->items[j] = inventory->items[j+1];
                    }
                    inventory->count--;
                }
                return;
            } else {
                printf("Insufficient quantity of item in inventory.\n");
                return;
            }
        }
    }
    printf("Item not found in inventory.\n");
}

int main() {
    Inventory inventory = { .count = 0 };
    
    // Add some items to inventory
    add_item(&inventory, "item1", 5);
    add_item(&inventory, "item2", 10);
    add_item(&inventory, "item3", 15);

    // Remove some items from inventory
    remove_item(&inventory, "item3", 7);
    remove_item(&inventory, "item2", 11);
    remove_item(&inventory, "item1", 4);

    // Print the final inventory status
    printf("Inventory:\n");
    for (int i = 0; i < inventory.count; i++) {
        printf("%s %d\n", inventory.items[i].name, inventory.items[i].quantity);
    }

    return 0;
}