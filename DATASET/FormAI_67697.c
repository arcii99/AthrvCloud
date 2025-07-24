//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME 20

typedef struct {
    char name[MAX_ITEM_NAME];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int numItems = 0;

void addItem(char name[], int quantity) {
    if (numItems >= MAX_ITEMS) {
        printf("Error: Inventory is full\n");
        return;
    }

    for (int i = 0; i < numItems; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            inventory[i].quantity += quantity;
            printf("%d %s added to inventory\n", quantity, name);
            return;
        }
    }

    Item newItem;
    strcpy(newItem.name, name);
    newItem.quantity = quantity;
    inventory[numItems++] = newItem;
    printf("%d %s added to inventory\n", quantity, name);
}

void removeItem(char name[], int quantity) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            if (inventory[i].quantity < quantity) {
                printf("Error: Not enough %s in inventory\n", name);
                return;
            }
            inventory[i].quantity -= quantity;
            printf("%d %s removed from inventory\n", quantity, name);
            if (inventory[i].quantity == 0) {
                for (int j = i; j < numItems - 1; j++) {
                    inventory[j] = inventory[j+1];
                }
                numItems--;
                printf("%s removed from inventory\n", name);
            }
            return;
        }
    }
    printf("Error: %s not found in inventory\n", name);
}

void printInventory() {
    printf("Inventory:\n");
    printf("%-20s%-20s\n", "Item", "Quantity");
    for (int i = 0; i < numItems; i++) {
        printf("%-20s%-20d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    addItem("apple", 10);
    addItem("banana", 5);
    printInventory();
    removeItem("apple", 5);
    printInventory();
    addItem("orange", 15);
    printInventory();
    removeItem("grape", 3);
    removeItem("banana", 10);
    printInventory();
    return 0;
}