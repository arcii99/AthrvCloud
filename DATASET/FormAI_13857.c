//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ITEMS 1000

// Struct for each item in the warehouse
typedef struct Item {
    char name[100];
    int quantity;
    float price;
} Item;

// Warehouse array
Item warehouse[MAX_ITEMS];

// Current number of items in the warehouse
int num_items = 0;

// Function to add an item to the warehouse
void add_item(char* name, int quantity, float price) {
    Item item;
    strcpy(item.name, name);
    item.quantity = quantity;
    item.price = price;
    warehouse[num_items] = item;
    num_items++;
}

// Function to remove an item from the warehouse
void remove_item(char* name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            for (int j = i; j < num_items-1; j++) {
                warehouse[j] = warehouse[j+1];
            }
            num_items--;
            printf("Item '%s' removed from warehouse.\n", name);
            return;
        }
    }
    printf("Item '%s' not found in warehouse.\n", name);
}

// Function to print all items in the warehouse
void print_items() {
    printf("Items in warehouse:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %d - $%.2f\n", i+1, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

// Function to search for an item in the warehouse
void search_item(char* name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            printf("%s - Quantity: %d - Price: $%.2f\n", warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
            return;
        }
    }
    printf("Item '%s' not found in warehouse.\n", name);
}

int main() {
    // Add some items to the warehouse
    add_item("Apple", 50, 0.50);
    add_item("Banana", 25, 0.25);
    add_item("Orange", 100, 0.75);

    // Print all items in the warehouse
    print_items();

    // Search for an item
    search_item("Apple");

    // Remove an item
    remove_item("Banana");

    // Print all items in the warehouse again
    print_items();

    return 0;
}