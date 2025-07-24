//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_WAREHOUSE_SIZE 100 // Maximum number of products that the warehouse can store
#define MAX_PRODUCT_NAME_LENGTH 20 // Maximum length of a product name

// Define the structure of a product
typedef struct {
    int id;
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

// Define the structure of a warehouse
typedef struct {
    Product products[MAX_WAREHOUSE_SIZE];
    int num_products;
} Warehouse;

// Initialize a new warehouse
void init_warehouse(Warehouse *w) {
    w->num_products = 0;
}

// Add a new product to the warehouse
void add_product(Warehouse *w, Product p) {
    if (w->num_products == MAX_WAREHOUSE_SIZE) {
        printf("Warehouse is full!\n");
        return;
    }

    // Check if the product already exists in the warehouse
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (w->products[i].id == p.id) {
            printf("Product already exists in warehouse!\n");
            return;
        }
    }

    // Add the new product to the warehouse
    w->products[w->num_products] = p;
    w->num_products++;
}

// Remove a product from the warehouse
void remove_product(Warehouse *w, int product_id) {
    int i;

    // Find the index of the product to remove
    for (i = 0; i < w->num_products; i++) {
        if (w->products[i].id == product_id) {
            // Shift all the products after the removed one down by one index
            int j;
            for (j = i + 1; j < w->num_products; j++) {
                w->products[j-1] = w->products[j];
            }

            // Decrement the number of products in the warehouse
            w->num_products--;

            printf("Product removed from warehouse.\n");
            return;
        }
    }

    printf("Product with id %d not found in warehouse.\n", product_id);
}

// Print the list of products in the warehouse
void print_products(Warehouse *w) {
    int i;
    printf("List of products in warehouse:\n");
    for (i = 0; i < w->num_products; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", w->products[i].id, w->products[i].name, w->products[i].quantity);
    }
}

int main() {
    // Initialize a new warehouse
    Warehouse w;
    init_warehouse(&w);

    // Add some products to the warehouse
    Product p1 = {1, "Shoe", 20};
    add_product(&w, p1);

    Product p2 = {2, "Shirt", 30};
    add_product(&w, p2);

    Product p3 = {3, "Pants", 10};
    add_product(&w, p3);

    // Print the list of products in the warehouse
    print_products(&w);

    // Remove a product from the warehouse
    remove_product(&w, 2);

    // Print the list of products in the warehouse again
    print_products(&w);

    return 0;
}