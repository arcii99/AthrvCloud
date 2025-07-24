//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int quantity;
} Item;

typedef struct {
    int id;
    Item *items;
    int num_items;
} Warehouse;

int main() {
    Warehouse warehouse;
    warehouse.id = 1001;
    warehouse.num_items = 0;
    printf("Welcome to Warehouse #%d!\n", warehouse.id);
    printf("Please enter the number of items to add: ");
    scanf("%d", &warehouse.num_items);
    warehouse.items = (Item *) malloc(sizeof(Item) * warehouse.num_items);
    printf("Great! Now let's add %d items:\n", warehouse.num_items);
    for (int i = 0; i < warehouse.num_items; ++i) {
        printf("Item #%d name: ", i+1);
        scanf("%s", warehouse.items[i].name);
        printf("Item #%d quantity: ", i+1);
        scanf("%d", &warehouse.items[i].quantity);
    }
    printf("All items added successfully!\n");
    printf("Here's what we have in stock:\n");
    for (int i = 0; i < warehouse.num_items; ++i) {
        printf("%d %s\n", warehouse.items[i].quantity, warehouse.items[i].name);
    }
    free(warehouse.items);
    printf("Thank you for using our Warehouse Management System. Have a great day!\n");
    return 0;
}