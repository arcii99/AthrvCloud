//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50

// Define structures
struct Product {
    char name[MAX_NAME_LEN];
    int quantity;
};

struct Warehouse {
    struct Product products[MAX_PRODUCTS];
    int num_products;
};

// Define global variables
struct Warehouse warehouse;

// Define functions
void addProduct(char* name, int quantity) {
    // Check if warehouse is full
    if (warehouse.num_products == MAX_PRODUCTS) {
        printf("Sorry, warehouse is full.\n");
        return;
    }

    // Add product to warehouse
    struct Product new_product;
    strcpy(new_product.name, name);
    new_product.quantity = quantity;
    warehouse.products[warehouse.num_products] = new_product;
    warehouse.num_products++;

    printf("Product added successfully!\n");
}

void removeProduct(char* name, int quantity) {
    // Find product in warehouse
    int i, index = -1;
    for (i = 0; i < warehouse.num_products; i++) {
        if (strcmp(warehouse.products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if product was found
    if (index == -1) {
        printf("Sorry, product not found.\n");
        return;
    }

    // Check if quantity is valid
    if (quantity > warehouse.products[index].quantity) {
        printf("Sorry, not enough product in warehouse.\n");
        return;
    }

    // Remove product from warehouse
    warehouse.products[index].quantity -= quantity;

    printf("Product removed successfully!\n");
}

void displayProducts() {
    // Check if warehouse is empty
    if (warehouse.num_products == 0) {
        printf("Warehouse is empty.\n");
        return;
    }

    // Display products in warehouse
    int i;
    for (i = 0; i < warehouse.num_products; i++) {
        printf("%s: %d\n", warehouse.products[i].name, warehouse.products[i].quantity);
    }
}

// Define main function
int main() {
    // Initialize warehouse
    warehouse.num_products = 0;

    // Display menu
    printf("Welcome to the Warehouse Management System!\n\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Display products\n");
    printf("4. Exit\n");

    // Loop until user chooses to exit
    int choice;
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Get product name and quantity from user
                char name[MAX_NAME_LEN];
                int quantity;
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);

                // Add product to warehouse
                addProduct(name, quantity);

                break;

            case 2:
                // Get product name and quantity from user
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);

                // Remove product from warehouse
                removeProduct(name, quantity);

                break;

            case 3:
                // Display products in warehouse
                displayProducts();

                break;

            case 4:
                // Exit program
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}