//FormAI DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    float price;
    int quantity;
};

struct Inventory {
    struct Product products[MAX_PRODUCTS];
    int count;
};

void addProduct(struct Inventory *inventory, struct Product product) {
    if (inventory->count < MAX_PRODUCTS) {
        inventory->products[inventory->count] = product;
        inventory->count++;
    } else {
        printf("Inventory is full!\n");
    }
}

void printInventory(struct Inventory inventory) {
    printf("Product Name\tPrice\tQuantity\n");
    printf("--------------------------------\n");

    for (int i = 0; i < inventory.count; i++) {
        struct Product product = inventory.products[i];
        printf("%s\t\t%.2f\t%d\n", product.name, product.price, product.quantity);
    }
}

int main() {
    struct Inventory inventory = { .count = 0 };

    struct Product product1 = { 
        .name = "Apple",
        .price = 0.50,
        .quantity = 100
    };

    struct Product product2 = { 
        .name = "Banana",
        .price = 0.25,
        .quantity = 50
    };

    struct Product product3 = { 
        .name = "Orange",
        .price = 0.75,
        .quantity = 75
    };

    addProduct(&inventory, product1);
    addProduct(&inventory, product2);
    addProduct(&inventory, product3);

    printInventory(inventory);

    return 0;
}