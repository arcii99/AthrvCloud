//FormAI DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000      // Maximum number of products
#define PRODUCT_NAME_LEN 50    // Maximum length of product name
#define PRODUCT_CODE_LEN 20    // Maximum length of product code

// Structure for each product
typedef struct {
    char name[PRODUCT_NAME_LEN];
    char code[PRODUCT_CODE_LEN];
    double price;
    int quantity;
} Product;

// Global array to hold the products
Product products[MAX_PRODUCTS];

// Function to add a new product
void addProduct() {
    // Ensure there is space to add a new product
    int numProducts = sizeof(products) / sizeof(products[0]);
    if (numProducts >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    // Get information for the new product from the user
    Product newProduct;
    printf("Enter product name: ");
    fgets(newProduct.name, PRODUCT_NAME_LEN, stdin);
    printf("Enter product code: ");
    fgets(newProduct.code, PRODUCT_CODE_LEN, stdin);
    printf("Enter product price: ");
    scanf("%lf", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    // Add the new product to the array
    products[numProducts] = newProduct;
    printf("Product added successfully.\n");
}

// Function to display all products
void displayProducts() {
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Code", "Price", "Quantity");
    printf("---------------------------------------------------------------\n");
    int numProducts = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < numProducts; i++) {
        Product currentProduct = products[i];
        printf("%-20s %-20s $%-9.2lf %-10d\n",
              currentProduct.name, currentProduct.code,
              currentProduct.price, currentProduct.quantity);
    }
}

// Function to find a product by code and return its index in the array
int findProductIndex(char* code) {
    int numProducts = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].code, code) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to update a product's information
void updateProduct() {
    // Get the product code from the user
    char code[PRODUCT_CODE_LEN];
    printf("Enter product code to update: ");
    fgets(code, PRODUCT_CODE_LEN, stdin);

    // Find the product with the matching code
    int index = findProductIndex(code);
    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    // Get the updated information for the product from the user
    Product updatedProduct = products[index];
    printf("Enter product name (press enter to keep current name): ");
    fgets(updatedProduct.name, PRODUCT_NAME_LEN, stdin);
    printf("Enter product code (press enter to keep current code): ");
    fgets(updatedProduct.code, PRODUCT_CODE_LEN, stdin);
    printf("Enter product price (press enter to keep current price): ");
    char priceStr[10];
    fgets(priceStr, 10, stdin);
    if (priceStr[0] != '\n') {
        updatedProduct.price = atof(priceStr);
    }
    printf("Enter product quantity (press enter to keep current quantity): ");
    char quantityStr[10];
    fgets(quantityStr, 10, stdin);
    if (quantityStr[0] != '\n') {
        updatedProduct.quantity = atoi(quantityStr);
    }

    // Update the product in the array
    products[index] = updatedProduct;
    printf("Product updated successfully.\n");
}

// Function to remove a product
void removeProduct() {
    // Get the product code from the user
    char code[PRODUCT_CODE_LEN];
    printf("Enter product code to remove: ");
    fgets(code, PRODUCT_CODE_LEN, stdin);

    // Find the product with the matching code
    int index = findProductIndex(code);
    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    // Remove the product by shifting all elements after it to the left
    int numProducts = sizeof(products) / sizeof(products[0]);
    for (int i = index; i < numProducts - 1; i++) {
        products[i] = products[i + 1];
    }
    printf("Product removed successfully.\n");
}

// Main function
int main() {
    while (1) {
        // Display menu and get user choice
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Update product\n");
        printf("4. Remove product\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");
        char choiceStr[2];
        fgets(choiceStr, 2, stdin);

        // Execute selected option
        switch (choiceStr[0]) {
            case '1':
                addProduct();
                break;
            case '2':
                displayProducts();
                break;
            case '3':
                updateProduct();
                break;
            case '4':
                removeProduct();
                break;
            case '5':
                return 0;
            default:
                printf("Error: Invalid choice.\n");
        }
    }
}