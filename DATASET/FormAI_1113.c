//FormAI DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>

// Define constants for the maximum amount of items and their names
#define MAX_ITEMS 1000
#define MAX_ITEM_NAME_LENGTH 50

// Define the Item struct
typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Define the Inventory struct
typedef struct {
    Item items[MAX_ITEMS];
    int numItems;
} Inventory;

// Declare a function to add items to the inventory
void addItem(Inventory *inventory, char name[], int quantity, float price) {
    // If the inventory is full, print an error message and return
    if (inventory->numItems >= MAX_ITEMS) {
        printf("Error: Inventory is full\n");
        return;
    }

    // Create a new item and add it to the inventory
    Item newItem;
    sprintf(newItem.name, "%s", name);
    newItem.quantity = quantity;
    newItem.price = price;
    inventory->items[inventory->numItems] = newItem;
    inventory->numItems++;

    // Print a success message
    printf("%d %s items added to inventory for $%.2f each\n", quantity, name, price);
}

// Declare a function to remove items from the inventory
void removeItem(Inventory *inventory, char name[], int quantity) {
    int i, j;
    int removed = 0;

    // Loop through the items in the inventory and remove the requested quantity of the item with the matching name
    for (i = 0; i < inventory->numItems; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            if (inventory->items[i].quantity >= quantity) {
                inventory->items[i].quantity -= quantity;
                removed += quantity;
                printf("%d %s items removed from inventory\n", quantity, name);
                break;
            } else {
                removed += inventory->items[i].quantity;
                printf("%d %s items removed from inventory\n", inventory->items[i].quantity, name);
                // Shift the remaining items down to fill the gap
                for (j = i + 1; j < inventory->numItems; j++) {
                    inventory->items[j - 1] = inventory->items[j];
                }
                inventory->numItems--;
            }
        }
    }

    // If no items were removed, print an error message
    if (removed == 0) {
        printf("Error: %s items not found in inventory\n", name);
    }
}

// Declare a function to print the current inventory
void printInventory(Inventory inventory) {
    int i;

    printf("Current Inventory:\n");
    for (i = 0; i < inventory.numItems; i++) {
        printf("%d %s items, $%.2f each\n", inventory.items[i].quantity, inventory.items[i].name, inventory.items[i].price);
    }
}

int main() {
    // Initialize an empty inventory
    Inventory inventory = { .items={}, .numItems=0 };

    // Add items to the inventory
    addItem(&inventory, "Apples", 20, 0.50);
    addItem(&inventory, "Bananas", 15, 0.35);
    addItem(&inventory, "Oranges", 10, 0.25);

    // Remove items from the inventory
    removeItem(&inventory, "Apples", 10);
    removeItem(&inventory, "Pears", 5);

    // Print the current inventory
    printInventory(inventory);

    return 0;
}