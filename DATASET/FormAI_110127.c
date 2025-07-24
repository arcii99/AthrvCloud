//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 1000

// Define the data structure for each item in the warehouse
typedef struct {
    int item_id;
    char item_name[50];
    int quantity;
} Item;

// Define the data structure for the warehouse itself
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Warehouse;

// Function to add an item to the warehouse
void add_item(Warehouse *warehouse, Item item) {
    // Check if the warehouse is already full
    if (warehouse->num_items >= MAX_ITEMS) {
        printf("Error: warehouse is full\n");
        return;
    }
    
    // Add the item to the warehouse
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
    
    printf("Added item %d: %s (%d)\n", item.item_id, item.item_name, item.quantity);
}

// Function to remove an item from the warehouse
void remove_item(Warehouse *warehouse, int item_id) {
    int index = -1;
    
    // Find the item in the warehouse and get its index
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].item_id == item_id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: item not found\n");
        return;
    }
    
    // Remove the item from the warehouse
    printf("Removed item %d: %s (%d)\n", warehouse->items[index].item_id, warehouse->items[index].item_name, warehouse->items[index].quantity);
    for (int i = index; i < warehouse->num_items - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->num_items--;
}

int main() {
    Warehouse warehouse = {};
    
    // Add some sample items to the warehouse
    add_item(&warehouse, (Item) {1, "Screwdriver", 50});
    add_item(&warehouse, (Item) {2, "Hammer", 30});
    add_item(&warehouse, (Item) {3, "Wrench", 40});
    
    // Remove one of the items from the warehouse
    remove_item(&warehouse, 2);
    
    return 0;
}