//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[20];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    float total_value;
} Warehouse;

// Function prototypes
void add_item(Warehouse *w, char *name, int quantity, float price);
void print_items(Warehouse *w);
void remove_item(Warehouse *w, char *name);
void calculate_total_value(Warehouse *w);
void search_item(Warehouse *w, char *name);

int main(void) {
    Warehouse warehouse;
    warehouse.num_items = 0;
    warehouse.total_value = 0.0;

    add_item(&warehouse, "Pen", 50, 0.5);
    add_item(&warehouse, "Pencil", 100, 0.25);
    add_item(&warehouse, "Notebook", 20, 1.5);
    add_item(&warehouse, "Marker", 30, 1.0);

    printf("Initial warehouse state:\n");
    print_items(&warehouse);

    printf("\nRemoving Pencil from warehouse...\n");
    remove_item(&warehouse, "Pencil");

    printf("\nWarehouse state after removal:\n");
    print_items(&warehouse);

    printf("\nCalculating total value of warehouse...\n");
    calculate_total_value(&warehouse);
    printf("Total value of warehouse: $%.2f\n", warehouse.total_value);

    printf("\nSearching for Notebook...\n");
    search_item(&warehouse, "Notebook");

    return 0;
}

void add_item(Warehouse *w, char *name, int quantity, float price) {
    if(w->num_items == MAX_ITEMS) {
        printf("Warehouse is full. Item not added.\n");
        return;
    }

    strcpy(w->items[w->num_items].name, name);
    w->items[w->num_items].quantity = quantity;
    w->items[w->num_items].price = price;

    w->num_items++;
}

void print_items(Warehouse *w) {
    printf("%-10s| %-10s| %-10s\n", "Name", "Quantity", "Price");

    for(int i=0; i<w->num_items; i++) {
        printf("%-10s| %-10d| $%-10.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

void remove_item(Warehouse *w, char *name) {
    int index = -1;

    for(int i=0; i<w->num_items; i++) {
        if(strcmp(w->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Item not found in warehouse. Nothing removed.\n");
        return;
    }

    for(int i=index; i<w->num_items-1; i++) {
        w->items[i] = w->items[i+1];
    }

    w->num_items--;
}

void calculate_total_value(Warehouse *w) {
    float total = 0.0;

    for(int i=0; i<w->num_items; i++) {
        total += w->items[i].quantity * w->items[i].price;
    }

    w->total_value = total;
}

void search_item(Warehouse *w, char *name) {
    int index = -1;

    for(int i=0; i<w->num_items; i++) {
        if(strcmp(w->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Item not found in warehouse.\n");
        return;
    }

    printf("%-10s| %-10s| %-10s\n", "Name", "Quantity", "Price");
    printf("%-10s| %-10d| $%-10.2f\n", w->items[index].name, w->items[index].quantity, w->items[index].price);
}