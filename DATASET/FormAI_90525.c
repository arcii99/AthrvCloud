//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

struct Item {
    int id;
    char name[50];
    double price;
    int qty;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct Warehouse* warehouse, int id, char* name, double price, int qty) {
    struct Item item = {id, name, price, qty};
    warehouse->items[warehouse->num_items++] = item;
}

void print_item(struct Item item) {
    printf("%d. %s - $%.2f - Qty: %d\n", item.id, item.name, item.price, item.qty);
}

void print_items(struct Warehouse warehouse) {
    printf("Warehouse Contents:\n");
    for (int i = 0; i < warehouse.num_items; i++) {
        struct Item item = warehouse.items[i];
        print_item(item);
    }
}

void remove_item(struct Warehouse* warehouse, int id) {
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < warehouse->num_items - 1; i++) {
            warehouse->items[i] = warehouse->items[i+1];
        }
        warehouse->num_items--;
    } else {
        printf("Item not found\n");
    }
}

int main() {
    struct Warehouse warehouse = {0};
    add_item(&warehouse, 1, "Shampoo", 4.99, 10);
    add_item(&warehouse, 2, "Soap", 1.99, 20);
    add_item(&warehouse, 3, "Toothpaste", 3.49, 15);
    print_items(warehouse);
    remove_item(&warehouse, 2);
    print_items(warehouse);
    return 0;
}