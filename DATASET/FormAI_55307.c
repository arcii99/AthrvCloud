//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct for items in the warehouse
typedef struct {
    char item_name[50];
    int quantity;
    float price;
} WarehouseItem;

// Define a struct for the warehouse itself
typedef struct {
    char warehouse_name[50];
    WarehouseItem items[100];
} Warehouse;

// Define functions for adding, updating, and deleting items from the warehouse
void add_item(Warehouse *warehouse, char name[], int quantity, float price) {
    WarehouseItem new_item;
    strcpy(new_item.item_name, name);
    new_item.quantity = quantity;
    new_item.price = price;
    for (int i = 0; i < 100; i++) {
        if (warehouse->items[i].quantity == 0) {
            warehouse->items[i] = new_item;
            printf("Item successfully added!\n");
            return;
        }
    }
    printf("Error: Warehouse is full!\n");
}

void update_item(Warehouse *warehouse, char name[], int quantity, float price) {
    for (int i = 0; i < 100; i++) {
        if (strcmp(warehouse->items[i].item_name, name) == 0) {
            warehouse->items[i].quantity = quantity;
            warehouse->items[i].price = price;
            printf("Item successfully updated!\n");
            return;
        }
    }
    printf("Error: Item not found in warehouse!\n");
}

void delete_item(Warehouse *warehouse, char name[]) {
    for (int i = 0; i < 100; i++) {
        if (strcmp(warehouse->items[i].item_name, name) == 0) {
            warehouse->items[i].quantity = 0;
            printf("Item successfully deleted!\n");
            return;
        }
    }
    printf("Error: Item not found in warehouse!\n");
}

// Define a function to display the warehouse's contents
void display_warehouse(Warehouse *warehouse) {
    printf("Warehouse name: %s\n", warehouse->warehouse_name);
    for (int i = 0; i < 100; i++) {
        if (warehouse->items[i].quantity != 0) {
            printf("Item: %s | Quantity: %d | Price: $%.2f\n", warehouse->items[i].item_name,
                   warehouse->items[i].quantity, warehouse->items[i].price);
        }
    }
}

// Define the main function to run the program
int main() {
    // Create a new warehouse
    Warehouse warehouse;
    strcpy(warehouse.warehouse_name, "Main Warehouse");
    
    // Set all items to have a quantity of 0 to start
    for (int i = 0; i < 100; i++) {
        warehouse.items[i].quantity = 0;
    }
    
    // Display the initial state of the warehouse
    display_warehouse(&warehouse);
    
    // Add some items to the warehouse
    add_item(&warehouse, "Widget A", 50, 10.99);
    add_item(&warehouse, "Widget B", 100, 5.99);
    add_item(&warehouse, "Widget C", 25, 50.00);
    
    // Display the warehouse again to see the new items
    display_warehouse(&warehouse);
    
    // Update the price of Widget A and the quantity of Widget C
    update_item(&warehouse, "Widget A", 50, 15.99);
    update_item(&warehouse, "Widget C", 40, 50.00);
    
    // Display the warehouse again to see the updates
    display_warehouse(&warehouse);
    
    // Delete Widget B from the warehouse
    delete_item(&warehouse, "Widget B");
    
    // Display the final state of the warehouse
    display_warehouse(&warehouse);
    
    return 0;
}