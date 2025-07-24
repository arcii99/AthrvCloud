//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 20
#define MAX_DESC_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    int quantity;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

int add_item(char* name, char* description, int quantity) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return 0;
    }
    
    Item item;
    item.id = num_items + 1;
    strncpy(item.name, name, MAX_NAME_LENGTH - 1);
    strncpy(item.description, description, MAX_DESC_LENGTH - 1);
    item.quantity = quantity;
    
    items[num_items] = item;
    num_items++;
    
    return item.id;
}

Item* remove_item(int id) {
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == id) {
            Item* item = &(items[i]);
            for (int j = i; j < num_items - 1; j++) {
                items[j] = items[j + 1];
            }
            num_items--;
            return item;
        }
    }
    return NULL;
}

void print_item(Item* item) {
    if (item == NULL) {
        printf("Error: Invalid item.\n");
        return;
    }
    
    printf("ID: %d\nName: %s\nDescription: %s\nQuantity: %d\n\n", item->id, item->name, item->description, item->quantity);
}

void print_all_items() {
    for (int i = 0; i < num_items; i++) {
        print_item(&(items[i]));
    }
}

int main() {
    int id1 = add_item("Item 1", "A description of item 1.", 10);
    int id2 = add_item("Item 2", "A description of item 2.", 5);
    
    printf("Added items with IDs: %d, %d\n\n", id1, id2);
    
    print_all_items();
    
    Item* removed_item = remove_item(id1);
    if (removed_item != NULL) {
        printf("Removed item with ID: %d\n\n", removed_item->id);
    }
    
    print_all_items();
    
    return 0;
}