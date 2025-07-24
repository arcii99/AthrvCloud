//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Item structure
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Item;

// Warehouse structure
typedef struct {
    Item items[100];
} Warehouse;

// Function to add items to the warehouse
void addItem(Warehouse* warehouse, int id, char name[], float price, int quantity) {
    int index = -1;
    for (int i = 0; i < 100; i++) {
        if (warehouse->items[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        warehouse->items[index].quantity += quantity;
    } else {
        for (int i = 0; i < 100; i++) {
            if (warehouse->items[i].id == 0) {
                warehouse->items[i].id = id;
                strcpy(warehouse->items[i].name, name);
                warehouse->items[i].price = price;
                warehouse->items[i].quantity = quantity;
                break;
            }
        }
    }
}

// Function to remove items from the warehouse
void removeItem(Warehouse* warehouse, int id, int quantity) {
    for (int i = 0; i < 100; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity -= quantity;

            if (warehouse->items[i].quantity <= 0) {
                warehouse->items[i].id = 0;
                warehouse->items[i].name[0] = '\0';
                warehouse->items[i].price = 0;
                warehouse->items[i].quantity = 0;
            }

            break;
        }
    }
}

// Function to print all items in the warehouse
void listItems(Warehouse warehouse) {
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < 100; i++) {
        if (warehouse.items[i].id != 0) {
            printf("%d\t%s\t%.2f\t%d\n", warehouse.items[i].id, warehouse.items[i].name, warehouse.items[i].price, warehouse.items[i].quantity);
        }
    }
}

// Main function
int main() {
    // Create a warehouse
    Warehouse warehouse = {0};

    // Add some items to the warehouse
    addItem(&warehouse, 1, "Apple", 0.50, 10);
    addItem(&warehouse, 2, "Banana", 0.30, 20);
    addItem(&warehouse, 3, "Orange", 0.40, 15);
    addItem(&warehouse, 4, "Pear", 0.60, 5);

    // Print all items in the warehouse
    listItems(warehouse);

    // Remove some items from the warehouse
    removeItem(&warehouse, 2, 5);
    removeItem(&warehouse, 4, 2);

    // Print all items in the warehouse
    listItems(warehouse);

    return 0;
}