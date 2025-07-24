//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the maximum capacity of the warehouse
#define MAX_CAPACITY 50

// Define the structure of the warehouse item
typedef struct {
    int id;
    char name[20];
    int quantity;
    float price;
} Item;

// Define the warehouse inventory array
Item inventory[MAX_CAPACITY];

// Define the current inventory count
int inventoryCount = 0;

// Add a new item to the warehouse inventory
void addItem(int id, char name[], int quantity, float price) {
    // Check if the warehouse has reached maximum capacity
    if(inventoryCount >= MAX_CAPACITY) {
        printf("Sorry, the warehouse is full.\n");
        return;
    }

    // Check if the item already exists in the warehouse
    for(int i = 0; i < inventoryCount; i++) {
        if(inventory[i].id == id) {
            printf("Item with id %d already exists in the warehouse.\n", id);
            return;
        }
    }

    // Add the new item to the warehouse inventory
    inventory[inventoryCount].id = id;
    strcpy(inventory[inventoryCount].name, name);
    inventory[inventoryCount].quantity = quantity;
    inventory[inventoryCount].price = price;
    inventoryCount++;

    printf("Item with id %d added to the warehouse.\n", id);
}

// Remove an item from the warehouse inventory
void removeItem(int id) {
    // Search for the item in the warehouse inventory
    int index = -1;
    for(int i = 0; i < inventoryCount; i++) {
        if(inventory[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if the item was found
    if(index == -1) {
        printf("Item with id %d not found in the warehouse.\n", id);
        return;
    }

    // Remove the item from the warehouse inventory
    for(int i = index; i < inventoryCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    inventoryCount--;

    printf("Item with id %d removed from the warehouse.\n", id);
}

// Search for an item in the warehouse inventory
void searchItem(int id) {
    // Search for the item in the warehouse inventory
    int index = -1;
    for(int i = 0; i < inventoryCount; i++) {
        if(inventory[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if the item was found
    if(index == -1) {
        printf("Item with id %d not found in the warehouse.\n", id);
        return;
    }

    // Print the item details
    printf("ID: %d\n", inventory[index].id);
    printf("Name: %s\n", inventory[index].name);
    printf("Quantity: %d\n", inventory[index].quantity);
    printf("Price: $%.2f\n", inventory[index].price);
}

// Print the warehouse inventory
void printInventory() {
    printf("Warehouse Inventory:\n");
    printf("--------------------\n");
    for(int i = 0; i < inventoryCount; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: $%.2f\n", inventory[i].price);
        printf("--------------------\n");
    }
}

int main() {
    // Add some initial items to the warehouse inventory
    addItem(1, "Item 1", 10, 5.99);
    addItem(2, "Item 2", 5, 9.99);
    addItem(3, "Item 3", 20, 7.99);

    // Print the initial warehouse inventory
    printInventory();

    // Remove an item from the warehouse inventory
    removeItem(2);

    // Search for an item in the warehouse inventory
    searchItem(3);

    // Add a new item to the warehouse inventory
    addItem(4, "Item 4", 15, 11.99);

    // Print the updated warehouse inventory
    printInventory();

    return 0;
}