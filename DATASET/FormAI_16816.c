//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 1000 // maximum number of items supported by the warehouse

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Warehouse {
    char name[50];
    int num_items;
    struct Item items[MAX_ITEMS];
};

int add_item(struct Warehouse *w, char *name, int quantity, float price) {
    if (w->num_items >= MAX_ITEMS) {
        return -1; // cannot add any more items
    }
    strcpy(w->items[w->num_items].name, name);
    w->items[w->num_items].quantity = quantity;
    w->items[w->num_items].price = price;
    w->num_items++;
    return 0;
}

int remove_item(struct Warehouse *w, char *name, int quantity) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            if (w->items[i].quantity >= quantity) {
                w->items[i].quantity -= quantity;
                return 0;
            } else {
                return -1; // not enough quantity to remove
            }
        }
    }
    return -1; // item not found
}

void list_items(struct Warehouse *w) {
    printf("List of items in the warehouse \"%s\":\n", w->name);
    printf("%-30s %-10s %-10s\n", "Name", "Quantity", "Price");
    int i;
    for (i = 0; i < w->num_items; i++) {
        printf("%-30s %-10d %-10.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

int main() {
    struct Warehouse w1 = {"Warehouse 1", 0};
    add_item(&w1, "Item A", 100, 9.99);
    add_item(&w1, "Item B", 50, 14.99);
    add_item(&w1, "Item C", 200, 4.99);
    list_items(&w1);
    printf("\n");
    remove_item(&w1, "Item A", 50);
    list_items(&w1);
    printf("\n");
    remove_item(&w1, "Item A", 75);
    list_items(&w1);
    return 0;
}