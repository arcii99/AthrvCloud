//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the structure of product
struct Product {
    char name[20];
    int quantity;
    float price;
};

// Defining the structure of warehouse
struct Warehouse {
    char name[20];
    int num_products;
    struct Product products[100];
};

// Function to create a warehouse
void create_warehouse(struct Warehouse *warehouse, char name[]) {
    strcpy(warehouse->name, name);
    warehouse->num_products = 0;
}

// Function to add a product in warehouse
void add_product(struct Warehouse *warehouse, char name[], int quantity, float price) {
    strcpy(warehouse->products[warehouse->num_products].name, name);
    warehouse->products[warehouse->num_products].quantity = quantity;
    warehouse->products[warehouse->num_products].price = price;
    warehouse->num_products++;
}

// Function to search a product in warehouse
int search_product(struct Warehouse warehouse, char name[]) {
    for(int i=0; i<warehouse.num_products; i++) {
        if(strcmp(warehouse.products[i].name, name) == 0)
            return i;
    }
    return -1;
}

// Function to update a product in warehouse
void update_product(struct Warehouse *warehouse, char name[], int quantity) {
    int index = search_product(*warehouse, name);
    if(index != -1)
        warehouse->products[index].quantity += quantity;
}

// Function to delete a product from warehouse
void delete_product(struct Warehouse *warehouse, char name[]) {
    int index = search_product(*warehouse, name);
    if(index != -1) {
        for(int i=index; i<warehouse->num_products-1; i++) {
            strcpy(warehouse->products[i].name, warehouse->products[i+1].name);
            warehouse->products[i].quantity = warehouse->products[i+1].quantity;
            warehouse->products[i].price = warehouse->products[i+1].price;
        }
        warehouse->num_products--;
    }
}

int main() {
    // Creating a warehouse
    struct Warehouse my_warehouse;
    create_warehouse(&my_warehouse, "My Warehouse");

    // Adding products to warehouse
    add_product(&my_warehouse, "Product 1", 100, 10.5);
    add_product(&my_warehouse, "Product 2", 200, 20.5);
    add_product(&my_warehouse, "Product 3", 300, 30.5);

    // Searching product in warehouse
    int index = search_product(my_warehouse, "Product 2");
    if(index != -1) {
        printf("Product Found: %s, Quantity: %d, Price: %.2f\n", 
                my_warehouse.products[index].name, my_warehouse.products[index].quantity, 
                my_warehouse.products[index].price);
    }
    else {
        printf("Product Not Found.\n");
    }

    // Updating product in warehouse
    update_product(&my_warehouse, "Product 2", 50);
    index = search_product(my_warehouse, "Product 2");
    if(index != -1) {
        printf("Product Found: %s, Quantity: %d, Price: %.2f\n", 
                my_warehouse.products[index].name, my_warehouse.products[index].quantity, 
                my_warehouse.products[index].price);
    }
    else {
        printf("Product Not Found.\n");
    }

    // Deleting product from warehouse
    delete_product(&my_warehouse, "Product 2");
    index = search_product(my_warehouse, "Product 2");
    if(index != -1) {
        printf("Product Found: %s, Quantity: %d, Price: %.2f\n", 
                my_warehouse.products[index].name, my_warehouse.products[index].quantity, 
                my_warehouse.products[index].price);
    }
    else {
        printf("Product Not Found.\n");
    }

    return 0;
}