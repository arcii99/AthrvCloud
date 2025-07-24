//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // maximum number of products the warehouse can store
#define MAX_NAME_LENGTH 20 // maximum length of a product name
#define MAX_CAPACITY 1000 // maximum capacity of the warehouse

struct Product {
    char name[MAX_NAME_LENGTH];
    int quantity;
};

struct Warehouse {
    struct Product products[MAX_PRODUCTS];
    int capacity;
    int occupancy;
};

int main() {
    struct Warehouse warehouse;
    warehouse.capacity = MAX_CAPACITY;
    warehouse.occupancy = 0;

    // adding products
    struct Product p1 = {"Pens", 50};
    struct Product p2 = {"Pencils", 100};
    struct Product p3 = {"Notebooks", 20};

    warehouse.products[0] = p1;
    warehouse.occupancy++;
    warehouse.products[1] = p2;
    warehouse.occupancy++;
    warehouse.products[2] = p3;
    warehouse.occupancy++;

    // displaying warehouse status
    printf("Warehouse Status:\n");
    printf("Capacity: %d\nOccupancy: %d\n\n", warehouse.capacity, warehouse.occupancy);

    // displaying product list
    printf("Product List:\n");
    for (int i = 0; i < warehouse.occupancy; i++) {
        printf("%d. %s - %d\n", i+1, warehouse.products[i].name, warehouse.products[i].quantity);
    }

    return 0;
}