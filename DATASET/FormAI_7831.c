//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    double cost;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item(Item new_item) {
    if(num_items >= MAX_ITEMS) {
        printf("Inventory is full\n");
        return;
    }
    
    int i;
    for(i = 0; i < num_items; i++) {
        if(strcmp(inventory[i].name, new_item.name) == 0) {
            inventory[i].quantity += new_item.quantity;
            return;
        }
    }
    
    inventory[num_items] = new_item;
    num_items++;
}

void remove_item(char *item_name, int quantity) {
    int i;
    for(i = 0; i < num_items; i++) {
        if(strcmp(inventory[i].name, item_name) == 0) {
            if(inventory[i].quantity < quantity)
                printf("Not enough %s in inventory\n", item_name);
            else {
                inventory[i].quantity -= quantity;
                printf("%d %s removed from inventory\n", quantity, item_name);
            }
            
            return;
        }
    }
    
    printf("%s not found in inventory\n", item_name);
}

void print_inventory() {
    int i;
    printf("Name\tQuantity\tCost\n");
    
    for(i = 0; i < num_items; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].cost);
    }
}

int main() {
    Item new_item;
    strcpy(new_item.name, "Bolt");
    new_item.quantity = 100;
    new_item.cost = 0.25;
    add_item(new_item);
    
    strcpy(new_item.name, "Nut");
    new_item.quantity = 200;
    new_item.cost = 0.10;
    add_item(new_item);
    
    remove_item("Bolt", 50);
    remove_item("Washer", 5);
    
    print_inventory();
    
    return 0;
}