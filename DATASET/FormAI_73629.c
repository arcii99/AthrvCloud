//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM 100
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEM];
    int count;
} Inventory;

Inventory inventory;

void add_item(char *name, int quantity, float price) {
    if (inventory.count >= MAX_ITEM) {
        printf("Warehouse is full!\n");
        return;
    }
    strcpy(inventory.items[inventory.count].name, name);
    inventory.items[inventory.count].quantity = quantity;
    inventory.items[inventory.count].price = price;
    inventory.count++;
}

void sell_item(char *name, int quantity) {
    int i, found = 0;
    float total = 0;
    for (i=0; i<inventory.count; i++) {
        if (strcmp(inventory.items[i].name, name) == 0) {
            found = 1;
            if (inventory.items[i].quantity < quantity) {
                printf("Not enough %s in the warehouse!\n", name);
                return;
            }
            total = inventory.items[i].price * quantity;
            inventory.items[i].quantity -= quantity;
            break;
        }
    }
    if (!found) {
        printf("%s not found in the warehouse!\n", name);
        return;
    }
    printf("Sold %d %s for $%.2f.\n", quantity, name, total);
}

int main() {
    inventory.count = 0;

    add_item("Apples", 50, 1.20);
    add_item("Oranges", 30, 1.50);
    add_item("Pears", 20, 1.80);
    add_item("Bananas", 40, 0.80);

    sell_item("Apples", 20);
    sell_item("Oranges", 40);
    sell_item("Pineapples", 10);

    return 0;
}