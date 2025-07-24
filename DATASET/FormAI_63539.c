//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Stock {
    struct Item item;
    int count;
};

struct Warehouse {
    struct Stock inventory[100];
    int size;
};

void addNewItem(struct Warehouse *w, struct Item i, int count) {
    int itemIndex = -1;
    for(int j = 0; j < w->size; j++) {
        if(strcmp(w->inventory[j].item.name, i.name) == 0) {
            itemIndex = j;
            break;
        }
    }
    if(itemIndex != -1) {
        w->inventory[itemIndex].count += count;
    }
    else {
        struct Stock newStock;
        newStock.item = i;
        newStock.count = count;
        w->inventory[w->size] = newStock;
        w->size += 1;
    }
    printf("Successfully added %d units of %s to inventory\n", count, i.name);
}

void removeItem(struct Warehouse *w, struct Item i, int count) {
    int itemIndex = -1;
    for(int j = 0; j < w->size; j++) {
        if(strcmp(w->inventory[j].item.name, i.name) == 0) {
            itemIndex = j;
            break;
        }
    }
    if(itemIndex == -1) {
        printf("%s not found in inventory\n", i.name);
    }
    else if(w->inventory[itemIndex].count < count) {
        printf("Only %d units of %s available in inventory\n", w->inventory[itemIndex].count, i.name);
    }
    else {
        w->inventory[itemIndex].count -= count;
        printf("Successfully removed %d units of %s from inventory\n", count, i.name);
    }
}

void displayInventory(struct Warehouse w) {
    printf("Inventory:\n");
    for(int i = 0; i < w.size; i++) {
        printf("%d units of %s - $%.2f per unit\n", w.inventory[i].count, w.inventory[i].item.name, w.inventory[i].item.price);
    }
}

int main() {
    struct Warehouse warehouse = {0};
    struct Item item1 = {"Apple", 1, 0.5};
    struct Item item2 = {"Banana", 2, 0.25};

    addNewItem(&warehouse, item1, 10); // Add 10 Apples to inventory
    addNewItem(&warehouse, item2, 5); // Add 5 Bananas to inventory
    displayInventory(warehouse); // Display current inventory

    removeItem(&warehouse, item1, 5); // Remove 5 Apples from inventory
    removeItem(&warehouse, item2, 3); // Remove 3 Bananas from inventory
    displayInventory(warehouse); // Display updated inventory

    return 0;
}