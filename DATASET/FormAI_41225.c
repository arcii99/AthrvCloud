//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

typedef struct {
    char name[50];
    int quantity;
    double price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int numProducts;
} Warehouse;

void addProduct(Warehouse *warehouse, char *name, int quantity, double price) {
    if (warehouse->numProducts >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    Product product;
    strcpy(product.name, name);
    product.quantity = quantity;
    product.price = price;

    warehouse->products[warehouse->numProducts] = product;
    warehouse->numProducts++;
}

void removeProduct(Warehouse *warehouse, char *name) {
    int index = -1;
    for (int i = 0; i < warehouse->numProducts; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    for (int i = index; i < warehouse->numProducts - 1; i++) {
        warehouse->products[i] = warehouse->products[i + 1];
    }

    warehouse->numProducts--;
}

void printWarehouse(Warehouse *warehouse) {
    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < warehouse->numProducts; i++) {
        printf("%s\t%d\t\t%.2f\n", warehouse->products[i].name,
                                    warehouse->products[i].quantity,
                                    warehouse->products[i].price);
    }
}

int main() {
    Warehouse warehouse;
    warehouse.numProducts = 0;

    addProduct(&warehouse, "Apple", 50, 0.5);
    addProduct(&warehouse, "Banana", 30, 0.3);
    addProduct(&warehouse, "Orange", 40, 0.4);

    printf("\nInitial Warehouse:\n");
    printWarehouse(&warehouse);

    removeProduct(&warehouse, "Banana");

    printf("\nAfter removing Banana:\n");
    printWarehouse(&warehouse);

    return 0;
}