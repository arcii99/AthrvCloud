//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[30];
    int quantity;
    float price;
};

struct Stock {
    struct Item item;
    int count;
};

struct Warehouse {
    struct Stock storage[50];
    int count;
};

void add_to_stock(struct Warehouse* warehouse, char* name, int quantity, float price) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->storage[i].item.name, name) == 0) {
            warehouse->storage[i].count += quantity;
            return;
        }
    }
    struct Item item;
    strcpy(item.name, name);
    item.quantity = quantity;
    item.price = price;
    struct Stock stock = {item, quantity};
    warehouse->storage[warehouse->count] = stock;
    warehouse->count++;
}

void remove_from_stock(struct Warehouse* warehouse, char* name, int quantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->storage[i].item.name, name) == 0) {
            warehouse->storage[i].count -= quantity;
            if (warehouse->storage[i].count < 0) {
                warehouse->storage[i].count = 0;
            }
            return;
        }
    }
}

void print_item(struct Item item) {
    printf("%-30s%d\t%f\n", item.name, item.quantity, item.price);
}

void print_stock(struct Stock stock) {
    print_item(stock.item);
    printf("Count: %d\n", stock.count);
}

void display_stock(struct Warehouse warehouse) {
    printf("%-30s%s\t%s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < warehouse.count; i++) {
        print_item(warehouse.storage[i].item);
        printf("Total Count: %d\n", warehouse.storage[i].count);
    }
}

int main() {
    struct Warehouse warehouse = {{0}, 0};
    add_to_stock(&warehouse, "Apple", 10, 5.99);
    add_to_stock(&warehouse, "Banana", 20, 2.99);
    add_to_stock(&warehouse, "Orange", 15, 3.99);
    display_stock(warehouse);

    remove_from_stock(&warehouse, "Apple", 5);
    printf("\nAfter sale:\n");
    display_stock(warehouse);
    return 0;
}