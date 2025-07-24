//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Struct for inventory item 
typedef struct item {
    char itemName[MAX_SIZE];
    int quantity;
} Item;

// Struct for warehouse location 
typedef struct location {
    int aisle;
    int rack;
    int level;
} Location;

// Struct for inventory movement transaction 
typedef struct transaction {
    char itemName[MAX_SIZE];
    Location fromLocation;
    Location toLocation;
    int quantityMoved;
} Transaction;

// Function to display inventory at a particular location 
void displayItem(Item inventory[MAX_SIZE], Location loc) {
    printf("\n\nItem Name: %s\nQuantity: %d\nLocation: Aisle - %d, Rack - %d, Level - %d\n", inventory[loc.aisle * 100 + loc.rack * 10 + loc.level].itemName, inventory[loc.aisle * 100 + loc.rack * 10 + loc.level].quantity, loc.aisle, loc.rack, loc.level);
}

// Function to perform inventory movement between two locations 
void inventoryMove(Item inventory[MAX_SIZE], Location fromLoc, Location toLoc, int quantity) {
    // Check if from location and to location are valid 
    if (inventory[fromLoc.aisle * 100 + fromLoc.rack * 10 + fromLoc.level].quantity < quantity) {
        printf("\n\nError: Not enough quantity to move!\n");
        return;
    }
    else if (inventory[toLoc.aisle * 100 + toLoc.rack * 10 + toLoc.level].quantity + quantity > MAX_SIZE) {
        printf("\n\nError: Maximum inventory limit in destination location exceeded!\n");
        return;
    }

    // Perform inventory movement 
    strcpy(inventory[toLoc.aisle * 100 + toLoc.rack * 10 + toLoc.level].itemName, inventory[fromLoc.aisle * 100 + fromLoc.rack * 10 + fromLoc.level].itemName);
    inventory[toLoc.aisle * 100 + toLoc.rack * 10 + toLoc.level].quantity += quantity;
    inventory[fromLoc.aisle * 100 + fromLoc.rack * 10 + fromLoc.level].quantity -= quantity;

    // Print the inventory movement transaction details 
    printf("\n\nInventory Movement Transaction Details:\n");
    printf("Item Name: %s\nQuantity Moved: %d\nFrom Location: Aisle - %d, Rack - %d, Level - %d\nTo Location: Aisle - %d, Rack - %d, Level - %d\n", inventory[toLoc.aisle * 100 + toLoc.rack * 10 + toLoc.level].itemName, quantity, fromLoc.aisle, fromLoc.rack, fromLoc.level, toLoc.aisle, toLoc.rack, toLoc.level);
}

int main() {
    // Initialize the inventory array 
    Item inventory[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        strcpy(inventory[i].itemName, "Empty");
        inventory[i].quantity = 0;
    }

    // Add some items to inventory 
    strcpy(inventory[23].itemName, "Item 1");
    inventory[23].quantity = 50;
    strcpy(inventory[125].itemName, "Item 2");
    inventory[125].quantity = 25;
    strcpy(inventory[981].itemName, "Item 3");
    inventory[981].quantity = 75;

    // Display warehouse inventory list 
    printf("Warehouse Inventory List:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (strcmp(inventory[i].itemName, "Empty") != 0) {
            printf("Item Name: %s\nQuantity: %d\nLocation: Aisle - %d, Rack - %d, Level - %d\n", inventory[i].itemName, inventory[i].quantity, i / 100, (i % 100) / 10, i % 10);
        }
    }

    // Display item details at a particular location 
    Location loc = {2, 3, 0};
    displayItem(inventory, loc);

    // Perform inventory movement transaction 
    Location fromLoc = {2, 3, 0};
    Location toLoc = {4, 1, 2};
    int quantity = 20;
    inventoryMove(inventory, fromLoc, toLoc, quantity);

    // Display updated warehouse inventory list 
    printf("Updated Warehouse Inventory List:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (strcmp(inventory[i].itemName, "Empty") != 0) {
            printf("Item Name: %s\nQuantity: %d\nLocation: Aisle - %d, Rack - %d, Level - %d\n", inventory[i].itemName, inventory[i].quantity, i / 100, (i % 100) / 10, i % 10);
        }
    }

    return 0;
}