//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the maximum size of the warehouse and item name length
#define MAX_WAREHOUSE_SIZE 1000
#define MAX_NAME_LENGTH 50

// Define the struct for each item in the warehouse
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Define the struct for the warehouse itself
typedef struct {
    Item items[MAX_WAREHOUSE_SIZE];
    int itemCount;
} Warehouse;

// Function to create a new warehouse
Warehouse createWarehouse() {
    Warehouse newWarehouse;
    newWarehouse.itemCount = 0;
    return newWarehouse;
}

// Function to add an item to the warehouse
void addItem(Warehouse *warehouse, char name[], int quantity, float price) {
    // Create a new item
    Item newItem;
    strncpy(newItem.name, name, MAX_NAME_LENGTH);
    newItem.quantity = quantity;
    newItem.price = price;
    
    // Add the new item to the warehouse
    warehouse->items[warehouse->itemCount] = newItem;
    warehouse->itemCount++;
}

// Function to remove an item from the warehouse by index
void removeItem(Warehouse *warehouse, int index) {
    // Shift all the items after the removed item down one index
    for (int i = index; i < warehouse->itemCount - 1; i++) {
        warehouse->items[i] = warehouse->items[i+1];
    }
    // Decrease the item count
    warehouse->itemCount--;
}

// Function to update the quantity and price of an item by index
void updateItem(Warehouse *warehouse, int index, int newQuantity, float newPrice) {
    // Update the item
    warehouse->items[index].quantity = newQuantity;
    warehouse->items[index].price = newPrice;
}

// Function to get the total value of the warehouse inventory
float getTotalValue(Warehouse warehouse) {
    float total = 0.00;
    for (int i = 0; i < warehouse.itemCount; i++) {
        total += warehouse.items[i].quantity * warehouse.items[i].price;
    }
    return total;
}

// Function to print out all the items in the warehouse
void printWarehouse(Warehouse warehouse) {
    printf("Warehouse Inventory:\n");
    printf("-------------------------------------------\n");
    printf("| %-20s | %-8s | %-10s |\n", "Item Name", "Quantity", "Price");
    printf("-------------------------------------------\n");
    for (int i = 0; i < warehouse.itemCount; i++) {
        printf("| %-20s | %-8d | $%-9.2f |\n", warehouse.items[i].name, warehouse.items[i].quantity, warehouse.items[i].price);
    }
    printf("-------------------------------------------\n");
    printf("| %-20s | %-18.2f |\n", "Total Value", getTotalValue(warehouse));
    printf("-------------------------------------------\n");
}

int main() {
    // Create a new warehouse
    Warehouse warehouse = createWarehouse();
    
    // Add some items to the warehouse
    addItem(&warehouse, "Pencil", 500, 0.50);
    addItem(&warehouse, "Pen", 250, 1.00);
    addItem(&warehouse, "Notebook", 200, 2.00);
    
    // Print out the warehouse inventory
    printWarehouse(warehouse);
    
    // Update an item in the warehouse
    updateItem(&warehouse, 1, 300, 1.25);
    printf("\n");
    printWarehouse(warehouse);
    
    // Remove an item from the warehouse
    removeItem(&warehouse, 2);
    printf("\n");
    printWarehouse(warehouse);
    
    return 0;
}