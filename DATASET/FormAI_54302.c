//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>

// Define data structures
typedef struct {
    char name[50];
    int quantity;
} Item;

typedef struct {
    char name[50];
    Item items[100];
    int itemCount;
} Warehouse;

// Define global variables
Warehouse warehouses[10];
int warehouseCount = 0;

// Function to add a new item to a warehouse
void addItemToWarehouse(char* warehouseName, char* itemName, int quantity) {
    int foundWarehouse = 0;
    for (int i = 0; i < warehouseCount; i++) {
        if (strcmp(warehouses[i].name, warehouseName) == 0) {
            // Add the item to the warehouse
            Item newItem;
            strcpy(newItem.name, itemName);
            newItem.quantity = quantity;
            warehouses[i].items[warehouses[i].itemCount++] = newItem;
            foundWarehouse = 1;
            break;
        }
    }
    if (!foundWarehouse) {
        // Create a new warehouse if it doesn't already exist
        Warehouse newWarehouse;
        strcpy(newWarehouse.name, warehouseName);
        Item newItem;
        strcpy(newItem.name, itemName);
        newItem.quantity = quantity;
        newWarehouse.items[0] = newItem;
        newWarehouse.itemCount = 1;
        warehouses[warehouseCount++] = newWarehouse;
    }
}

// Function to remove an item from a warehouse
void removeItemFromWarehouse(char* warehouseName, char* itemName) {
    for (int i = 0; i < warehouseCount; i++) {
        if (strcmp(warehouses[i].name, warehouseName) == 0) {
            // Remove the item from the warehouse
            for (int j = 0; j < warehouses[i].itemCount; j++) {
                if (strcmp(warehouses[i].items[j].name, itemName) == 0) {
                    for (int k = j; k < warehouses[i].itemCount - 1; k++) {
                        warehouses[i].items[k] = warehouses[i].items[k+1];
                    }
                    warehouses[i].itemCount--;
                    break;
                }
            }   
        }
    }
}

int main() {
    // Add items to the warehouses
    addItemToWarehouse("Warehouse A", "Widget 1", 10);
    addItemToWarehouse("Warehouse B", "Widget 2", 5);
    addItemToWarehouse("Warehouse A", "Widget 3", 20);
    addItemToWarehouse("Warehouse C", "Widget 4", 15);

    // Remove an item from a warehouse
    removeItemFromWarehouse("Warehouse A", "Widget 1");

    // Print out the warehouses and their items
    for (int i = 0; i < warehouseCount; i++) {
        printf("%s\n", warehouses[i].name);
        for (int j = 0; j < warehouses[i].itemCount; j++) {
            printf("%s: %d\n", warehouses[i].items[j].name, warehouses[i].items[j].quantity);
        }
    }

    return 0;
}