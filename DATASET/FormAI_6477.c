//FormAI DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100

// struct to represent a product
typedef struct {
    int product_id;
    char product_name[50];
    float price;
    int quantity;
} product_t;

// global inventory array
product_t inventory[MAX_PRODUCTS];

// number of products in the inventory
int num_products = 0;

// function to add a product to the inventory
void add_product(int product_id, char* product_name, float price, int quantity) {
    product_t new_product;
    new_product.product_id = product_id;
    strcpy(new_product.product_name, product_name);
    new_product.price = price;
    new_product.quantity = quantity;
    inventory[num_products++] = new_product;
}

// function to find a product by its id and return a pointer to it
product_t* find_product_by_id(int product_id) {
    for(int i=0; i<num_products; i++) {
        if(inventory[i].product_id == product_id) {
            return &inventory[i];
        }
    }
    return NULL;
}

int main() {
    // adding some products to the inventory
    add_product(1, "iPhone XR", 749.99, 50);
    add_product(2, "Samsung Galaxy S10", 899.99, 30);
    add_product(3, "Macbook Pro", 1499.99, 20);
    add_product(4, "HP Elitebook", 1199.99, 25);
    
    // displaying the inventory
    printf("Product Inventory:\n");
    printf("ID\tName\t\t\tPrice\tQuantity\n");
    for(int i=0; i<num_products; i++) {
        printf("%d\t%s\t\t$%.2f\t%d\n", inventory[i].product_id, inventory[i].product_name, inventory[i].price, inventory[i].quantity);
    }
    printf("\n");
    
    // finding a product by id
    int product_id = 2;
    printf("Finding product with id %d:\n", product_id);
    product_t *found_product = find_product_by_id(product_id);
    if(found_product != NULL) {
        printf("Product found:\n");
        printf("ID\tName\t\t\tPrice\tQuantity\n");
        printf("%d\t%s\t\t$%.2f\t%d\n", found_product->product_id, found_product->product_name, found_product->price, found_product->quantity);
    } else {
        printf("Product not found!\n");
    }
    
    // updating the quantity of a product
    product_id = 1;
    int new_quantity = 40;
    printf("\nUpdating quantity of product with id %d to %d:\n", product_id, new_quantity);
    found_product = find_product_by_id(product_id);
    if(found_product != NULL) {
        found_product->quantity = new_quantity;
        printf("Quantity updated!\n");
        printf("ID\tName\t\t\tPrice\tQuantity\n");
        printf("%d\t%s\t\t$%.2f\t%d\n", found_product->product_id, found_product->product_name, found_product->price, found_product->quantity);
    } else {
        printf("Product not found!\n");
    }
    
    return 0;
}