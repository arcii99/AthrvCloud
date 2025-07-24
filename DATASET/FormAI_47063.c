//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum quantity of items and length of item names
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 30

// Define a struct for a single item
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} item;

// Define a struct for the entire inventory
typedef struct {
    item items[MAX_ITEMS];
    int count;
} inventory;

// Function to add a new item to the inventory
void addItem(inventory *inv, char *name, int quantity) {
    if (inv->count >= MAX_ITEMS) {
        printf("Maximum item limit reached!\n");
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

// Function to remove an item from the inventory
void removeItem(inventory *inv, char *name, int quantity) {
    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            inv->items[i].quantity -= quantity;
            if (inv->items[i].quantity <= 0) {
                for (int j = i; j < inv->count - 1; j++) {
                    inv->items[j] = inv->items[j + 1];
                }
                inv->count--;
            }
            return;
        }
    }
    printf("Item not found!\n");
}

// Function to display the entire inventory
void displayInventory(inventory *inv) {
    printf("Warehouse Inventory:\n");
    printf("----------------------\n");
    for (int i = 0; i < inv->count; i++) {
        printf("%s - %d\n", inv->items[i].name, inv->items[i].quantity);
    }
    printf("----------------------\n");
}

int main() {
    // Initialize an empty inventory
    inventory inv;
    inv.count = 0;

    // Add items to the inventory
    addItem(&inv, "Bolt", 50);
    addItem(&inv, "Nut", 75);
    addItem(&inv, "Screwdriver", 25);
    addItem(&inv, "Hammer", 15);

    // Display the current inventory
    displayInventory(&inv);

    // Remove some items from the inventory
    removeItem(&inv, "Bolt", 10);
    removeItem(&inv, "Screwdriver", 7);

    // Display the updated inventory
    displayInventory(&inv);

    return 0;
}