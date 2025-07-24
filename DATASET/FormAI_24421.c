//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

void printInventory(Inventory inventory) {
    printf("Name\t\tQuantity\tPrice\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < inventory.count; i++) {
        printf("%s\t\t%d\t\t%.2f\n", inventory.items[i].name, inventory.items[i].quantity, inventory.items[i].price);
    }
    printf("\n");
}

void addItem(Inventory* inventory, char name[], int quantity, float price) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full, cannot add item.\n");
        return;
    }

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            inventory->items[i].quantity += quantity;
            printf("Added %d %s to inventory.\n", quantity, name);
            return;
        }
    }

    Item item;
    strcpy(item.name, name);
    item.quantity = quantity;
    item.price = price;

    inventory->items[inventory->count++] = item;
    printf("Added %d %s to inventory.\n", quantity, name);
}

void removeItem(Inventory* inventory, char name[], int quantity) {
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            if (inventory->items[i].quantity < quantity) {
                printf("Cannot remove %d %s from inventory, not enough in stock.\n", quantity, name);
                return;
            }
            inventory->items[i].quantity -= quantity;
            printf("Removed %d %s from inventory.\n", quantity, name);
            return;
        }
    }
    printf("%s not found in inventory.\n", name);
}

int main() {
    Inventory inventory;
    inventory.count = 0;

    addItem(&inventory, "hammer", 10, 5.99);
    addItem(&inventory, "screwdriver", 15, 3.99);
    addItem(&inventory, "nails", 100, 0.99);
    addItem(&inventory, "screws", 150, 1.99);
    addItem(&inventory, "wrench", 5, 9.99);

    printf("\n");
    printInventory(inventory);

    removeItem(&inventory, "hammer", 5);
    removeItem(&inventory, "screwdriver", 20);

    printf("\n");
    printInventory(inventory);

    return 0;
}