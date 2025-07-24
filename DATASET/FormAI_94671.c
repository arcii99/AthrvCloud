//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a location name
#define MAX_LOC_LENGTH 10

// Define a struct for an item in the warehouse
typedef struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    char location[MAX_LOC_LENGTH];
} Item;

// Define a struct for the warehouse itself
typedef struct warehouse {
    Item items[MAX_ITEMS];
    int num_items;
} Warehouse;

// Function to add a new item to the warehouse
void add_item(Warehouse *w, char *name, int quantity, char *location) {
    // Make sure the name is not too long
    if (strlen(name) >= MAX_NAME_LENGTH) {
        printf("Error: Item name too long!\n");
        return;
    }

    // Make sure the location name is not too long
    if (strlen(location) >= MAX_LOC_LENGTH) {
        printf("Error: Location name too long!\n");
        return;
    }

    // Make sure there is room in the warehouse
    if (w->num_items >= MAX_ITEMS) {
        printf("Error: Warehouse is full!\n");
        return;
    }

    // Create the new item and add it to the warehouse
    Item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    strcpy(new_item.location, location);

    w->items[w->num_items++] = new_item;
}

// Function to remove an item from the warehouse
void remove_item(Warehouse *w, char *name) {
    int i;

    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            // Found the item, remove it
            w->items[i] = w->items[w->num_items - 1];
            w->num_items--;
            printf("Item %s removed successfully!\n", name);
            return;
        }
    }

    // Item was not found
    printf("Error: Item %s not found in warehouse!\n", name);
}

// Function to display the contents of the warehouse
void display_contents(Warehouse *w) {
    int i;

    printf("Warehouse contents:\n");
    printf("====================\n");

    for (i = 0; i < w->num_items; i++) {
        printf("%s (%d): %s\n", w->items[i].name, w->items[i].quantity, w->items[i].location);
    }
}

// Main function for the program
int main() {
    Warehouse warehouse;
    warehouse.num_items = 0;

    // Add some items to the warehouse
    add_item(&warehouse, "Apples", 10, "A1");
    add_item(&warehouse, "Bananas", 5, "A2");
    add_item(&warehouse, "Oranges", 15, "B1");

    // Display the contents of the warehouse
    display_contents(&warehouse);

    // Remove an item from the warehouse
    remove_item(&warehouse, "Apples");

    // Display the contents of the warehouse again
    display_contents(&warehouse);

    return 0;
}