//FormAI DATASET v1.0 Category: Product Inventory System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(char name[], int quantity, float price) {
    if (numProducts >= MAX_PRODUCTS) {
        printf("Error: cannot add more products\n");
        return;
    }

    Product p;
    strcpy(p.name, name);
    p.quantity = quantity;
    p.price = price;

    products[numProducts++] = p;
}

void printProduct(Product p) {
    printf("%s: %d x $%.2f = $%.2f\n", p.name, p.quantity, p.price, p.quantity * p.price);
}

void printInventory() {
    float totalPrice = 0;

    printf("==============================\n");
    printf("|     PRODUCT INVENTORY      |\n");
    printf("==============================\n");

    for (int i = 0; i < numProducts; i++) {
        printProduct(products[i]);
        totalPrice += products[i].quantity * products[i].price;
    }

    printf("==============================\n");
    printf("Total value: $%.2f\n", totalPrice);
}

void updateQuantity(char name[], int newQuantity) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity = newQuantity;
            printf("Quantity of %s updated to %d\n", name, newQuantity);
            return;
        }
    }

    printf("Error: product %s not found\n", name);
}

int main() {
    addProduct("Apple", 10, 0.5);
    addProduct("Banana", 5, 0.3);
    addProduct("Orange", 15, 0.4);

    printInventory();

    updateQuantity("Apple", 5);
    updateQuantity("Grape", 8);

    printInventory();

    return 0;
}