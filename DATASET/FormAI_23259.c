//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum quantities and lengths
#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50

// Define structures for products and warehouses
struct product {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
};

struct warehouse {
    int id;
    char location[MAX_NAME_LENGTH];
    struct product products[MAX_PRODUCTS];
    int num_products;
};

// Function to find a product in a warehouse by ID and return its index
int find_product(struct warehouse *w, int id) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Initialize warehouses and products
    struct warehouse warehouses[10];
    int next_warehouse_id = 1;
    int next_product_id = 1;

    // Main loop
    int choice = 0;
    while (choice != 5) {
        printf("Main Menu:\n");
        printf("1. Add a warehouse\n");
        printf("2. Add a product to a warehouse\n");
        printf("3. Remove a product from a warehouse\n");
        printf("4. Display warehouse inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Add a warehouse
                struct warehouse w;
                w.id = next_warehouse_id;
                next_warehouse_id++;
                printf("Enter location of warehouse: ");
                scanf("%s", w.location);
                w.num_products = 0;
                warehouses[w.id - 1] = w;
                printf("Warehouse added with ID %d\n", w.id);
                break;
            }
            case 2: {
                // Add a product to a warehouse
                int warehouse_id, quantity;
                char product_name[MAX_NAME_LENGTH];
                printf("Enter warehouse ID: ");
                scanf("%d", &warehouse_id);
                int warehouse_index = warehouse_id - 1;
                if (warehouse_index < 0 || warehouse_index >= 10) {
                    printf("Invalid warehouse ID\n");
                    break;
                }
                struct warehouse *w = &warehouses[warehouse_index];
                printf("Enter product name: ");
                scanf("%s", product_name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                struct product p;
                p.id = next_product_id;
                next_product_id++;
                strcpy(p.name, product_name);
                p.quantity = quantity;
                int existing_index = find_product(w, p.id);
                if (existing_index != -1) {
                    // Product already exists, just update quantity
                    w->products[existing_index].quantity += quantity;
                } else {
                    // New product, add to warehouse
                    if (w->num_products >= MAX_PRODUCTS) {
                        printf("Warehouse is full\n");
                        break;
                    }
                    w->products[w->num_products] = p;
                    w->num_products++;
                }
                printf("Product added with ID %d\n", p.id);
                break;
            }
            case 3: {
                // Remove a product from a warehouse
                int warehouse_id, product_id, quantity;
                printf("Enter warehouse ID: ");
                scanf("%d", &warehouse_id);
                int warehouse_index = warehouse_id - 1;
                if (warehouse_index < 0 || warehouse_index >= 10) {
                    printf("Invalid warehouse ID\n");
                    break;
                }
                struct warehouse *w = &warehouses[warehouse_index];
                printf("Enter product ID: ");
                scanf("%d", &product_id);
                int product_index = find_product(w, product_id);
                if (product_index == -1) {
                    printf("Product not found in warehouse\n");
                    break;
                }
                printf("Enter quantity to remove: ");
                scanf("%d", &quantity);
                if (w->products[product_index].quantity < quantity) {
                    printf("Insufficient quantity in warehouse\n");
                    break;
                }
                w->products[product_index].quantity -= quantity;
                if (w->products[product_index].quantity == 0) {
                    // Remove product from warehouse
                    int i;
                    for (i = product_index; i < w->num_products - 1; i++) {
                        w->products[i] = w->products[i + 1];
                    }
                    w->num_products--;
                }
                printf("Product quantity updated\n");
                break;
            }
            case 4: {
                // Display warehouse inventory
                int warehouse_id;
                printf("Enter warehouse ID: ");
                scanf("%d", &warehouse_id);
                int warehouse_index = warehouse_id - 1;
                if (warehouse_index < 0 || warehouse_index >= 10) {
                    printf("Invalid warehouse ID\n");
                    break;
                }
                struct warehouse *w = &warehouses[warehouse_index];
                printf("Warehouse %d: %s\n", w->id, w->location);
                printf("Product ID   Name              Quantity\n");
                int i;
                for (i = 0; i < w->num_products; i++) {
                    printf("%-12d%-18s%d\n", w->products[i].id, w->products[i].name, w->products[i].quantity);
                }
                break;
            }
            case 5: {
                // Exit
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }

    return 0;
}