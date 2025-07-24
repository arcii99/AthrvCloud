//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    int quantity;
    float price;
};

struct warehouse {
    char name[50];
    struct item inventory[100];
    int num_items;
};

int main() {
    struct warehouse warehouse1;
    strcpy(warehouse1.name, "Warehouse 1");
    warehouse1.num_items = 0;

    struct item item1;
    strcpy(item1.name, "Item 1");
    item1.quantity = 50;
    item1.price = 10.99;
    warehouse1.inventory[0] = item1;
    warehouse1.num_items++;

    printf("Welcome to %s\n", warehouse1.name);
    printf("We currently have %d items in stock:\n", warehouse1.num_items);

    for (int i = 0; i < warehouse1.num_items; i++) {
        printf("%d) %s\n", i+1, warehouse1.inventory[i].name);
        printf("   Quantity: %d\n", warehouse1.inventory[i].quantity);
        printf("   Price: $%.2f\n", warehouse1.inventory[i].price);
    }

    struct item item2;
    strcpy(item2.name, "Item 2");
    item2.quantity = 100;
    item2.price = 5.99;
    warehouse1.inventory[1] = item2;
    warehouse1.num_items++;

    printf("\nWe just added %s to our inventory.\n", item2.name);
    printf("We now have %d items in stock:\n", warehouse1.num_items);

    for (int i = 0; i < warehouse1.num_items; i++) {
        printf("%d) %s\n", i+1, warehouse1.inventory[i].name);
        printf("   Quantity: %d\n", warehouse1.inventory[i].quantity);
        printf("   Price: $%.2f\n", warehouse1.inventory[i].price);
    }

    return 0;
}