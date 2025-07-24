//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000 

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
}; 

struct Item inventory[MAX_ITEMS];

int num_items = 0;

void add_item(int id, char *name, int quantity, float price) {
    if (num_items >= MAX_ITEMS) {
        printf("Inventory is full, cannot add more items\n");
        return;
    }
    inventory[num_items].id = id;
    strcpy(inventory[num_items].name, name);
    inventory[num_items].quantity = quantity;
    inventory[num_items].price = price;
    num_items++;
    printf("%s added to inventory\n", name);
}

void remove_item(int id) {
    int item_index = -1;
    for (int i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            item_index = i;
            break;
        }
    }
    if (item_index == -1) {
        printf("Item not found in inventory\n");
        return;
    }
    printf("%s removed from inventory\n", inventory[item_index].name);
    for (int i = item_index; i < num_items - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    num_items--;
}

void display_inventory() {
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, 
               inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void update_quantity(int id, int new_quantity) {
    int item_index = -1;
    for (int i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            item_index = i;
            break;
        }
    }
    if (item_index == -1) {
        printf("Item not found in inventory\n");
        return;
    }
    inventory[item_index].quantity = new_quantity;
    printf("Quantity of %s updated to %d\n", inventory[item_index].name,
           inventory[item_index].quantity);
}

void update_price(int id, float new_price) {
    int item_index = -1;
    for (int i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            item_index = i;
            break;
        }
    }
    if (item_index == -1) {
        printf("Item not found in inventory\n");
        return;
    }
    inventory[item_index].price = new_price;
    printf("Price of %s updated to %.2f\n", inventory[item_index].name,
           inventory[item_index].price);
}

int main() {
    add_item(1001, "Apple", 100, 0.5);
    add_item(1002, "Banana", 75, 0.25);
    add_item(1003, "Orange", 50, 0.75);
    display_inventory();
    remove_item(1002);
    display_inventory();
    update_quantity(1001, 150);
    update_price(1003, 0.50);
    display_inventory();
    return 0;
}