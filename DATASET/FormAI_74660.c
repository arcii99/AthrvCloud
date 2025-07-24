//FormAI DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20

struct product {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
};

struct inventory {
    struct product items[MAX_ITEMS];
    int size;
};

void add_item(struct inventory *inv, struct product newItem) {
    inv->items[inv->size] = newItem;
    inv->size++;
}

void print_item(struct product item) {
    printf("|%6d | %-20s | %8.2f | %7d |\n", item.id, item.name, item.price, item.quantity);
}

void print_header() {
    printf("+-------+----------------------+----------+---------+\n");
    printf("| ID    | Name                 | Price    | Quantity|\n");
    printf("+-------+----------------------+----------+---------+\n");
}

void print_footer() {
    printf("+-------+----------------------+----------+---------+\n");
}

int get_next_id(struct inventory *inv) {
    int id = 0;
    for (int i = 0; i < inv->size; i++) {
        if (inv->items[i].id > id) {
            id = inv->items[i].id;
        }
    }
    return id + 1;
}

int main() {
    struct inventory inv = { .size = 0 };

    struct product item1 = {
        .id = get_next_id(&inv),
        .name = "Chair",
        .price = 25.0,
        .quantity = 10
    };
    add_item(&inv, item1);
    
    struct product item2 = {
        .id = get_next_id(&inv),
        .name = "Table",
        .price = 50.0,
        .quantity = 5
    };
    add_item(&inv, item2);
    
    struct product item3 = {
        .id = get_next_id(&inv),
        .name = "Lamp",
        .price = 15.0,
        .quantity = 15
    };
    add_item(&inv, item3);

    print_header();
    for (int i = 0; i < inv.size; i++) {
        print_item(inv.items[i]);
    }
    print_footer();

    return 0;
}