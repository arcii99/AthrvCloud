//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defining constants */
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 20
#define MAX_ITEM_DESCRIPTION 50

/* Defining product struct */
typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
    char description[MAX_ITEM_DESCRIPTION];
} product;

/* Defining warehouse struct */
typedef struct {
    product products[MAX_PRODUCTS];
    int total_products;
} warehouse;

/* Function to add a product to the warehouse */
void add_product(warehouse *w, product p) {
    if (w->total_products < MAX_PRODUCTS) {
        w->products[w->total_products] = p;
        w->total_products++;
        printf("%s has been added to the warehouse.\n", p.name);
    } else {
        printf("The warehouse is full, cannot add %s.\n", p.name);
    }
}

/* Function to remove a product from the warehouse */
void remove_product(warehouse *w, product p) {
    for (int i = 0; i < w->total_products; i++) {
        if (strcmp(w->products[i].name, p.name) == 0) {
            for (int j = i; j < w->total_products - 1; j++) {
                w->products[j] = w->products[j+1];
            }
            w->total_products--;
            printf("%s has been removed from the warehouse.\n", p.name);
            return;
        }
    }
    printf("%s not found in the warehouse.\n", p.name);
}

/* Function to update a product in the warehouse */
void update_product(warehouse *w, product p) {
    for (int i = 0; i < w->total_products; i++) {
        if (strcmp(w->products[i].name, p.name) == 0) {
            w->products[i] = p;
            printf("%s has been updated in the warehouse.\n", p.name);
            return;
        }
    }
    printf("%s not found in the warehouse.\n", p.name);
}

/* Function to display all products in the warehouse */
void display_products(warehouse *w) {
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < w->total_products; i++) {
        printf("Product Name: %s\n", w->products[i].name);
        printf("Price: $%.2f\n", w->products[i].price);
        printf("Quantity: %d\n", w->products[i].quantity);
        printf("Description: %s\n", w->products[i].description);
        printf("------------------------\n");
    }
}

int main() {
    /* Initializing warehouse with some products */
    warehouse w;
    product p1 = {"Keyboard", 25.99, 50, "Mechanical Keyboard with RGB lighting."};
    product p2 = {"Mouse", 12.99, 75, "Wireless Gaming Mouse with 10,000 DPI."};
    product p3 = {"Headphones", 49.99, 30, "Over-ear Headphones with Active Noise Cancelling."};
    product p4 = {"Speakers", 79.99, 15, "Bluetooth Speakers with Excellent Bass."};
    w.total_products = 4;
    w.products[0] = p1;
    w.products[1] = p2;
    w.products[2] = p3;
    w.products[3] = p4;

    /* Displaying initial products */
    printf("Initial Warehouse Inventory:\n");
    display_products(&w);
    printf("------------------------\n");

    /* Adding a new product */
    product p5 = {"Monitor", 199.99, 20, "27 inch 1440p Gaming Monitor."};
    add_product(&w, p5);
    printf("------------------------\n");

    /* Removing a product */
    product p6 = {"Keyboard"};
    remove_product(&w, p6);
    printf("------------------------\n");

    /* Updating a product */
    product p7 = {"Headphones", 59.99, 40, "Over-ear Headphones with Excellent Sound Quality and Noise Cancelling."};
    update_product(&w, p7);
    printf("------------------------\n");

    /* Displaying final products */
    printf("Final Warehouse Inventory:\n");
    display_products(&w);

    return 0;
}