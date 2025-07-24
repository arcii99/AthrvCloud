//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

struct item {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
};

struct warehouse {
    struct item inventory[MAX_ITEMS];
    int num_items;
};

void add_item(struct warehouse *w, char name[], int quantity, float price) {
    if (w->num_items < MAX_ITEMS) {
        struct item new_item;
        strcpy(new_item.name, name);
        new_item.quantity = quantity;
        new_item.price = price;
        w->inventory[w->num_items] = new_item;
        w->num_items++;
        printf("%s added to inventory.\n", name);
    } else {
        printf("Warehouse is full, cannot add %s.\n", name);
    }
}

void remove_item(struct warehouse *w, char name[]) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->inventory[i].name, name) == 0) {
            printf("Removing %s from inventory.\n", name);
            for (; i < w->num_items-1; i++) {
                w->inventory[i] = w->inventory[i+1];
            }
            w->num_items--;
            return;
        }
    }
    printf("Item %s not found in inventory.\n", name);
}

void print_inventory(struct warehouse *w) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < w->num_items; i++) {
        printf("%s (quantity: %d, price: %.2f)\n", w->inventory[i].name, w->inventory[i].quantity, w->inventory[i].price);
    }
}

int main() {
    struct warehouse w;
    w.num_items = 0;

    // Add some items to inventory
    add_item(&w, "Widget", 10, 1.99);
    add_item(&w, "Gizmo", 5, 2.99);

    // Print inventory
    print_inventory(&w);

    // Remove an item from inventory
    remove_item(&w, "Widget");

    // Print inventory again
    print_inventory(&w);

    return 0;
}