//FormAI DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    float price;
    char name[50];
} Product;

int main() {
    // create an array of products
    Product products[5] = {
        {1, 50.99, "Product A"},
        {2, 25.99, "Product B"},
        {3, 75.99, "Product C"},
        {4, 10.99, "Product D"},
        {5, 39.99, "Product E"}
    };

    // calculate the total price of all products
    float total_price = 0;
    for(int i = 0; i < 5; i++) {
        total_price += products[i].price;
    }

    printf("Total price of all products: $%.2f\n", total_price);

    // find the product with the highest price
    Product max_product = products[0];
    for(int i = 1; i < 5; i++) {
        if(products[i].price > max_product.price) {
            max_product = products[i];
        }
    }

    printf("Product with highest price: %s\n", max_product.name);

    // calculate the average price of all products
    float avg_price = total_price / 5;
    printf("Average price of all products: $%.2f\n", avg_price);

    // find all products with price greater than the average price
    printf("Products with price greater than average:\n");
    for(int i = 0; i < 5; i++) {
        if(products[i].price > avg_price) {
            printf("- %s\n", products[i].name);
        }
    }

    return 0;
}