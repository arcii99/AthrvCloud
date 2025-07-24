//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[30];
    float price;
    int quantity;
};

struct inventory {
    struct product products[MAX_PRODUCTS];
    int count;
};

void initialize_inventory(struct inventory *inv) {
    inv->count = 0;
}

void add_product(struct inventory *inv, struct product p) {
    if (inv->count < MAX_PRODUCTS) {
        inv->products[inv->count] = p;
        inv->count++;
        printf("Product added successfully.\n");
    } else {
        printf("Inventory is full. Could not add the product.\n");
    }
}

void search_product_by_name(struct inventory *inv, char name[]) {
    int found = 0;
    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            printf("Product found:\n");
            printf("ID       : %d\n", inv->products[i].id);
            printf("Name     : %s\n", inv->products[i].name);
            printf("Price    : %.2f\n", inv->products[i].price);
            printf("Quantity : %d\n", inv->products[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void search_product_by_id(struct inventory *inv, int id) {
    int found = 0;
    for (int i = 0; i < inv->count; i++) {
        if (inv->products[i].id == id) {
            printf("Product found:\n");
            printf("ID       : %d\n", inv->products[i].id);
            printf("Name     : %s\n", inv->products[i].name);
            printf("Price    : %.2f\n", inv->products[i].price);
            printf("Quantity : %d\n", inv->products[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void print_inventory(struct inventory *inv) {
    printf("ID       | Name                      | Price | Quantity\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < inv->count; i++) {
        printf("%-9d| %-25s| %.2f | %d\n", inv->products[i].id, inv->products[i].name, inv->products[i].price, inv->products[i].quantity);
    }
}

int main() {
    struct inventory inv;
    initialize_inventory(&inv);

    struct product p1 = {1, "Product 1", 10.5, 20};
    struct product p2 = {2, "Product 2", 15.75, 15};
    struct product p3 = {3, "Product 3", 5.99, 30};

    add_product(&inv, p1);
    add_product(&inv, p2);
    add_product(&inv, p3);

    search_product_by_name(&inv, "Product 2");
    search_product_by_id(&inv, 3);

    print_inventory(&inv);

    return 0;
}