//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_SIZE 50

// Struct to define an item in the warehouse
typedef struct {
    char name[MAX_NAME_SIZE];
    int quantity;
    float price;
} Item;

// Array of items in the warehouse
Item items[MAX_ITEMS];
int num_items = 0;

// Function to add an item to the warehouse
void add_item(char* name, int quantity, float price) {
    if(num_items < MAX_ITEMS) {
        strcpy(items[num_items].name, name);
        items[num_items].quantity = quantity;
        items[num_items].price = price;
        num_items++;
    }
    else {
        printf("Warehouse is full!\n");
    }
}

// Function to find an item in the warehouse by name
int find_item(char* name) {
    int i;
    for(i = 0; i < num_items; i++) {
        if(strcmp(name, items[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to remove an item from the warehouse
void remove_item(char* name, int quantity) {
    int index = find_item(name);
    if(index != -1) {
        items[index].quantity -= quantity;
    }
    else {
        printf("Item not found!\n");
    }
}

// Function to display all items in the warehouse
void display_items() {
    int i;
    for(i = 0; i < num_items; i++) {
        printf("%s: %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    add_item("Apples", 10, 0.50);
    add_item("Bananas", 20, 0.25);
    add_item("Oranges", 15, 0.75);

    display_items();

    remove_item("Apples", 5);

    display_items();

    return 0;
}