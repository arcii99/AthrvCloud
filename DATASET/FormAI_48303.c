//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Item structure
typedef struct {
    char name[20];
    int quantity;
} Item;

// Warehouse structure
typedef struct {
    char name[20];
    Item items[MAX_ITEMS];
    int num_items;
} Warehouse;

// Function declarations
void add_item(Warehouse* wh, char* item_name, int quantity);
void remove_item(Warehouse* wh, char* item_name, int quantity);
void print_inventory(Warehouse* wh);

int main() {
    // Create a new warehouse
    Warehouse wh;
    strcpy(wh.name, "My Warehouse");
    wh.num_items = 0;

    // Add some initial items
    add_item(&wh, "Widget", 10);
    add_item(&wh, "Gadget", 5);

    // Print initial inventory
    print_inventory(&wh);

    // Remove some items
    remove_item(&wh, "Widget", 3);
    remove_item(&wh, "Gadget", 1);

    // Print updated inventory
    print_inventory(&wh);

    return 0;
}

void add_item(Warehouse* wh, char* item_name, int quantity) {
    // Check if item already exists
    for (int i = 0; i < wh->num_items; i++) {
        if (strcmp(wh->items[i].name, item_name) == 0) {
            wh->items[i].quantity += quantity;
            return;
        }
    }

    // Item does not exist yet, add it
    strcpy(wh->items[wh->num_items].name, item_name);
    wh->items[wh->num_items].quantity = quantity;
    wh->num_items++;
}

void remove_item(Warehouse* wh, char* item_name, int quantity) {
    // Check if item exists
    for (int i = 0; i < wh->num_items; i++) {
        if (strcmp(wh->items[i].name, item_name) == 0) {
            wh->items[i].quantity -= quantity;

            // Remove item if it is now 0 or less
            if (wh->items[i].quantity <= 0) {
                for (int j = i; j < wh->num_items-1; j++) {
                    wh->items[j] = wh->items[j+1];
                }
                wh->num_items--;
            }
            return;
        }
    }
}

void print_inventory(Warehouse* wh) {
    printf("Inventory for warehouse '%s':\n", wh->name);
    printf("-------------------------\n");
    for (int i = 0; i < wh->num_items; i++) {
        printf("%s: %d\n", wh->items[i].name, wh->items[i].quantity);
    }
}