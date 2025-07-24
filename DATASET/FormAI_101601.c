//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_ORDERS 100

// Define struct for a product
typedef struct {
    int id;
    char name[50];
    int quantity;
} Product;

// Define struct for an order
typedef struct {
    int id;
    Product products[MAX_PRODUCTS];
} Order;

// Define global variables
Product inventory[MAX_PRODUCTS];
Order orders[MAX_ORDERS];
int num_products = 0;
int num_orders = 0;

// Function to add a product to the inventory
void add_product(int id, char name[], int quantity) {
    Product new_product;
    new_product.id = id;
    strcpy(new_product.name, name);
    new_product.quantity = quantity;
    inventory[num_products] = new_product;
    num_products++;
}

// Function to get the index of a product in the inventory
int get_product_index(int product_id) {
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == product_id) {
            return i;
        }
    }
    return -1;
}

// Function to place an order
void place_order(int order_id, int product_ids[], int quantities[], int num_products) {
    Order new_order;
    new_order.id = order_id;
    for (int i = 0; i < num_products; i++) {
        int product_index = get_product_index(product_ids[i]);
        if (product_index == -1 || inventory[product_index].quantity < quantities[i]) {
            printf("Error: Product with ID %d is out of stock or does not exist\n", product_ids[i]);
            return;
        }
        new_order.products[i] = inventory[product_index];
        new_order.products[i].quantity = quantities[i];
    }
    orders[num_orders] = new_order;
    num_orders++;
    for (int i = 0; i < num_products; i++) {
        int product_index = get_product_index(product_ids[i]);
        inventory[product_index].quantity -= quantities[i];
    }
    printf("Order placed successfully!\n");
}

// Function to print the inventory
void print_inventory() {
    printf("Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
    printf("\n");
}

// Function to print an order
void print_order(Order order) {
    printf("Order ID: %d\n", order.id);
    printf("Products:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (order.products[i].id != 0) {
            printf("%d\t%s\t%d\n", order.products[i].id, order.products[i].name, order.products[i].quantity);
        }
    }
    printf("\n");
}

// Function to print all orders
void print_orders() {
    printf("Orders:\n");
    for (int i = 0; i < num_orders; i++) {
        print_order(orders[i]);
    }
}

int main() {
    // Add products to inventory
    add_product(1001, "iPhone X", 10);
    add_product(1002, "Samsung Galaxy S9", 15);
    add_product(1003, "Google Pixel 2", 7);

    // Print inventory
    print_inventory();

    // Place an order for 3 iPhone X's and 1 Google Pixel 2
    int product_ids[] = {1001, 1003};
    int quantities[] = {3, 1};
    place_order(1, product_ids, quantities, 2);

    // Print inventory and orders
    print_inventory();
    print_orders();

    return 0;
}