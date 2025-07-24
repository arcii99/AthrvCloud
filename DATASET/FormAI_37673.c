//FormAI DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    char category[50];
    int quantity;
    float price;
};

struct Inventory {
    int num_products;
    struct Product products[MAX_PRODUCTS];
};

void add_product(struct Inventory *inv, char *name, char *category, int quantity, float price) {
    if (inv->num_products >= MAX_PRODUCTS) {
        printf("Error: inventory is full.\n");
        return;
    }
    struct Product p;
    strcpy(p.name, name);
    strcpy(p.category, category);
    p.quantity = quantity;
    p.price = price;
    inv->products[inv->num_products++] = p;
}

void print_inventory(struct Inventory *inv) {
    printf("Product Name\tCategory\tQuantity\tPrice\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%s\t\t%s\t\t%d\t\t%.2f\n", inv->products[i].name, inv->products[i].category, inv->products[i].quantity, inv->products[i].price);
    }
}

int main() {
    struct Inventory inv = {0};
    add_product(&inv, "Apple", "Fruit", 50, 0.50);
    add_product(&inv, "Banana", "Fruit", 25, 0.25);
    add_product(&inv, "Orange", "Fruit", 35, 0.30);
    add_product(&inv, "Milk", "Dairy", 20, 1.50);
    add_product(&inv, "Cheese", "Dairy", 15, 2.50);
    add_product(&inv, "Bread", "Bakery", 10, 1.00);
    print_inventory(&inv);
    return 0;
}