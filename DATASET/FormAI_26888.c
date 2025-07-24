//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for products
typedef struct Product {
    int id;
    char name[50];
    int quantity;
} Product;

// Define structure for warehouses
typedef struct Warehouse {
    int id;
    char location[50];
    int capacity;
    Product products[50];
    int num_products;
} Warehouse;

// Function to add a product to the warehouse
void add_product_to_warehouse(Warehouse *warehouse, Product product) {
    if (warehouse->num_products >= 50) {
        printf("Warehouse is full, cannot add product!\n");
        return;
    }

    warehouse->products[warehouse->num_products] = product;
    warehouse->num_products++;
}

// Function to remove a product from the warehouse
void remove_product_from_warehouse(Warehouse *warehouse, int product_id) {
    int found = 0;
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == product_id) {
            found = 1;
            for (int j = i; j < warehouse->num_products - 1; j++) {
                warehouse->products[j] = warehouse->products[j+1];
            }
            warehouse->num_products--;
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found in warehouse!\n", product_id);
    }
}

// Function to display all products in a warehouse
void display_all_products_in_warehouse(Warehouse warehouse) {
    printf("Products in warehouse %s:\n", warehouse.location);
    for (int i = 0; i < warehouse.num_products; i++) {
        printf("%d - %s - Quantity: %d\n", warehouse.products[i].id, warehouse.products[i].name, warehouse.products[i].quantity);
    }
}

// Main function
int main() {
    // Create three warehouses
    Warehouse warehouse1 = {1, "New York", 50, {}, 0};
    Warehouse warehouse2 = {2, "Los Angeles", 50, {}, 0};
    Warehouse warehouse3 = {3, "Chicago", 50, {}, 0};

    // Create some products
    Product product1 = {1, "Apples", 100};
    Product product2 = {2, "Oranges", 75};
    Product product3 = {3, "Bananas", 50};

    // Add products to warehouses
    add_product_to_warehouse(&warehouse1, product1);
    add_product_to_warehouse(&warehouse1, product2);
    add_product_to_warehouse(&warehouse2, product2);
    add_product_to_warehouse(&warehouse3, product3);

    // Display products in each warehouse
    display_all_products_in_warehouse(warehouse1);
    display_all_products_in_warehouse(warehouse2);
    display_all_products_in_warehouse(warehouse3);

    // Remove a product from warehouse 1
    remove_product_from_warehouse(&warehouse1, 1);

    // Display products in warehouse 1 again
    display_all_products_in_warehouse(warehouse1);

    return 0;
}