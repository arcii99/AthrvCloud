//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
struct warehouse_item {
    char name[50];
    int quantity;
    float price;
};

// Define the structure of the warehouse
struct warehouse {
    struct warehouse_item items[MAX_ITEMS];
    int num_items;
    float total_value;
};

// Function to add an item to the warehouse
void add_item(struct warehouse *w, char *name, int quantity, float price) {
    // Check if the warehouse is full
    if (w->num_items == MAX_ITEMS) {
        printf("The warehouse is full!\n");
        return;
    }
    
    // Create a new item and add it to the warehouse
    struct warehouse_item item;
    strcpy(item.name, name);
    item.quantity = quantity;
    item.price = price;
    w->items[w->num_items] = item;
    w->num_items++;
    
    // Update the total value of the warehouse
    w->total_value += quantity * price;
    
    // Print a message to confirm the addition
    printf("Added %d %ss at %0.2f each.\n", quantity, item.name, item.price);
}

// Function to remove an item from the warehouse
void remove_item(struct warehouse *w, char *name, int quantity) {
    // Find the item in the warehouse and remove the specified quantity
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            // Check if there is enough of the item to remove
            if (w->items[i].quantity < quantity) {
                printf("There is not enough %s in the warehouse!\n", name);
                return;
            }
            
            // Remove the quantity and update the total value of the warehouse
            w->items[i].quantity -= quantity;
            w->total_value -= quantity * w->items[i].price;
            
            // Print a message to confirm the removal
            printf("Removed %d %ss.\n", quantity, name);
            
            // Check if the item needs to be completely removed from the warehouse
            if (w->items[i].quantity == 0) {
                // Shift the remaining items to fill the gap in the array
                for (int j = i; j < w->num_items - 1; j++) {
                    w->items[j] = w->items[j+1];
                }
                w->num_items--;
            }
            
            return;
        }
    }
    
    // Print a message if the item was not found in the warehouse
    printf("%s not found in the warehouse!\n", name);
}

// Function to list all items in the warehouse
void list_items(struct warehouse *w) {
    // Print a header for the listing
    printf("Item Name\tQuantity\tPrice\n");
    
    // Loop through the items in the warehouse and print their details
    for (int i = 0; i < w->num_items; i++) {
        printf("%s\t\t%d\t\t%0.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
    
    // Print the total value of the warehouse
    printf("Total Value: %0.2f\n", w->total_value);
}

int main() {
    // Initialize the warehouse
    struct warehouse w;
    w.num_items = 0;
    w.total_value = 0.0;
    
    // Add some items to the warehouse
    add_item(&w, "Swords", 10, 25.0);
    add_item(&w, "Shields", 20, 20.0);
    add_item(&w, "Bows", 5, 30.0);
    
    // Remove some items from the warehouse
    remove_item(&w, "Swords", 3);
    remove_item(&w, "Arrows", 10);
    
    // List all items in the warehouse
    list_items(&w);
    
    return 0;
}