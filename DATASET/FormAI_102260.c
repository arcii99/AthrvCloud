//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_PRODUCTS 1000
#define MAX_STOCK 10000

// define product struct
typedef struct product{
    int id;
    char name[50];
    float price;
}Product;

// define stock struct
typedef struct stock{
    int productId;
    int quantity;
}Stock;

// initialize arrays
Product products[MAX_PRODUCTS];
Stock stock[MAX_STOCK];
int numOfProducts = 0, numOfStock = 0;

// function to add a product
void addProduct(int id, char name[], float price){
    // check if product already exists
    for(int i=0; i<numOfProducts; i++){
        if(products[i].id == id){
            printf("Product already exists.\n");
            return;
        }
    }

    // add product
    products[numOfProducts].id = id;
    strcpy(products[numOfProducts].name, name);
    products[numOfProducts].price = price;
    numOfProducts++;
}

// function to add stock
void addStock(int productId, int quantity){
    // check if product already has stock
    for(int i=0; i<numOfStock; i++){
        if(stock[i].productId == productId){
            stock[i].quantity += quantity;
            return;
        }
    }

    // add stock
    stock[numOfStock].productId = productId;
    stock[numOfStock].quantity = quantity;
    numOfStock++;
}

// function to display products
void displayProducts(){
    printf("Products:\n");
    for(int i=0; i<numOfProducts; i++){
        printf("%d. %s - $%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

// function to display stock
void displayStock(){
    printf("Stock:\n");
    for(int i=0; i<numOfStock; i++){
        printf("%d - %d\n", stock[i].productId, stock[i].quantity);
    }
}

int main(){
    // add products
    addProduct(1001, "Phone", 499.99);
    addProduct(1002, "Laptop", 799.99);
    addProduct(1003, "Tablet", 299.99);

    // add stock
    addStock(1001, 10);
    addStock(1002, 5);
    addStock(1003, 20);

    // display products and stock
    displayProducts();
    displayStock();

    return 0;
}