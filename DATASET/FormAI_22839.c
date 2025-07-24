//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCT 50
#define MAX_ITEM 1000

typedef struct Product {
    int id;
    char name[100];
    int quantity;
} Product;

typedef struct Item {
    Product product;
    int quantity;
} Item;

typedef struct Warehouse {
    Item items[MAX_ITEM];
    int num_items;
} Warehouse;

void add_product(Warehouse* warehouse, Product product) {
    if (warehouse->num_items == MAX_ITEM) {
        printf("The warehouse is full.\n");
        return;
    }

    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].product.id == product.id) {
            printf("Product with ID %d already exists.\n", product.id);
            return;
        }
    }

    Item item = { product, 0 };
    warehouse->items[warehouse->num_items++] = item;
    printf("Product '%s' with ID %d added successfully.\n", product.name, product.id);
}

void add_item(Warehouse* warehouse, int id, int quantity) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].product.id == id) {
            warehouse->items[i].quantity += quantity;
            printf("%d %s(s) added to warehouse.\n", quantity, warehouse->items[i].product.name);
            return;
        }
    }

    printf("Product with ID %d does not exist.\n", id);
}

void remove_item(Warehouse* warehouse, int id, int quantity) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].product.id == id) {
            Item* item = &warehouse->items[i];

            if (item->quantity < quantity) {
                printf("Not enough %s(s) to remove.\n", item->product.name);
                return;
            }

            item->quantity -= quantity;
            printf("%d %s(s) removed from warehouse.\n", quantity, item->product.name);

            if (item->quantity == 0) {
                for (int j = i; j < warehouse->num_items - 1; j++) {
                    warehouse->items[j] = warehouse->items[j + 1];
                }
                warehouse->num_items--;
                printf("Product '%s' with ID %d removed from warehouse.\n", item->product.name, item->product.id);
            }

            return;
        }
    }

    printf("Product with ID %d does not exist.\n", id);
}

void print_inventory(Warehouse* warehouse) {
    printf("Current Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        Item item = warehouse->items[i];
        printf("- %d %s (ID: %d)\n", item.quantity, item.product.name, item.product.id);
    }
    printf("End of Inventory.\n");
}

int main() {
    Warehouse warehouse = { 0 };

    Product p1 = { 1, "Banana", 0 };
    Product p2 = { 2, "Apple", 0 };
    Product p3 = { 3, "Orange", 0 };

    add_product(&warehouse, p1);
    add_product(&warehouse, p2);
    add_product(&warehouse, p3);

    add_item(&warehouse, 1, 10);
    add_item(&warehouse, 2, 5);
    add_item(&warehouse, 4, 3);

    print_inventory(&warehouse);

    remove_item(&warehouse, 1, 5);
    remove_item(&warehouse, 2, 10);

    print_inventory(&warehouse);

    return 0;
}