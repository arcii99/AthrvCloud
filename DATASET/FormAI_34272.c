//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to store products
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// define a struct to store warehouse information
typedef struct {
    Product products[100];
    int productCount;
    float totalRevenue;
} Warehouse;

// function to add a new product to the warehouse
void addProduct(Warehouse *warehouse, Product newProduct) {
    warehouse->products[warehouse->productCount] = newProduct;
    warehouse->productCount++;
    printf("Product added to the warehouse!\n");
}

// function to remove a product from the warehouse
void removeProduct(Warehouse *warehouse, int productId) {
    for (int i = 0; i < warehouse->productCount; i++) {
        if (warehouse->products[i].id == productId) {
            for (int j = i; j < warehouse->productCount; j++) {
                warehouse->products[j] = warehouse->products[j+1];
            }
            warehouse->productCount--;
            printf("Product removed from the warehouse!\n");
            return;
        }
    }
    printf("Product not found in the warehouse!\n");
}

// function to update the quantity of a product in the warehouse
void updateQuantity(Warehouse *warehouse, int productId, int newQuantity) {
    for (int i = 0; i < warehouse->productCount; i++) {
        if (warehouse->products[i].id == productId) {
            warehouse->products[i].quantity = newQuantity;
            printf("Product quantity updated!\n");
            return;
        }
    }
    printf("Product not found in the warehouse!\n");
}

// function to calculate the revenue of the warehouse
void calculateRevenue(Warehouse *warehouse) {
    float totalRevenue = 0;
    for (int i = 0; i < warehouse->productCount; i++) {
        totalRevenue += warehouse->products[i].price * warehouse->products[i].quantity;
    }
    warehouse->totalRevenue = totalRevenue;
}

// main function
int main() {
    Warehouse warehouse;
    warehouse.productCount = 0;
    warehouse.totalRevenue = 0;

    // add some products to the warehouse
    Product product1 = {1, "Laptop", 899.99, 10};
    Product product2 = {2, "Smartphone", 499.99, 20};
    Product product3 = {3, "Tablet", 349.99, 15};
    addProduct(&warehouse, product1);
    addProduct(&warehouse, product2);
    addProduct(&warehouse, product3);

    // update the quantity of a product
    updateQuantity(&warehouse, 1, 5);

    // remove a product
    removeProduct(&warehouse, 3);

    // calculate the revenue of the warehouse
    calculateRevenue(&warehouse);
    printf("Total revenue of the warehouse: $%.2f\n", warehouse.totalRevenue);

    return 0;
}