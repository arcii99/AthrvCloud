//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
} Item;

typedef struct {
    Item items[100];
    int count;
} Inventory;

typedef struct {
    char name[50];
    Inventory* inventory;
} Warehouse;

void add_item(Warehouse* warehouse, char* name, int quantity) {
    for (int i = 0; i < warehouse->inventory->count; i++) {
        if (strcmp(name, warehouse->inventory->items[i].name) == 0) {
            warehouse->inventory->items[i].quantity += quantity;
            printf("%d units of %s added to %s.\n", quantity, name, warehouse->name);
            return;
        }
    }
    if (warehouse->inventory->count >= 100) {
        printf("Error: Warehouse inventory is full.\n");
        return;
    }
    Item item;
    strncpy(item.name, name, sizeof(item.name));
    item.quantity = quantity;
    warehouse->inventory->items[warehouse->inventory->count++] = item;
    printf("%d units of %s added to %s.\n", quantity, name, warehouse->name);
}

void remove_item(Warehouse* warehouse, char* name, int quantity) {
    for (int i = 0; i < warehouse->inventory->count; i++) {
        if (strcmp(name, warehouse->inventory->items[i].name) == 0) {
            if (warehouse->inventory->items[i].quantity >= quantity) {
                warehouse->inventory->items[i].quantity -= quantity;
                printf("%d units of %s removed from %s.\n", quantity, name, warehouse->name);
                if (warehouse->inventory->items[i].quantity == 0) {
                    for (int j = i; j < warehouse->inventory->count - 1; j++) {
                        warehouse->inventory->items[j] = warehouse->inventory->items[j+1];
                    }
                    warehouse->inventory->count--;
                }
            } else {
                printf("Error: Not enough units of %s in %s.\n", name, warehouse->name);
            }
            return;
        }
    }
    printf("Error: %s does not have %s in inventory.\n", warehouse->name, name);
}

void move_item(Warehouse* source, Warehouse* destination, char* name, int quantity) {
    for (int i = 0; i < source->inventory->count; i++) {
        if (strcmp(name, source->inventory->items[i].name) == 0) {
            if (source->inventory->items[i].quantity >= quantity) {
                remove_item(source, name, quantity);
                add_item(destination, name, quantity);
                printf("%d units of %s moved from %s to %s.\n", quantity, name, source->name, destination->name);
            } else {
                printf("Error: Not enough units of %s in %s.\n", name, source->name);
            }
            return;
        }
    }
    printf("Error: %s does not have %s in inventory.\n", source->name, name);
}

int main() {
    Inventory inventory1 = {.count = 0};
    Inventory inventory2 = {.count = 0};
    Warehouse warehouse1 = {.name = "Warehouse 1", .inventory = &inventory1};
    Warehouse warehouse2 = {.name = "Warehouse 2", .inventory = &inventory2};

    add_item(&warehouse1, "Laptop", 10);
    add_item(&warehouse1, "Tablet", 20);
    add_item(&warehouse2, "Laptop", 5);

    remove_item(&warehouse1, "Laptop", 3);
    remove_item(&warehouse1, "Tablet", 25);

    move_item(&warehouse1, &warehouse2, "Laptop", 4);
    move_item(&warehouse2, &warehouse1, "Tablet", 15);
    
    return 0;
}