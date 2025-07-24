//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 1000
#define MAX_LOCATIONS 10
#define MAX_ORDERS 100

typedef struct {
    int item_id;
    int quantity;
} Item;

typedef struct {
    int order_id;
    Item items[MAX_ITEMS];
    int status; // 0 = pending, 1 = packed, 2 = shipped
} Order;

typedef struct {
    int location_id;
    Item items[MAX_ITEMS];
} Location;

typedef struct {
    Order orders[MAX_ORDERS];
    Location locations[MAX_LOCATIONS];
    int num_orders;
    int num_locations;
} Warehouse;

// Function to randomly generate items and locations
void randomly_generate_items(Item items[]) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].item_id = i + 1;
        items[i].quantity = rand() % 1000;
    }
}

void randomly_generate_locations(Location locations[]) {
    for (int i = 0; i < MAX_LOCATIONS; i++) {
        locations[i].location_id = i + 1;
        randomly_generate_items(locations[i].items);
    }
}

void add_order(Warehouse *warehouse) {
    // Generate randomly 5 items and quantities between [1-10]
    Item items[5];
    for (int i = 0; i < 5; i++) {
        items[i].item_id = rand() % 1000 + 1;
        items[i].quantity = rand() % 10 + 1;
    }
    // Find a location with enough stock to fulfill the order
    int location_index;
    for (int i = 0; i < MAX_LOCATIONS; i++) {
        int found_location = 1;
        for (int j = 0; j < 5; j++) {
            Item *item = &warehouse->locations[i].items[items[j].item_id - 1];
            if (item->quantity < items[j].quantity) {
                found_location = 0;
                break;
            }
        }
        if (found_location) {
            location_index = i;
            break;
        }
    }
    // If no location found, add the order to pending_orders
    if (location_index == 0) {
        warehouse->orders[warehouse->num_orders].order_id = warehouse->num_orders + 1;
        for (int i = 0; i < 5; i++) {
            warehouse->orders[warehouse->num_orders].items[i] = items[i];
        }
        warehouse->orders[warehouse->num_orders].status = 0;
        warehouse->num_orders++;
        printf("Order added to pending\n");
    } else {
        // Remove the stock from the location
        for (int i = 0; i < 5; i++) {
            Item *item = &warehouse->locations[location_index].items[items[i].item_id - 1];
            item->quantity -= items[i].quantity;
        }
        // Add the order to the location
        warehouse->orders[warehouse->num_orders].order_id = warehouse->num_orders + 1;
        for (int i = 0; i < 5; i++) {
            warehouse->locations[location_index].items[items[i].item_id - 1].quantity += items[i].quantity;
            warehouse->orders[warehouse->num_orders].items[i] = items[i];
        }
        warehouse->orders[warehouse->num_orders].status = 1;
        warehouse->num_orders++;
        printf("Order fulfilled\n");
    }
}

// Function to print the status of all orders
void print_orders(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_orders; i++) {
        printf("Order ID: %d\n", warehouse->orders[i].order_id);
        printf("Status: %d\n", warehouse->orders[i].status);
        printf("Items:\n");
        for (int j = 0; j < 5; j++) {
            Item item = warehouse->orders[i].items[j];
            printf("Item ID: %d, Quantity: %d\n", item.item_id, item.quantity);
        }
    }
}

int main() {
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the Surrealist Warehouse Management System!\n");
    printf("Generating items and locations...\n");
    
    Warehouse warehouse;
    warehouse.num_orders = 0;
    warehouse.num_locations = MAX_LOCATIONS;
    randomly_generate_locations(warehouse.locations);
    
    printf("Items and locations generated. Let's start fulfilling orders!\n");
    
    while (1) {
        printf("Enter 1 to add an order, 2 to print the status of all orders, or -1 to exit:\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_order(&warehouse);
                break;
            case 2:
                print_orders(&warehouse);
                break;
            case -1:
                printf("Goodbye!\n");
                return 0;
        }
    }
    
    return 0;
}