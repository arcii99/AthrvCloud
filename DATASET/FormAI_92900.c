//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define maximum number of products in the warehouse
#define MAX_PRODUCTS 100

// Define product structure
typedef struct {
    int id;
    char name[50];
    int quantity;
} Product;

// Define global variables
Product products[MAX_PRODUCTS];
int numProducts = 0;

// Function to add a new product to the warehouse
void addProduct(int id, char name[], int quantity) {
    // Check if the product already exists
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            // Product already exists, update quantity
            products[i].quantity += quantity;
            return;
        }
    }

    // Product doesn't exist, create a new one
    Product newProduct;
    newProduct.id = id;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;

    // Add the new product to the warehouse
    products[numProducts] = newProduct;
    numProducts++;
}

// Function to remove a product from the warehouse
void removeProduct(int id, int quantity) {
    // Find the product with matching id
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            // Check if there's enough quantity
            if (products[i].quantity >= quantity) {
                products[i].quantity -= quantity;
                return;
            } else {
                printf("Not enough quantity for product %d\n", id);
                return;
            }
        }
    }

    // Product not found
    printf("Product %d not found\n", id);
}

// Function to display the available products in the warehouse
void displayProducts() {
    printf("ID\tName\tQuantity\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\n", products[i].id, products[i].name, products[i].quantity);
    }
}

// Main function to run the program
int main() {
    // Add some initial products to the warehouse
    addProduct(1, "Shampoo", 50);
    addProduct(2, "Soap", 100);
    addProduct(3, "Toothpaste", 75);

    // Display the initial products
    displayProducts();

    // Remove some quantity from product 1
    removeProduct(1, 25);

    // Display the updated products
    displayProducts();

    // Add a new product
    addProduct(4, "Conditioner", 30);

    // Display the updated products
    displayProducts();

    return 0;
}