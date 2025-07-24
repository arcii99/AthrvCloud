//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_PRODUCTS 50
#define PRODUCT_NAME_LENGTH 50
 
typedef struct {
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
    float price;
} Product;
 
typedef struct {
    Product products[MAX_PRODUCTS];
    int total_products;
} Inventory;
 
void init_inventory(Inventory *inventory) {
    inventory->total_products = 0;
}
 
void add_product(Inventory *inventory, char *name, int quantity, float price) {
    if (inventory->total_products >= MAX_PRODUCTS) {
        printf("Error: Inventory full! Cannot add product\n");
        return;
    }
 
    Product new_product;
    strncpy(new_product.name, name, PRODUCT_NAME_LENGTH);
    new_product.quantity = quantity;
    new_product.price = price;
 
    inventory->products[inventory->total_products++] = new_product;
}
 
void remove_product(Inventory *inventory, char *name) {
    int index_to_remove = -1;
 
    for (int i = 0; i < inventory->total_products; i++) {
        Product current_product = inventory->products[i];
        if (strcmp(current_product.name, name) == 0) {
            index_to_remove = i;
            break;
        }
    }
 
    if (index_to_remove == -1) {
        printf("Error: Product not found!\n");
        return;
    }
 
    for (int i = index_to_remove; i < inventory->total_products - 1; i++) {
        inventory->products[i] = inventory->products[i + 1];
    }
    inventory->total_products--;
}
 
void print_inventory(Inventory *inventory) {
    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < inventory->total_products; i++) {
        Product current_product = inventory->products[i];
        printf("%s\t\t%d\t\t%.2f\n", current_product.name, current_product.quantity, current_product.price);
    }
}
 
int main() {
    Inventory inventory;
    init_inventory(&inventory);
 
    //Adding products
    add_product(&inventory, "Pen", 30, 10.50);
    add_product(&inventory, "Pencil", 20, 5.75);
    add_product(&inventory, "Eraser", 50, 8.20);
 
    //Print Inventory
    print_inventory(&inventory);
 
    //Removing a product
    remove_product(&inventory, "Pen");
 
    //Print Inventory
    print_inventory(&inventory);
 
    return 0;
}