//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ITEMS 1000

struct Item {
    int id;
    char name[50];
    int quantity;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct Warehouse* warehouse, struct Item item) {

    bool item_exists = false;

    // Check if item already exists in warehouse
    for (int i=0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == item.id) {
            warehouse->items[i].quantity += item.quantity;
            item_exists = true;
            break;
        }
    }

    // Add new item to warehouse if it doesn't already exist
    if (!item_exists) {
        warehouse->items[warehouse->num_items] = item;
        warehouse->num_items++;
    }

}

void remove_item(struct Warehouse* warehouse, int id, int quantity) {

    bool item_removed = false;

    // Remove quantity from existing item or remove completely if remaining quantity is 0
    for (int i=0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity -= quantity;
            if (warehouse->items[i].quantity <= 0) {
                for (int j=i; j < warehouse->num_items-1; j++) {
                    warehouse->items[j] = warehouse->items[j+1];
                }
                warehouse->num_items--;
            }
            item_removed = true;
            break;
        }
    }

    // Inform user if item wasn't found in warehouse
    if (!item_removed) {
        printf("Item with ID %d was not found in the warehouse.\n", id);
    }

}

void print_warehouse_contents(struct Warehouse* warehouse) {

    printf("Warehouse contents:\n");
    printf("ID\tName\t\t\tQuantity\n");
    printf("----------------------------------\n");

    for (int i=0; i < warehouse->num_items; i++) {
        printf("%d\t%d\t%s\t%d\n", i+1, warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {

    struct Warehouse warehouse = {.num_items = 0};

    // Add some items to the warehouse
    struct Item item1 = {.id = 1, .name = "Box of Nails", .quantity = 100};
    struct Item item2 = {.id = 2, .name = "Hammer", .quantity = 20};
    struct Item item3 = {.id = 3, .name = "Circular saw", .quantity = 4};
    add_item(&warehouse, item1);
    add_item(&warehouse, item2);
    add_item(&warehouse, item3);

    // Print current contents of warehouse
    print_warehouse_contents(&warehouse);

    // Remove some items from the warehouse
    remove_item(&warehouse, 2, 10);
    remove_item(&warehouse, 3, 2);

    // Print updated contents of warehouse
    print_warehouse_contents(&warehouse);

    return 0;
}