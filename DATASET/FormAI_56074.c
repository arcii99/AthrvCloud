//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// define the structure for an item stored in the warehouse
typedef struct {
    char name[50];
    int quantity;
    float weight;
} Item;

// define the structure for a warehouse
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Warehouse;

// function to add an item to the warehouse
void add_item(Warehouse* wh, char* name, int quantity, float weight) {
    // check if the warehouse is full
    if (wh->num_items >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }

    // create a new item and add it to the warehouse
    Item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.weight = weight;

    wh->items[wh->num_items] = new_item;
    wh->num_items++;

    printf("Item added to warehouse successfully!\n");
}

// function to remove an item from the warehouse
void remove_item(Warehouse* wh, char* name) {
    // iterate over each item in the warehouse and remove the item with the matching name
    for (int i = 0; i < wh->num_items; i++) {
        if (strcmp(wh->items[i].name, name) == 0) {
            // move all the items after this item up one index to fill the gap
            for (int j = i+1; j < wh->num_items; j++) {
                wh->items[j-1] = wh->items[j];
            }

            // update the number of items in the warehouse
            wh->num_items--;

            printf("Item removed from warehouse successfully!\n");
            return;
        }
    }

    printf("Item not found in warehouse!\n");
}

// function to print out all the items in the warehouse
void print_inventory(Warehouse* wh) {
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < wh->num_items; i++) {
        printf("%s (Quantity: %d, Weight: %.2f)\n", wh->items[i].name, wh->items[i].quantity, wh->items[i].weight);
    }
}

int main() {
    // create a new warehouse
    Warehouse warehouse;
    warehouse.num_items = 0;

    // add some initial items to the warehouse
    add_item(&warehouse, "Box of screws", 100, 2.5);
    add_item(&warehouse, "Hammer", 50, 5.0);

    // print out the current inventory
    print_inventory(&warehouse);

    // remove an item from the warehouse
    remove_item(&warehouse, "Box of screws");

    // print out the updated inventory
    print_inventory(&warehouse);

    return 0;
}