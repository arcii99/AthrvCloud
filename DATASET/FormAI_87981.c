//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000   // maximum number of products in the warehouse
#define MAX_NAME_LENGTH 50  // maximum length of product name

// a struct to represent a product in the warehouse
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Product;

// a struct to represent the warehouse
typedef struct {
    Product products[MAX_PRODUCTS];
    int num_products;
    double total_value;
} Warehouse;

// function to add a new product to the warehouse
void add_product(Warehouse* warehouse, char* name, int quantity, double price) {
    if (warehouse->num_products >= MAX_PRODUCTS) {
        printf("Warehouse is full, cannot add more products.\n");
        return;
    }
    Product new_product;
    strncpy(new_product.name, name, MAX_NAME_LENGTH);
    new_product.quantity = quantity;
    new_product.price = price;
    warehouse->products[warehouse->num_products] = new_product;
    warehouse->num_products++;
    warehouse->total_value += quantity * price;
    printf("Added product: %s Quantity: %d Price: %.2f\n", name, quantity, price);
}

// function to remove a product from the warehouse
void remove_product(Warehouse* warehouse, char* name) {
    int index = -1;
    for (int i = 0; i < warehouse->num_products; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }
    warehouse->total_value -= warehouse->products[index].quantity * warehouse->products[index].price;
    for (int i = index; i < warehouse->num_products - 1; i++) {
        warehouse->products[i] = warehouse->products[i+1];
    }
    warehouse->num_products--;
    printf("Removed product: %s\n", name);
}

// function to print the warehouse inventory report
void print_report(Warehouse* warehouse) {
    printf("---------- Inventory Report ----------\n");
    printf("Number of Products: %d\n", warehouse->num_products);
    printf("Total Value: %.2f\n", warehouse->total_value);
    printf("Products:\n");
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("%s\tQuantity: %d\tPrice: %.2f\n", warehouse->products[i].name,
                                                    warehouse->products[i].quantity,
                                                    warehouse->products[i].price);
    }
    printf("---------- End of Report ----------\n");
}

int main() {
    Warehouse warehouse;
    warehouse.num_products = 0;
    warehouse.total_value = 0.0;
    
    // adding some initial products to the warehouse
    add_product(&warehouse, "Pencil", 100, 0.50);
    add_product(&warehouse, "Notebook", 50, 2.50);
    add_product(&warehouse, "Eraser", 200, 0.25);
    
    // printing the initial inventory report
    print_report(&warehouse);
    
    // adding a new product
    add_product(&warehouse, "Marker", 20, 1.25);
    
    // removing a product
    remove_product(&warehouse, "Pencil");
    
    // printing the updated inventory report
    print_report(&warehouse);
    
    return 0;
}