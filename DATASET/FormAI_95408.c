//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK_SIZE 1000
#define MAX_ITEM_NAME_LENGTH 20

struct Item {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    int price;
};

struct Stock {
    int count;
    struct Item items[MAX_STOCK_SIZE];
};

void initializeStock(struct Stock* stock) {
    stock->count = 0;
}

void addItem(struct Stock* stock, char* name, int quantity, int price) {
    if (stock->count >= MAX_STOCK_SIZE) {
        printf("Warehouse is full\n");
        return;
    }

    struct Item* newItem = &(stock->items[stock->count]);
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    stock->count++;

    printf("Added %d %s(s) costing %d gold each to the Warehouse\n", quantity, name, price);
}

void removeItem(struct Stock* stock, char* name, int quantity) {
    int removed = 0;
    for (int i = 0; i < stock->count; i++) {
        struct Item* currentItem = &(stock->items[i]);
        if (strcmp(currentItem->name, name) == 0) {
            if (currentItem->quantity >= quantity) {
                currentItem->quantity -= quantity;
                printf("Removed %d %s(s) from the Warehouse\n", quantity, name);
                removed = 1;
                break;
            } else {
                printf("Warehouse does not have enough %s(s)\n", name);
                return;
            }
        }
    }

    if (!removed) {
        printf("Warehouse does not have %s\n", name);
    }
}

void printInventory(struct Stock* stock) {
    if (stock->count == 0) {
        printf("Warehouse is empty\n");
        return;
    }

    printf("Warehouse inventory:\n");
    for (int i = 0; i < stock->count; i++) {
        struct Item* currentItem = &(stock->items[i]);
        printf("%s - %d - %d gold each\n", currentItem->name, currentItem->quantity, currentItem->price);
    }
}

int main() {
    struct Stock warehouse;
    initializeStock(&warehouse);

    printf("Welcome to the Dungeon Warehouse Management System\n");
    while (1) {
        printf("Enter a command (add, remove, inventory, exit): ");
        char command[10];
        fgets(command, 10, stdin);

        if (strcmp(command, "add\n") == 0) {
            char name[MAX_ITEM_NAME_LENGTH];
            int quantity, price;
            printf("Enter item name: ");
            fgets(name, MAX_ITEM_NAME_LENGTH, stdin);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            printf("Enter item price: ");
            scanf("%d", &price);
            getchar();  // clear the newline character from the input buffer
            addItem(&warehouse, name, quantity, price);
        } else if (strcmp(command, "remove\n") == 0) {
            char name[MAX_ITEM_NAME_LENGTH];
            int quantity;
            printf("Enter item name: ");
            fgets(name, MAX_ITEM_NAME_LENGTH, stdin);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            getchar();  // clear the newline character from the input buffer
            removeItem(&warehouse, name, quantity);
        } else if (strcmp(command, "inventory\n") == 0) {
            printInventory(&warehouse);
        } else if (strcmp(command, "exit\n") == 0) {
            printf("Farewell, Dungeon Master!\n");
            exit(0);
        } else {
            printf("Invalid command, please try again\n");
        }
    }

    return 0;
}