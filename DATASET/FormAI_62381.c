//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum number of items the store can hold

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Inventory {
    struct Item items[MAX_ITEMS];
    int count;
};

// Function declarations
void initialize_inventory(struct Inventory* inventory);
void add_item_to_inventory(struct Inventory* inventory, char* name, int quantity, float price);
void remove_item_from_inventory(struct Inventory* inventory, char* name);
void display_inventory(struct Inventory inventory);
void update_item_quantity(struct Inventory* inventory, char* name, int new_quantity);

int main() {
    struct Inventory inventory;
    initialize_inventory(&inventory);

    // Add some items to the inventory
    add_item_to_inventory(&inventory, "Paracetamol", 50, 10.0);
    add_item_to_inventory(&inventory, "Ibuprofen", 30, 15.0);
    add_item_to_inventory(&inventory, "Aspirin", 25, 5.0);

    // Display the inventory
    printf("Inventory:\n");
    display_inventory(inventory);

    // Update the quantity of an item
    update_item_quantity(&inventory, "Paracetamol", 60);

    // Display the updated inventory
    printf("\nUpdated Inventory:\n");
    display_inventory(inventory);

    // Remove an item from the inventory
    remove_item_from_inventory(&inventory, "Aspirin");

    // Display the inventory after removing an item
    printf("\nInventory after removing an item:\n");
    display_inventory(inventory);

    return 0;
}

// Initialize the inventory with empty items
void initialize_inventory(struct Inventory* inventory) {
    inventory->count = 0;
}

// Add an item to the inventory
void add_item_to_inventory(struct Inventory* inventory, char* name, int quantity, float price) {
    struct Item item;
    strcpy(item.name, name);
    item.quantity = quantity;
    item.price = price;

    inventory->items[inventory->count] = item;
    inventory->count++;
}

// Remove an item from the inventory
void remove_item_from_inventory(struct Inventory* inventory, char* name) {
    int index = -1;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < inventory->count - 1; i++) {
            inventory->items[i] = inventory->items[i+1];
        }
        inventory->count--;
    }
}

// Display the inventory
void display_inventory(struct Inventory inventory) {
    printf("Name\t\tQuantity\tPrice\n");
    for (int i = 0; i < inventory.count; i++) {
        printf("%s\t\t%d\t\t%.2f\n", inventory.items[i].name, inventory.items[i].quantity, inventory.items[i].price);
    }
}

// Update the quantity of an item
void update_item_quantity(struct Inventory* inventory, char* name, int new_quantity) {
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            inventory->items[i].quantity = new_quantity;
            break;
        }
    }
}