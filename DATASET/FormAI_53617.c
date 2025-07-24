//FormAI DATASET v1.0 Category: Database querying ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

typedef struct {
    Product products[100];
    int count;
} ProductList;

ProductList queryDatabase(const char* query) {
    //Imagine that we have a database of products
    ProductList productList;
    productList.count = 0;

    //Here we could perform some sort of SQL query
    if (strcmp(query, "SELECT * FROM products") == 0) {
        //For this example we just return all products
        productList.count = 3;

        Product product1 = {1, "Apple", 0.50f};
        Product product2 = {2, "Orange", 0.75f};
        Product product3 = {3, "Banana", 0.25f};

        productList.products[0] = product1;
        productList.products[1] = product2;
        productList.products[2] = product3;
    } else if (strcmp(query, "SELECT * FROM products WHERE price < 0.50") == 0) {
        //In this example we return only products that cost less than 50 cents
        productList.count = 2;

        Product product1 = {1, "Apple", 0.50f};
        Product product2 = {3, "Banana", 0.25f};

        productList.products[0] = product1;
        productList.products[1] = product2;
    }

    return productList;
}

int main() {
    //Query all products
    printf("Querying all products:\n");
    ProductList allProducts = queryDatabase("SELECT * FROM products");
    for (int i = 0; i < allProducts.count; i++) {
        printf("%d: %s - $%.2f\n", allProducts.products[i].id, allProducts.products[i].name, allProducts.products[i].price);
    }

    //Query products that cost less than 50 cents
    printf("\nQuerying products that cost less than $0.50:\n");
    ProductList cheapProducts = queryDatabase("SELECT * FROM products WHERE price < 0.50");
    for (int i = 0; i < cheapProducts.count; i++) {
        printf("%d: %s - $%.2f\n", cheapProducts.products[i].id, cheapProducts.products[i].name, cheapProducts.products[i].price);
    }
    
    return 0;
}