//FormAI DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for inventory items
typedef struct {
    char name[50];
    int quantity;
    float price;
} InventoryItem;

// Function to add item to inventory
void addItem(InventoryItem *inventory, int *numItems, char *name, int quantity, float price) {
    InventoryItem newItem;
    strcpy(newItem.name, name);
    newItem.quantity = quantity;
    newItem.price = price;
    inventory[*numItems] = newItem;
    *numItems += 1;
    printf("Item added to inventory.\n");
}

// Function to remove item from inventory
void removeItem(InventoryItem *inventory, int *numItems, char *name) {
    int foundIndex = -1;
    for (int i = 0; i < *numItems; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex != -1) {
        for (int j = foundIndex; j < *numItems - 1; j++) {
            inventory[j] = inventory[j + 1];
        }
        *numItems -= 1;
        printf("Item removed from inventory.\n");
    } else {
        printf("Item not found in inventory.\n");
    }
}

// Function to update item quantity in inventory
void updateQuantity(InventoryItem *inventory, int *numItems, char *name, int quantity) {
    int foundIndex = -1;
    for (int i = 0; i < *numItems; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex != -1) {
        inventory[foundIndex].quantity = quantity;
        printf("Item quantity updated.\n");
    } else {
        printf("Item not found in inventory.\n");
    }
}

// Function to update item price in inventory
void updatePrice(InventoryItem *inventory, int *numItems, char *name, float price) {
    int foundIndex = -1;
    for (int i = 0; i < *numItems; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex != -1) {
        inventory[foundIndex].price = price;
        printf("Item price updated.\n");
    } else {
        printf("Item not found in inventory.\n");
    }
}

// Function to print inventory
void printInventory(InventoryItem *inventory, int numItems) {
    printf("Inventory:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d - $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    InventoryItem inventory[50];
    int numItems = 0;

    // Add some items to inventory
    addItem(inventory, &numItems, "Apple", 10, 0.50);
    addItem(inventory, &numItems, "Banana", 15, 0.75);
    addItem(inventory, &numItems, "Orange", 12, 0.60);

    // Print inventory
    printInventory(inventory, numItems);

    // Remove an item from inventory
    removeItem(inventory, &numItems, "Banana");

    // Print inventory
    printInventory(inventory, numItems);

    // Update quantity of an item
    updateQuantity(inventory, &numItems, "Apple", 15);

    // Print inventory
    printInventory(inventory, numItems);

    // Update price of an item
    updatePrice(inventory, &numItems, "Orange", 0.75);

    // Print inventory
    printInventory(inventory, numItems);

    return 0;
}