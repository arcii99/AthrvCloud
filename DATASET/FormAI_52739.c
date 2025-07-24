//FormAI DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 1000

// Define a struct to represent a product
struct Product {
    char name[50];
    float price;
    int quantity;
};

// Define a global array to store all products
struct Product products[MAX_PRODUCTS];

// Define a function to add a new product
void add_product(char name[], float price, int quantity) {
    // Find the index of the first empty slot in the products array
    int index = 0;
    while (products[index].name[0] != '\0') {
        index++;
        if (index == MAX_PRODUCTS) {
            printf("Error: Maximum number of products reached\n");
            return;
        }
    }
    // Add the new product to the products array
    strcpy(products[index].name, name);
    products[index].price = price;
    products[index].quantity = quantity;
    // Print a success message
    printf("Product added: %s, $%.2f, %d in stock\n", name, price, quantity);
}

// Define a function to remove a product
void remove_product(char name[]) {
    // Find the index of the product in the products array
    int index = -1;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: Product not found\n");
        return;
    }
    // Remove the product from the products array
    products[index].name[0] = '\0';
    products[index].price = 0.0;
    products[index].quantity = 0;
    // Print a success message
    printf("Product removed: %s\n", name);
}

// Define a function to update the price of a product
void update_price(char name[], float new_price) {
    // Find the index of the product in the products array
    int index = -1;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: Product not found\n");
        return;
    }
    // Update the price of the product
    products[index].price = new_price;
    // Print a success message
    printf("Price updated: %s, $%.2f\n", name, new_price);
}

// Define a function to update the quantity of a product
void update_quantity(char name[], int new_quantity) {
    // Find the index of the product in the products array
    int index = -1;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: Product not found\n");
        return;
    }
    // Update the quantity of the product
    products[index].quantity = new_quantity;
    // Print a success message
    printf("Quantity updated: %s, %d in stock\n", name, new_quantity);
}

// Define a function to print all products
void print_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].name[0] != '\0') {
            printf("%s: $%.2f, %d in stock\n", products[i].name, products[i].price, products[i].quantity);
        }
    }
}

int main() {
    // Initialize the products array
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i].name[0] = '\0';
        products[i].price = 0.0;
        products[i].quantity = 0;
    }
    // Add some initial products
    add_product("Apple", 0.50, 10);
    add_product("Banana", 0.25, 20);
    add_product("Orange", 0.75, 15);
    // Test all functions
    print_products();
    add_product("Grape", 1.00, 5);
    update_quantity("Apple", 5);
    remove_product("Banana");
    update_price("Orange", 0.50);
    print_products();
    return 0;
}