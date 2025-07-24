//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ITEMS 100

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Warehouse;

void add_item(Warehouse *wh, char *name, int quantity, float price) {
    // Check if the item already exists
    int i;
    for (i = 0; i < wh->num_items; i++) {
        if (strcmp(wh->items[i].name, name) == 0) {
            wh->items[i].quantity += quantity;
            wh->items[i].price = price;
            printf("Sherlock Holmes: The item \"%s\" already exists in the warehouse. Quantity increased to %d and price updated to %.2f.\n", name, wh->items[i].quantity, wh->items[i].price);
            return;
        }
    }
    
    // If not, add a new item
    if (wh->num_items >= MAX_ITEMS) {
        printf("Sherlock Holmes: The warehouse is full. Cannot add item \"%s\".\n", name);
        return;
    }
    
    Item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;
    wh->items[wh->num_items] = new_item;
    wh->num_items++;
    printf("Sherlock Holmes: Item \"%s\" successfully added to the warehouse with a quantity of %d and a price of %.2f.\n", name, quantity, price);
}

void remove_item(Warehouse *wh, char *name, int quantity) {
    // Check if the item exists
    int i;
    for (i = 0; i < wh->num_items; i++) {
        if (strcmp(wh->items[i].name, name) == 0) {
            if (wh->items[i].quantity < quantity) {
                printf("Sherlock Holmes: The item \"%s\" only has %d in stock. Cannot remove %d.\n", name, wh->items[i].quantity, quantity);
                return;
            }
            wh->items[i].quantity -= quantity;
            printf("Sherlock Holmes: Successfully removed %d \"%s\" from the warehouse. %d left in stock.\n", quantity, name, wh->items[i].quantity);
            return;
        }
    }
    
    printf("Sherlock Holmes: The item \"%s\" is not in the warehouse.\n", name);
}

void display_items(Warehouse *wh) {
    printf("Sherlock Holmes: Name\t\t Quantity\t Price per unit\n");
    int i;
    for (i = 0; i < wh->num_items; i++) {
        printf("\t%s\t\t %d\t\t $%.2f\n", wh->items[i].name, wh->items[i].quantity, wh->items[i].price);
    }
}

int main() {
    // Initialize the warehouse with some items
    Warehouse wh;
    wh.num_items = 0;
    add_item(&wh, "Lamp", 10, 25.5);
    add_item(&wh, "Chair", 3, 50.0);
    
    // Test the functionality
    add_item(&wh, "Table", 5, 100.0);
    add_item(&wh, "Lamp", 20, 30.0);
    remove_item(&wh, "Chair", 2);
    display_items(&wh);
    
    return 0;
}