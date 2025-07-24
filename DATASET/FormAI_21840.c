//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WAREHOUSE_SIZE 100

struct item {
    int id;
    char name[20];
    int quantity;
};

struct warehouse {
    struct item inventory[WAREHOUSE_SIZE];
    int total_items;
};

void print_item(struct item i) {
    printf("Item ID: %d\nItem Name: %s\nQuantity: %d\n", i.id, i.name, i.quantity);
}

void add_item_to_warehouse(struct warehouse* w, char name[20], int quantity) {
    srand(time(NULL));
    int id = rand() % 1000;
    struct item new_item = {id, name, quantity};
    w->inventory[w->total_items] = new_item;
    w->total_items++;
    printf("Successfully added item to the warehouse:\n");
    print_item(new_item);
}

void remove_item_from_warehouse(struct warehouse* w, int id) {
    int index = -1;
    for (int i = 0; i < w->total_items; i++) {
        if (w->inventory[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        struct item removed_item = w->inventory[index];
        for (int i = index; i < w->total_items - 1; i++) {
            w->inventory[i] = w->inventory[i+1];
        }
        w->total_items--;
        printf("Successfully removed item from the warehouse:\n");
        print_item(removed_item);
    } else {
        printf("Item with ID %d not found in the warehouse.\n", id);
    }
}

void print_warehouse(struct warehouse* w) {
    printf("Current warehouse inventory:\n");
    for (int i = 0; i < w->total_items; i++) {
        print_item(w->inventory[i]);
        printf("------------------------\n");
    }
}

int main() {
    struct warehouse w = {{}, 0};
    add_item_to_warehouse(&w, "Surreal Salt", 10);
    add_item_to_warehouse(&w, "Enigmatic Eggs", 20);
    add_item_to_warehouse(&w, "Dreamy Donuts", 15);
    print_warehouse(&w);
    remove_item_from_warehouse(&w, 393);
    print_warehouse(&w);
    return 0;
}