//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct Item{
    int id;
    char name[50];
    int quantity;
}Item;

typedef struct Warehouse{
    Item items[MAX_ITEMS];
    int count;
}Warehouse;

// Function to add item to warehouse
void addItem(Warehouse *warehouse, Item item){
    if(warehouse->count == MAX_ITEMS){
        printf("Warehouse is full\n");
        return;
    }
    
    warehouse->items[warehouse->count] = item;
    warehouse->count++;
}

// Function to remove item from warehouse by id
void removeItem(Warehouse *warehouse, int id){
    int i, index = -1;
    
    // Find item index
    for(i=0; i<warehouse->count; i++){
        if(warehouse->items[i].id == id){
            index = i;
            break;
        }
    }
    
    if(index == -1){
        printf("Item not found\n");
        return;
    }
    
    // Shift items
    for(i=index+1; i<warehouse->count; i++){
        warehouse->items[i-1] = warehouse->items[i];
    }
    
    warehouse->count--;
    printf("Item removed from warehouse\n");
}

// Function to display items in warehouse
void displayItems(Warehouse warehouse){
    int i;
    
    printf("Warehouse Items:\n");
    if(warehouse.count == 0){
        printf("Empty\n");
    }
    else{
        for(i=0; i<warehouse.count; i++){
            printf("Id: %d, Name: %s, Quantity: %d\n", warehouse.items[i].id, warehouse.items[i].name, warehouse.items[i].quantity);
        }
    }
}

int main(){
    // Initialize warehouse
    Warehouse wh;
    wh.count = 0;
    
    // Add items
    Item item1 = {1, "Pencil", 100};
    addItem(&wh, item1);
    
    Item item2 = {2, "Pen", 50};
    addItem(&wh, item2);
    
    Item item3 = {3, "Notebook", 200};
    addItem(&wh, item3);
    
    // Display items
    displayItems(wh);
    
    // Remove item
    removeItem(&wh, 2);
    
    // Display items again
    displayItems(wh);
    
    return 0;
}