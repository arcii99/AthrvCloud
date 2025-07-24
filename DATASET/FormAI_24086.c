//FormAI DATASET v1.0 Category: Database querying ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_SIZE 100

struct product {
    char name[50];
    float price;
    int quantity;
};

struct database {
    struct product products[DATABASE_SIZE];
    int size;
};

void add_product(struct database *db, char *name, float price, int quantity) {
    if(db->size >= DATABASE_SIZE) {
        printf("Database full\n");
        return;
    }

    struct product new_product;
    strcpy(new_product.name, name);
    new_product.price = price;
    new_product.quantity = quantity;

    db->products[db->size++] = new_product;
    printf("Product added successfully\n");
}

void display_products(struct database *db) {
    printf("Products in database:\n");
    for(int i = 0; i < db->size; i++) {
        printf("%d. Name: %s | Price: %.2f | Quantity: %d\n", i+1, db->products[i].name, db->products[i].price, db->products[i].quantity);
    }
}

int main() {
    struct database db;
    db.size = 0;

    add_product(&db, "Coke", 1.25, 100);
    add_product(&db, "Chips", 0.75, 200);
    add_product(&db, "Chocolate", 2.00, 50);
    display_products(&db);

    return 0;
}