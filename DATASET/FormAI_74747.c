//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of warehouse and product name
#define MAX_WAREHOUSE 10
#define MAX_PRODUCT_NAME 20

// Structure to hold product information
typedef struct product {
    char name[MAX_PRODUCT_NAME];
    int quantity;
} Product;

// Structure to hold warehouse information and product inventory
typedef struct warehouse {
    char name[MAX_PRODUCT_NAME];
    int total_inventory;
    Product products[MAX_WAREHOUSE];
} Warehouse;

// Function to add a product to a warehouse inventory
void add_product(Warehouse* wh, char name[MAX_PRODUCT_NAME], int quantity) {
    // Check if product with the same name already exists in warehouse
    for (int i = 0; i < MAX_WAREHOUSE; i++) {
        if (strcmp(wh->products[i].name, name) == 0) {
            wh->products[i].quantity += quantity;
            wh->total_inventory += quantity;
            return;
        }
    }
    // If product doesn't exist, add it to the first empty slot in the array
    for (int i = 0; i < MAX_WAREHOUSE; i++) {
        if (wh->products[i].quantity == 0) {
            strcpy(wh->products[i].name, name);
            wh->products[i].quantity = quantity;
            wh->total_inventory += quantity;
            return;
        }
    }
    // If no empty slot is found, print error message
    printf("ERROR: Cannot add product, maximum warehouse capacity reached.\n");
}

// Function to remove a product from a warehouse inventory
void remove_product(Warehouse* wh, char name[MAX_PRODUCT_NAME], int quantity) {
    // Check if product with the same name exists in warehouse
    for (int i = 0; i < MAX_WAREHOUSE; i++) {
        if (strcmp(wh->products[i].name, name) == 0) {
            if (wh->products[i].quantity >= quantity) {
                wh->products[i].quantity -= quantity;
                wh->total_inventory -= quantity;
                return;
            }
            else {
                printf("ERROR: Cannot remove product, not enough quantity available.\n");
                return;
            }
        }
    }
    // If product doesn't exist, print error message
    printf("ERROR: Cannot remove product, product not found in warehouse.\n");
}

// Function to print inventory of a warehouse
void print_inventory(Warehouse* wh) {
    printf("Warehouse: %s\n", wh->name);
    printf("Total Inventory: %d\n", wh->total_inventory);
    printf("Product Inventory:\n");
    for (int i = 0; i < MAX_WAREHOUSE; i++) {
        if (wh->products[i].quantity > 0) {
            printf("- %s: %d\n", wh->products[i].name, wh->products[i].quantity);
        }
    }
}

int main() {
    Warehouse wh1, wh2;
    strcpy(wh1.name, "Warehouse A");
    wh1.total_inventory = 0;
    strcpy(wh2.name, "Warehouse B");
    wh2.total_inventory = 0;
    
    // Add products to warehouse inventories
    add_product(&wh1, "Product A", 10);
    add_product(&wh1, "Product B", 5);
    add_product(&wh2, "Product C", 20);
    add_product(&wh2, "Product A", 15);
    
    // Print inventories before and after removing products
    print_inventory(&wh1);
    print_inventory(&wh2);
    remove_product(&wh1, "Product B", 3);
    remove_product(&wh2, "Product A", 12);
    print_inventory(&wh1);
    print_inventory(&wh2);
    
    return 0;
}