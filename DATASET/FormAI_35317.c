//FormAI DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the maximum number of products in inventory
#define MAX_PRODUCTS 100

// Define a struct for a product
typedef struct {
    int id;
    char name[50];
    double price;
    int quantity;
} Product;

// Define a struct for inventory
typedef struct {
    int num_products;
    Product products[MAX_PRODUCTS];
} Inventory;

// Function to add a product to inventory
void add_product(Inventory *inv, Product prod) {
    if (inv->num_products >= MAX_PRODUCTS) {
        printf("Inventory is full\n");
        return;
    }
    inv->products[inv->num_products] = prod;
    inv->num_products++;
}

// Function to remove a product from inventory
void remove_product(Inventory *inv, int id) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            inv->products[i] = inv->products[inv->num_products - 1];
            inv->num_products--;
            printf("Product with ID %d removed from inventory\n", id);
            return;
        }
    }
    printf("Product with ID %d not found in inventory\n", id);
}

// Function to get the total value of the inventory
double inventory_value(Inventory inv) {
    int i;
    double value = 0;
    for (i = 0; i < inv.num_products; i++) {
        value += inv.products[i].price * inv.products[i].quantity;
    }
    return value;
}

// Function to display all products in inventory
void display_products(Inventory inv) {
    int i;
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (i = 0; i < inv.num_products; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", inv.products[i].id, inv.products[i].name, inv.products[i].price, inv.products[i].quantity);
    }
}

// Main function
int main() {
    // Initialize the inventory
    Inventory inv;
    inv.num_products = 0;

    // Add some products to the inventory
    Product prod1 = {1, "Product 1", 10.99, 5};
    Product prod2 = {2, "Product 2", 5.99, 10};
    Product prod3 = {3, "Product 3", 20.50, 2};
    add_product(&inv, prod1);
    add_product(&inv, prod2);
    add_product(&inv, prod3);

    // Display the current inventory
    display_products(inv);

    // Remove a product from the inventory
    remove_product(&inv, 2);

    // Display the updated inventory
    printf("\n");
    display_products(inv);

    // Get the total value of the inventory and display it
    double value = inventory_value(inv);
    printf("\nTotal inventory value: $%.2f\n", value);

    return 0;
}