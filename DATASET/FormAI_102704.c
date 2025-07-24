//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum capacity of the warehouse
#define MAX_CAPACITY 1000

// Structure of the warehouse item
typedef struct {
    char name[20];
    int quantity;
} Item;

// Define the warehouse inventory
Item warehouse[MAX_CAPACITY];

// Define the current inventory count
int inventory_count = 0;

// Define the function to add a new item to the warehouse
void add_item(char item_name[], int item_quantity) {
    if (inventory_count < MAX_CAPACITY) {
        Item new_item;
        strcpy(new_item.name, item_name);
        new_item.quantity = item_quantity;
        warehouse[inventory_count] = new_item;
        inventory_count++;
        printf("Successfully added item %s with quantity %d to the warehouse.\n", item_name, item_quantity);
    } else {
        printf("Warehouse is full! Cannot add a new item.\n");
    }
}

// Define the function to remove an item from the warehouse
void remove_item(char item_name[]) {
    int removed = 0;
    for (int i = 0; i < inventory_count; i++) {
        if (strcmp(warehouse[i].name, item_name) == 0) {
            for (int j = i; j < inventory_count; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            inventory_count--;
            removed = 1;
            printf("Successfully removed item %s from the warehouse.\n", item_name);
            break;
        }
    }
    if (!removed) {
        printf("Item %s not found in the warehouse.\n", item_name);
    }
}

// Define the function to print the current warehouse inventory
void print_inventory() {
    printf("Current warehouse inventory:\n");
    for (int i = 0; i < inventory_count; i++) {
        printf("%d. %s (quantity: %d)\n", i + 1, warehouse[i].name, warehouse[i].quantity);
    }
}

// Define the main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Add some initial items to the warehouse
    add_item("Widget", rand() % 100);
    add_item("Thingamabob", rand() % 100);
    add_item("Doodad", rand() % 100);
    add_item("Whatchamacallit", rand() % 100);
    add_item("Gizmo", rand() % 100);

    // Print the initial warehouse inventory
    printf("Warehouse Management System\n");
    printf("===========================\n");
    print_inventory();

    // Remove an item from the warehouse
    remove_item("Doodad");

    // Add a new item to the warehouse
    add_item("Doohickey", rand() % 100);

    // Print the updated warehouse inventory
    printf("===========================\n");
    print_inventory();

    // Exit the program
    return 0;
}