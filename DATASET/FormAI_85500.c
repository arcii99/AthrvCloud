//FormAI DATASET v1.0 Category: Database querying ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

void print_product(Product p) {
    printf("[ID: %d, Name: %s, Price: $%.2f]\n", p.id, p.name, p.price);
}

void print_products(Product *arr, int count) {
    for (int i = 0; i < count; i++) {
        print_product(arr[i]);
    }
}

int main() {
    // Initialize products
    Product products[] = {
        {1, "Apple", 0.99},
        {2, "Banana", 0.50},
        {3, "Orange", 1.20},
        {4, "Mango", 2.50},
        {5, "Pineapple", 3.99}
    };

    int num_products = sizeof(products) / sizeof(Product);

    // Print all products
    printf("All Products:\n");
    print_products(products, num_products);

    // Query products by price
    float min_price = 1.00;
    printf("\nProducts with a price greater than $%.2f:\n", min_price);
    for (int i = 0; i < num_products; i++) {
        if (products[i].price > min_price) {
            print_product(products[i]);
        }
    }

    // Query products by name
    char search_name[50] = "mango";
    printf("\nProducts with a name containing \"%s\":\n", search_name);
    for (int i = 0; i < num_products; i++) {
        if (strstr(products[i].name, search_name) != NULL) {
            print_product(products[i]);
        }
    }

    // Query products by ID
    int search_id = 2;
    printf("\nThe product with ID %d:\n", search_id);
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == search_id) {
            print_product(products[i]);
            break;
        }
    }

    return 0;
}