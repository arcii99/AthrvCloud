//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_ITEM_NAME 20

typedef struct {
    char name[MAX_ITEM_NAME];
    int count;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(char* name, int count) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Warehouse is full. Cannot add more products.\n");
        return;
    }

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].count += count;
            printf("Added %d items of %s to stock. Total count of %s is now %d.\n", count, name, name, products[i].count);
            return;
        }
    }

    strncpy(products[num_products].name, name, MAX_ITEM_NAME-1);
    products[num_products].count = count;
    printf("Added %d items of %s to stock. Total count of %s is now %d.\n", count, name, name, count);
    num_products++;
}

void remove_product(char* name, int count) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            if (products[i].count < count) {
                printf("Cannot remove %d items of %s. Only %d items are in stock.\n", count, name, products[i].count);
                return;
            }
            products[i].count -= count;
            printf("Removed %d items of %s from stock. Total count of %s is now %d.\n", count, name, name, products[i].count);
            return;
        }
    }

    printf("Product with name %s does not exist in the warehouse.\n", name);
}

void print_products() {
    printf("The following products are in stock:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", products[i].name, products[i].count);
    }
}

int main() {
    // Initialize warehouse with some items
    add_product("banana", 50);
    add_product("apple", 100);
    add_product("orange", 75);

    // Add some more items
    add_product("banana", 25);
    add_product("pineapple", 30);

    // Remove some items
    remove_product("banana", 15);
    remove_product("pear", 20);

    // Print total stock
    print_products();

    return 0;
}