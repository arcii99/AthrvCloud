//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Warehouse {
    struct Item items[100];
    int num_items;
};

void initialize_warehouse(struct Warehouse* w) {
    w->num_items = 0;
}

void add_item(struct Warehouse* w, char* name, int quantity, float price) {
    struct Item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;
    w->items[w->num_items] = new_item;
    w->num_items++;
    printf("Added %d %s @ $%.2f to warehouse\n", quantity, name, price);
}

void remove_item(struct Warehouse* w, char* name, int quantity) {
    int found = 0;
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            if (w->items[i].quantity >= quantity) {
                w->items[i].quantity -= quantity;
                printf("Removed %d %s from warehouse\n", quantity, name);
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("Item not found in warehouse\n");
    }
}

void print_items(struct Warehouse* w) {
    printf("Warehouse contains:\n");
    for (int i = 0; i < w->num_items; i++) {
        printf("%d %s @ $%.2f each\n", w->items[i].quantity, w->items[i].name, w->items[i].price);
    }
}

int main() {
    struct Warehouse w;
    initialize_warehouse(&w);

    add_item(&w, "Plasma Rifle", 10, 5000.00);
    add_item(&w, "Power Armor", 5, 10000.00);
    add_item(&w, "Nuka-Cola", 50, 1.50);
    print_items(&w);

    remove_item(&w, "Plasma Rifle", 5);
    print_items(&w);

    remove_item(&w, "Sniper Rifle", 1);
    print_items(&w);

    return 0;
}