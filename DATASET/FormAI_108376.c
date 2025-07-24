//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME 50

struct Item {
    char name[MAX_NAME];
    int quantity;
    float price;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int count;
};

void printMenu() {
    printf("       Warehouse Management System       \n");
    printf("-----------------------------------------\n");
    printf("1. Add item\n");
    printf("2. Show inventory\n");
    printf("3. Search item\n");
    printf("4. Exit\n");
}

void addItem(struct Warehouse *warehouse) {
    char name[MAX_NAME];
    int quantity;
    float price;

    printf("Enter item name : ");
    scanf("%s", name);
    printf("Enter item quantity : ");
    scanf("%d", &quantity);
    printf("Enter item price : ");
    scanf("%f", &price);

    struct Item item = { .quantity = quantity, .price = price };
    strncpy(item.name, name, MAX_NAME);

    warehouse->items[warehouse->count++] = item;

    printf("Item added to warehouse successfully.\n");
}

void showInventory(const struct Warehouse *warehouse) {
    printf("       Inventory       \n");
    printf("------------------------\n");
    printf("%-20s%-10s%s\n", "Name", "Quantity", "Price");

    if (warehouse->count == 0) {
        printf("No items in warehouse.\n");
        return;
    }

    float totalValue = 0;

    for (int i = 0; i < warehouse->count; i++) {
        const struct Item *item = &warehouse->items[i];
        printf("%-20s%-10d%.2f\n", item->name, item->quantity, item->price);

        totalValue += item->quantity * item->price;
    }

    printf("\nTotal value of inventory : %.2f\n", totalValue);
}

void searchItem(const struct Warehouse *warehouse) {
    char name[MAX_NAME];

    printf("Enter item name to search: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->count; i++) {
        const struct Item *item = &warehouse->items[i];

        if (strncmp(item->name, name, MAX_NAME) == 0) {
            printf("Item found in inventory.\n");
            printf("%-20s%-10s%s\n", "Name", "Quantity", "Price");
            printf("%-20s%-10d%.2f\n", item->name, item->quantity, item->price);
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

int main() {
    struct Warehouse warehouse;
    warehouse.count = 0;

    int choice;

    do {
        printMenu();
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                addItem(&warehouse);
                break;
            }
            case 2: {
                showInventory(&warehouse);
                break;
            }
            case 3: {
                searchItem(&warehouse);
                break;
            }
            case 4: {
                printf("Exiting Warehouse Management System...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }

        printf("\n");

    } while (1);

    return 0;
}