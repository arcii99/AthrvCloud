//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

// Product struct
typedef struct {
    char name[50];
    int quantity;
} Product;

// Warehouse struct
typedef struct {
    Product products[MAX_PRODUCTS];
    int numOfProducts;
} Warehouse;

// Initialize a new Warehouse
Warehouse initWarehouse() {
    Warehouse warehouse;
    warehouse.numOfProducts = 0;
    return warehouse;
}

// Add a new product to the Warehouse
void addProduct(Warehouse *warehouse, char name[50], int quantity) {
    Product product;
    strcpy(product.name, name);
    product.quantity = quantity;
    warehouse->products[warehouse->numOfProducts++] = product;
}

// Remove a product from the Warehouse by name
void removeProduct(Warehouse *warehouse, char name[50]) {
    for (int i = 0; i < warehouse->numOfProducts; i++) {
        if (strcmp(name, warehouse->products[i].name) == 0) {
            for (int j = i; j < warehouse->numOfProducts - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->numOfProducts--;
            break;
        }
    }
}

// Update a product's quantity in the Warehouse
void updateProduct(Warehouse *warehouse, char name[50], int quantity) {
    for (int i = 0; i < warehouse->numOfProducts; i++) {
        if (strcmp(name, warehouse->products[i].name) == 0) {
            warehouse->products[i].quantity = quantity;
            break;
        }
    }
}

// Search for a product in the Warehouse by name and return its index
int searchProduct(Warehouse warehouse, char name[50]) {
    for (int i = 0; i < warehouse.numOfProducts; i++) {
        if (strcmp(name, warehouse.products[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

// Print all products in the Warehouse
void printProducts(Warehouse warehouse) {
    printf("Products in Warehouse:\n");
    for (int i = 0; i < warehouse.numOfProducts; i++) {
        printf("%d. %s - Quantity: %d\n", i + 1, warehouse.products[i].name, warehouse.products[i].quantity);
    }
}

int main() {
    Warehouse warehouse = initWarehouse();
    addProduct(&warehouse, "Soda", 50);
    addProduct(&warehouse, "Chips", 100);
    addProduct(&warehouse, "Candy", 200);
    printf("Initial state of Warehouse:\n");
    printProducts(warehouse);

    // Remove "Chips" from Warehouse
    printf("\nRemoving \"Chips\" from Warehouse...\n");
    removeProduct(&warehouse, "Chips");
    printProducts(warehouse);

    // Update the quantity of "Soda" in Warehouse
    printf("\nUpdating the quantity of \"Soda\" in Warehouse to 100...\n");
    updateProduct(&warehouse, "Soda", 100);
    printProducts(warehouse);

    // Search for "Candy" in Warehouse and print its quantity
    printf("\nSearching for \"Candy\" in Warehouse...\n");
    int index = searchProduct(warehouse, "Candy");
    if (index != -1) {
        printf("\"Candy\" found in Warehouse - Quantity: %d\n", warehouse.products[index].quantity);
    } else {
        printf("\"Candy\" not found in Warehouse\n");
    }

    return 0;
}