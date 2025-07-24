//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_PRODUCT_NAME 50

// Structure to store the product information.
typedef struct {
    int id;
    char name[MAX_PRODUCT_NAME];
    int quantity;
} Product;

// Global array of products.
Product products[MAX_PRODUCTS];

// Global variable to keep track of the number of products stored.
int numProducts = 0;

// Function to add a new product to the warehouse.
void addProduct(int id, char* name, int quantity) {
    Product product = { id, "", quantity };
    strncpy(product.name, name, MAX_PRODUCT_NAME-1);
    products[numProducts++] = product;
}

// Function to display the list of products stored in the warehouse.
void displayProducts() {
    printf("Product ID\tProduct Name\tQuantity\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t\t%s\t\t%d\n", products[i].id, products[i].name, products[i].quantity);
    }
}

int main() {
    printf("Welcome to the Warehouse Management System!\n\n");

    // Add some initial products to the warehouse.
    addProduct(1, "Product A", 10);
    addProduct(2, "Product B", 20);
    addProduct(3, "Product C", 30);
    addProduct(4, "Product D", 40);

    // Display the list of products.
    displayProducts();

    return 0;
}