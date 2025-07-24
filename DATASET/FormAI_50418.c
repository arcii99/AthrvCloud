//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WAREHOUSES 10
#define MAX_ITEMS 50
#define MAX_NAME 20

// Item structure
typedef struct Item {
    int itemID;
    char name[MAX_NAME];
    int quantity;
} Item;

// Warehouse structure
typedef struct Warehouse {
    int warehouseID;
    char name[MAX_NAME];
    Item items[MAX_ITEMS];
    int numItems;
} Warehouse;

// Global variables
Warehouse warehouses[MAX_WAREHOUSES];
int numWarehouses = 0;

// Function to add a new warehouse
void addWarehouse(int warehouseID, char* name) {
    Warehouse newWarehouse;
    newWarehouse.warehouseID = warehouseID;
    strcpy(newWarehouse.name, name);
    newWarehouse.numItems = 0;
    warehouses[numWarehouses++] = newWarehouse;
}

// Function to add a new item to a warehouse
void addItem(int warehouseID, int itemID, char* itemName, int quantity) {
    for(int i=0; i<numWarehouses; i++) {
        if(warehouses[i].warehouseID == warehouseID) {
            Item newItem;
            newItem.itemID = itemID;
            strcpy(newItem.name, itemName);
            newItem.quantity = quantity;
            warehouses[i].items[warehouses[i].numItems++] = newItem;
            break;
        }
    }
}

// Function to print the inventory of a warehouse
void printInventory(int warehouseID) {
    printf("Inventory of Warehouse %d:\n", warehouseID);
    for(int i=0; i<numWarehouses; i++) {
        if(warehouses[i].warehouseID == warehouseID) {
            for(int j=0; j<warehouses[i].numItems; j++) {
                printf("%d. %s - %d\n", warehouses[i].items[j].itemID, warehouses[i].items[j].name, warehouses[i].items[j].quantity);
            }
            break;
        }
    }
}

int main() {
    // Adding warehouses
    addWarehouse(1, "Warehouse A");
    addWarehouse(2, "Warehouse B");
    
    // Adding items to Warehouse A
    addItem(1, 1, "Item 1", 10);
    addItem(1, 2, "Item 2", 5);
    addItem(1, 3, "Item 3", 20);
    
    // Adding items to Warehouse B
    addItem(2, 4, "Item 4", 15);
    addItem(2, 5, "Item 5", 8);
    
    // Printing inventory of Warehouse A
    printInventory(1);
    
    // Printing inventory of Warehouse B
    printInventory(2);
    
    return 0;
}