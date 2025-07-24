//FormAI DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 1000

// Product structure definition
typedef struct {
    int id;
    char name[50];
    double price;
    int quantity;
} Product;

// Local storage of the products inventory
Product products[MAX_PRODUCTS];
int num_products = 0;

// Function to add a new product to the inventory
void add_product(int id, char name[], double price, int quantity) {
    if (num_products < MAX_PRODUCTS) {
        Product p = {
            .id = id,
            .price = price,
            .quantity = quantity
        };
        strcpy(p.name, name);
        products[num_products++] = p;
    }
}

int main() {
    // Initialize with some example products
    add_product(1, "Water Bottle", 5.99, 100);
    add_product(2, "Canned Food", 2.99, 150);
    add_product(3, "Knife", 9.99, 50);
    add_product(4, "Ammunition", 0.99, 200);

    // Display the inventory
    printf("ID\tName\t\t\tPrice\tQuantity\n");
    printf("--\t----\t\t\t-----\t--------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%-20s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}