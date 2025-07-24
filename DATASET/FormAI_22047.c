//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100 // maximum number of items in warehouse

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Warehouse {
    char name[50];
    struct Item items[MAX_ITEMS];
    int num_items;
};

// Function to add an item to the warehouse
void add_item(struct Warehouse *warehouse, char *item_name, int item_quantity, float item_price) {
    // Create a new item and add it to the warehouse
    struct Item new_item;
    strcpy(new_item.name, item_name);
    new_item.quantity = item_quantity;
    new_item.price = item_price;

    // Add the item to the warehouse
    warehouse->items[warehouse->num_items] = new_item;
    warehouse->num_items++;
}

// Function to remove an item from the warehouse
void remove_item(struct Warehouse *warehouse, char *item_name) {
    // Find the item in the warehouse and remove it
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, item_name) == 0) {
            // Remove the item by shifting all subsequent items to the left
            int j;
            for (j = i; j < warehouse->num_items - 1; j++) {
                warehouse->items[j] = warehouse->items[j+1];
            }
            warehouse->num_items--;
            printf("Item '%s' removed from warehouse '%s'\n", item_name, warehouse->name);
            return;
        }
    }
    printf("Item '%s' not found in warehouse '%s'\n", item_name, warehouse->name);
}

// Function to list all items in the warehouse
void list_items(struct Warehouse *warehouse) {
    printf("List of items in warehouse '%s':\n", warehouse->name);
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        printf("%s (Quantity: %d, Price: $%.2f)\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    // Create two example warehouses
    struct Warehouse warehouse1;
    strcpy(warehouse1.name, "Warehouse A");
    warehouse1.num_items = 0;

    struct Warehouse warehouse2;
    strcpy(warehouse2.name, "Warehouse B");
    warehouse2.num_items = 0;

    // Add some items to the warehouses
    add_item(&warehouse1, "Item 1", 10, 2.50);
    add_item(&warehouse1, "Item 2", 5, 7.00);
    add_item(&warehouse2, "Item 3", 20, 1.25);
    add_item(&warehouse2, "Item 4", 15, 5.50);

    // List the items in the warehouses
    list_items(&warehouse1);
    list_items(&warehouse2);

    // Remove an item from a warehouse
    remove_item(&warehouse1, "Item 2");

    // List the items in the warehouses again
    list_items(&warehouse1);
    list_items(&warehouse2);

    return 0;
}