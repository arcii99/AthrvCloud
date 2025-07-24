//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

void add_item(Inventory *inv, char name[], int quantity, float price) {
    if (inv->count == MAX_ITEMS) {
        printf("Error: inventory is full\n");
        return;
    }
    strcpy(inv->items[inv->count].name, name);
    inv->items[inv->count].quantity = quantity;
    inv->items[inv->count].price = price;
    inv->count++;
}

void remove_item(Inventory *inv, char name[]) {
    int i, pos = -1;
    for (i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Error: item not found\n");
        return;
    }
    for (i = pos + 1; i < inv->count; i++) {
        inv->items[i - 1] = inv->items[i];
    }
    inv->count--;
}

void print_inventory(Inventory *inv) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inv->count; i++) {
        printf("%s (%d) - $%.2f\n", inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

int main() {
    Inventory inventory;
    inventory.count = 0;
    add_item(&inventory, "Aspirin", 10, 2.5);
    add_item(&inventory, "Tylenol", 5, 3.0);
    add_item(&inventory, "Advil", 3, 2.0);
    add_item(&inventory, "Mucinex", 2, 6.5);
    remove_item(&inventory, "Advil");
    print_inventory(&inventory);
    return 0;
}