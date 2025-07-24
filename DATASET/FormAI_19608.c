//FormAI DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

Item database[MAX_ITEMS];

int num_items = 0;

void add_item(Item new_item) {
    if(num_items < MAX_ITEMS) {
        database[num_items] = new_item;
        num_items++;
        printf("Item %s added to database.\n", new_item.name);
    } else {
        printf("Database is full, cannot add new item.\n");
    }
}

void remove_item(int id) {
    int index = -1;
    for(int i = 0; i < num_items; i++) {
        if(database[i].id == id) {
            index = i;
        }
    }
    if(index == -1) {
        printf("Item with id %d not found in database.\n", id);
    } else {
        printf("Item %s removed from database.\n", database[index].name);
        for(int i = index; i < num_items-1; i++) {
            database[i] = database[i+1];
        }
        num_items--;
    }
}

void update_quantity(int id, int new_qty) {
    int index = -1;
    for(int i = 0; i < num_items; i++) {
        if(database[i].id == id) {
            index = i;
        }
    }
    if(index == -1) {
        printf("Item with id %d not found in database.\n", id);
    } else {
        database[index].quantity = new_qty;
        printf("Quantity updated to %d for item %s.\n", new_qty, database[index].name);
    }
}

void print_database() {
    printf("Current database:\n");
    for(int i = 0; i < num_items; i++) {
        printf("ID: %d; Name: %s; Quantity: %d\n", database[i].id, database[i].name, database[i].quantity);
    }
}

int main() {
    printf("Welcome to the Database Simulator!\n\n");

    Item item1 = {1, "Apple", 10};
    add_item(item1);

    Item item2 = {2, "Banana", 15};
    add_item(item2);

    Item item3 = {3, "Orange", 20};
    add_item(item3);

    print_database();

    update_quantity(2, 20);

    remove_item(1);

    print_database();

    return 0;
}