//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTS 50 // Maximum number of products in the inventory system
#define MAX_NAME_LENGTH 50 // Maximum length of product names

// Product struct representing each item in the inventory system
struct Product {
    char name[MAX_NAME_LENGTH];
    int id;
    int quantity;
    float price;
};

// Global variables
struct Product inventory[MAX_PRODUCTS]; // Inventory system containing all products
int num_products = 0; // Keep track of the number of products currently in the inventory

// Function prototypes
bool add_product(char name[], int id, int quantity, float price);
bool remove_product(int id);
void print_inventory();
void print_product(struct Product prod);

int main() {
    // Test cases
    add_product("Samsung Galaxy S20", 1, 10, 999.99);
    add_product("iPhone 11 Pro", 2, 15, 1199.99);
    add_product("Google Pixel 4", 3, 20, 899.99);
    add_product("OnePlus 8 Pro", 4, 30, 799.99);

    remove_product(2);

    print_inventory();

    return 0;
}

// Adds a new product to the inventory system
// Returns true if the product was successfully added, false otherwise
bool add_product(char name[], int id, int quantity, float price) {
    if (num_products >= MAX_PRODUCTS) {
        return false; // If the inventory is full, return false
    }

    // Create a new product with the given information and add it to the inventory system
    struct Product new_prod;
    strcpy(new_prod.name, name);
    new_prod.id = id;
    new_prod.quantity = quantity;
    new_prod.price = price;

    inventory[num_products] = new_prod;
    num_products++;

    return true;
}

// Removes a product from the inventory system with the given ID
// Returns true if the product was successfully removed, false otherwise
bool remove_product(int id) {
    int found_index = -1; // Index of the product with the given ID

    // Find the index of the product with the given ID
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        return false; // Product not found, return false
    }

    // Shift all products after the found index one position to the left to remove the product
    for (int i = found_index; i < num_products - 1; i++) {
        inventory[i] = inventory[i+1];
    }

    num_products--;

    return true;
}

// Prints the entire inventory system
void print_inventory() {
    printf("Product Inventory System\n");
    printf("--------------------------------------------------------------\n");
    printf("|%-20s|%-10s|%-10s|%-10s|\n", "Product Name", "Product ID", "Quantity", "Price");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < num_products; i++) {
        print_product(inventory[i]);
    }

    printf("--------------------------------------------------------------\n");
}

// Prints a single product
void print_product(struct Product prod) {
    printf("|%-20s|%-10d|%-10d|%-10.2f|\n", prod.name, prod.id, prod.quantity, prod.price);
}