//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_WAREHOUSE_SIZE 1000
#define MAX_ITEM_NAME_LENGTH 20

typedef struct Item {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct Warehouse {
    Item inventory[MAX_WAREHOUSE_SIZE];
    int num_items;
} Warehouse;

void add_item(Warehouse *w, char name[], int quantity, float price) {
    if(w->num_items < MAX_WAREHOUSE_SIZE) {
        strcpy(w->inventory[w->num_items].name, name);
        w->inventory[w->num_items].quantity = quantity;
        w->inventory[w->num_items].price = price;
        w->num_items++;
    }
}

void remove_item(Warehouse *w, int index) {
    if(index < w->num_items && index >= 0) {
        for(int i = index; i < w->num_items-1; i++) {
            w->inventory[i] = w->inventory[i+1];
        }
        w->num_items--;
    }
}

void print_inventory(Warehouse *w) {
    float total = 0;
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Quantity", "Price", "Total");
    for(int i = 0; i < w->num_items; i++) {
        float item_total = w->inventory[i].quantity * w->inventory[i].price;
        printf("%-20s %-10d $%-9.2f $%-9.2f\n", w->inventory[i].name, w->inventory[i].quantity, w->inventory[i].price, item_total);
        total += item_total;
    }
    printf("Total value of inventory: $%.2f\n", total);
}

int main() {
    Warehouse w = {{0}, 0};
    add_item(&w, "Toothpaste", 50, 1.99);
    add_item(&w, "Shampoo", 30, 5.99);
    add_item(&w, "Soap", 100, 0.99);
    add_item(&w, "Deodorant", 25, 3.49);
    printf("Initial inventory:\n");
    print_inventory(&w);
    printf("\nRemoving Soap from inventory...\n");
    remove_item(&w, 2);
    printf("New inventory:\n");
    print_inventory(&w);
    return 0;
}