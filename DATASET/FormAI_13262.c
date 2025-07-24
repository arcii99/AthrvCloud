//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Product struct
struct Product {
    char p_name[50];
    int p_quantity;
    float p_price;
};

// Define Warehouse struct
struct Warehouse {
    char w_name[50];
    struct Product p_list[100];
    int p_count;
};

// Function to add product to warehouse
void add_product(struct Warehouse *w, struct Product p) {
    if (w->p_count == 100) {
        printf("Warehouse is full. Cannot add more products.\n");
    } else {
        w->p_list[w->p_count] = p;
        w->p_count++;
        printf("%s added to %s.\n", p.p_name, w->w_name);
    }
}

// Function to remove product from warehouse
void remove_product(struct Warehouse *w, char *name) {
    int i, index = -1;
    for (i = 0; i < w->p_count; i++) {
        if (strcmp(w->p_list[i].p_name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found in %s.\n", w->w_name);
    } else {
        printf("%s removed from %s.\n", w->p_list[index].p_name, w->w_name);
        // Shift remaining products in array to fill gap
        for (i = index; i < w->p_count - 1; i++) {
            w->p_list[i] = w->p_list[i+1];
        }
        // Decrement product count
        w->p_count--;
    }
}

// Function to display all products in warehouse
void display_products(struct Warehouse *w) {
    int i;
    printf("Products in %s:\n", w->w_name);
    for (i = 0; i < w->p_count; i++) {
        printf("%s - %d - %.2f\n", w->p_list[i].p_name, w->p_list[i].p_quantity, w->p_list[i].p_price);
    }
}

int main() {
    // Create two warehouses
    struct Warehouse w1 = {"Warehouse 1", {}, 0};
    struct Warehouse w2 = {"Warehouse 2", {}, 0};

    // Create products to be added to warehouses
    struct Product p1 = {"Product 1", 10, 4.99};
    struct Product p2 = {"Product 2", 5, 9.99};
    struct Product p3 = {"Product 3", 20, 2.49};
    struct Product p4 = {"Product 4", 3, 19.99};

    // Add products to warehouses
    add_product(&w1, p1);
    add_product(&w1, p2);
    add_product(&w2, p3);
    add_product(&w2, p4);

    // Display products in warehouses
    display_products(&w1);
    display_products(&w2);

    // Remove a product from warehouse 1
    remove_product(&w1, "Product 1");

    // Attempt to remove a product not in warehouse 2
    remove_product(&w2, "Product 5");

    // Display updated products in warehouses
    display_products(&w1);
    display_products(&w2);

    return 0;
}