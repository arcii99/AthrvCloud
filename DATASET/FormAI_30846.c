//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

struct item {
    int id;
    int quantity;
    char name[50];
};

struct warehouse {
    struct item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct warehouse *w, int id, char *name, int quantity) {
    if (w->num_items >= MAX_ITEMS) {
        printf("Error: warehouse is full\n");
        return;
    }

    struct item new_item = {id, quantity};
    strncpy(new_item.name, name, sizeof(new_item.name) - 1);

    w->items[w->num_items] = new_item;
    w->num_items++;
}

int find_item(struct warehouse *w, int id) {
    for (int i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            return i;
        }
    }
    return -1;
}

void remove_item(struct warehouse *w, int id) {
    int index = find_item(w, id);
    if (index == -1) {
        printf("Error: item not found\n");
        return;
    }

    w->items[index] = w->items[w->num_items-1];
    w->num_items--;
}

void print_items(struct warehouse *w) {
    printf("ID     Name                      Quantity\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < w->num_items; i++) {
        printf("%-6d %-25s %d\n", w->items[i].id, w->items[i].name, w->items[i].quantity);
    }
}

int main() {
    struct warehouse w = {0};

    add_item(&w, 123, "Widget", 50);
    add_item(&w, 456, "Gadget", 20);
    add_item(&w, 789, "Thingamajig", 100);

    print_items(&w);

    remove_item(&w, 123);

    print_items(&w);

    return 0;
}