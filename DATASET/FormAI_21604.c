//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>

//Struct for storing product information.
typedef struct {
    int product_id;
    char product_name[20];
    int quantity;
} Product;

//Struct for storing warehouse information.
typedef struct {
    int warehouse_id;
    char warehouse_name[20];
    Product products[100];
} Warehouse;

//Function for adding a product to the warehouse.
void add_product(Product *product, Warehouse *warehouse) {
    for (int i = 0; i < 100; i++) {
        if (warehouse->products[i].product_id == -1) {
            warehouse->products[i] = *product;
            printf("Product added successfully!\n");
            return;
        }
    }
    printf("Warehouse is full! Product cannot be added.\n");
}

//Function for removing a product from the warehouse.
void remove_product(int product_id, Warehouse *warehouse) {
    for (int i = 0; i < 100; i++) {
        if (warehouse->products[i].product_id == product_id) {
            warehouse->products[i].product_id = -1;
            printf("Product removed successfully!\n");
            return;
        }
    }
    printf("Product not found in warehouse.\n");
}

//Function for updating product quantity in the warehouse.
void update_quantity(int product_id, int quantity, Warehouse *warehouse) {
    for (int i = 0; i < 100; i++) {
        if (warehouse->products[i].product_id == product_id) {
            warehouse->products[i].quantity = quantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Product not found in warehouse.\n");
}

int main() {
    Warehouse warehouse1 = {1, "Central Warehouse"};
    Product product1 = {101, "Shoes", 50};
    Product product2 = {102, "Shirts", 100};
    Product product3 = {103, "Pants", 75};

    //Adding products to warehouse1.
    add_product(&product1, &warehouse1);
    add_product(&product2, &warehouse1);
    add_product(&product3, &warehouse1);

    //Updating quantity of product2 in warehouse1.
    update_quantity(102, 125, &warehouse1);

    //Removing product1 from warehouse1.
    remove_product(101, &warehouse1);

    //Printing the final product and warehouse information.
    printf("\nWarehouse ID: %d\n", warehouse1.warehouse_id);
    printf("Warehouse Name: %s\n\n", warehouse1.warehouse_name);
    for (int i = 0; i < 100; i++) {
        if (warehouse1.products[i].product_id != -1) {
            printf("Product ID: %d\n", warehouse1.products[i].product_id);
            printf("Product Name: %s\n", warehouse1.products[i].product_name);
            printf("Quantity: %d\n\n", warehouse1.products[i].quantity);
        }
    }

    return 0;
}