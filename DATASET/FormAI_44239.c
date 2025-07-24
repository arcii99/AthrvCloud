//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    int item_id;
    char item_name[50];
    int quantity;
    float price;
} item;

int total_items = 0;
item items[100];

// Function to add an item to the warehouse
void add_item(int item_id, char item_name[], int quantity, float price)
{
    items[total_items].item_id = item_id;
    strcpy(items[total_items].item_name, item_name);
    items[total_items].quantity = quantity;
    items[total_items].price = price;

    printf("New item added to warehouse:\n");
    printf("Item ID: %d\n", items[total_items].item_id);
    printf("Item Name: %s\n", items[total_items].item_name);
    printf("Item Quantity: %d\n", items[total_items].quantity);
    printf("Item Price: $%.2f\n", items[total_items].price);

    total_items++;
}

// Function to remove an item from the warehouse
void remove_item(int item_id)
{
    bool item_found = false;
    int i;

    for (i = 0; i < total_items; i++) {
        if (items[i].item_id == item_id) {
            item_found = true;
            break;
        }
    }

    if (item_found) {
        printf("Item removed from warehouse:\n");
        printf("Item ID: %d\n", items[i].item_id);
        printf("Item Name: %s\n", items[i].item_name);
        printf("Item Quantity: %d\n", items[i].quantity);
        printf("Item Price: $%.2f\n", items[i].price);

        // Shift items to left after removing
        for (int j = i; j < total_items - 1; j++) {
            items[j] = items[j + 1];
        }

        total_items--;
    } else {
        printf("Item not found in warehouse.\n");
    }
}

// Function to display all items in the warehouse
void display_items()
{
    printf("Items in warehouse:\n");

    for (int i = 0; i < total_items; i++) {
        printf("------------------\n");
        printf("Item ID: %d\n", items[i].item_id);
        printf("Item Name: %s\n", items[i].item_name);
        printf("Item Quantity: %d\n", items[i].quantity);
        printf("Item Price: $%.2f\n", items[i].price);
    }

    printf("------------------\n");
}

int main()
{
    // Add some initial items to the warehouse
    add_item(100, "Shoes", 50, 29.99);
    add_item(101, "Jeans", 30, 39.99);
    add_item(102, "Shirts", 20, 19.99);

    // Display all items in the warehouse
    display_items();

    // Remove an item from the warehouse
    remove_item(101);

    // Display all items in the warehouse again to confirm the item was removed
    display_items();

    return 0;
}