//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000

struct Item {
    char name[50];
    int quantity;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct Warehouse *w, const char *name, int quantity) {
    if (w->num_items == MAX_ITEMS) {
        printf("Error: warehouse is full\n");
        return;
    }
    struct Item item = {
        .quantity = quantity
    };
    strncpy(item.name, name, sizeof(item.name) - 1);
    w->items[w->num_items++] = item;
}

void remove_item(struct Warehouse *w, const char *name, int quantity) {
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            if (w->items[i].quantity >= quantity) {
                w->items[i].quantity -= quantity;
                return;
            } else {
                printf("Error: not enough %s in warehouse\n", name);
                return;
            }
        }
    }
    printf("Error: %s not found in warehouse\n", name);
}

void print_items(const struct Warehouse *w) {
    printf("Items in warehouse:\n");
    for (int i = 0; i < w->num_items; i++) {
        printf("%s: %d\n", w->items[i].name, w->items[i].quantity);
    }
}

int main() {
    struct Warehouse w = {
        .num_items = 0
    };
    add_item(&w, "apples", 10);
    add_item(&w, "bananas", 20);
    add_item(&w, "oranges", 15);
    remove_item(&w, "bananas", 5);
    print_items(&w);
    return 0;
}