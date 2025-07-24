//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id; // unique identifier
    char name[50]; // name of the product
    double price; // price of the product
    int quantity; // quantity in stock
} Product;

Product products[MAX_PRODUCTS]; // array of products
int num_products = 0; // number of products in the inventory

// function to add a product to the inventory
void add_product(int id, char name[], double price, int quantity){
    if (num_products >= MAX_PRODUCTS) {
        printf("Cannot add product - maximum number of products reached\n");
        return;
    }
    products[num_products].id = id;
    strcpy(products[num_products].name, name);
    products[num_products].price = price;
    products[num_products].quantity = quantity;
    num_products++;
}

// function to remove a product from the inventory
void remove_product(int id) {
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found\n");
        return;
    }
    for (int i = index; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }
    num_products--;
    printf("Product removed successfully\n");
}

// function to display all products in the inventory
void display_products() {
    printf("Products in inventory:\n");
    printf("----------------------\n");
    printf("%-10s%-20s%-10s%-10s\n", "ID", "Name", "Price", "Quantity");
    for (int i = 0; i < num_products; i++) {
        printf("%-10d%-20s%-10.2f%-10d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("----------------------\n");
}

int main() {
    // add some products to the inventory
    add_product(1, "Apple", 0.99, 100);
    add_product(2, "Banana", 0.50, 50);
    add_product(3, "Orange", 1.25, 75);
    
    // display all products
    display_products();
    
    // remove a product
    remove_product(2);
    
    // display all products again
    display_products();
    
    return 0;
}