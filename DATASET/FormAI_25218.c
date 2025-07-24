//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure for products */
struct Product {
    char name[20];
    int quantity;
    float price;
};

/* Define structure for warehouse */
struct Warehouse {
    char location[20];
    int capacity;
    int products_count;
    struct Product products[100];
};

/* Function to add a product to the warehouse */
void add_product(struct Warehouse *warehouse, struct Product product) {
    if (warehouse->products_count < warehouse->capacity) {
        warehouse->products[warehouse->products_count++] = product;
        printf("Product added to warehouse.\n");
    } else {
        printf("Warehouse is full. Unable to add product.\n");
    }
}

/* Function to remove a product from the warehouse by product name */
void remove_product(struct Warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->products_count; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            int j;
            for (j = i; j < warehouse->products_count - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->products_count--;
            printf("Product removed from warehouse.\n");
            return;
        }
    }
    printf("Product not found in warehouse.\n");
}

/* Function to display all products in the warehouse */
void display_products(struct Warehouse *warehouse) {
    int i;
    printf("Warehouse at %s\n", warehouse->location);
    printf("Capacity: %d\n", warehouse->capacity);
    printf("Product Count: %d\n", warehouse->products_count);
    for (i = 0; i < warehouse->products_count; i++) {
        printf("%s\t%d\t%.2f\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

int main() {
    /* Create a warehouse */
    struct Warehouse warehouse = {"New York", 100, 0};

    /* Add some products */
    add_product(&warehouse, (struct Product){"Pencil", 50, 0.50});
    add_product(&warehouse, (struct Product){"Eraser", 25, 0.25});

    /* Display products */
    display_products(&warehouse);

    /* Remove a product */
    remove_product(&warehouse, "Pencil");

    /* Display products again */
    display_products(&warehouse);

    return 0;
}