//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include<stdio.h>
#include<stdlib.h>

#define MAX_ITEMS 100

// Defining the structure for the item
struct item{
    int item_no;
    char item_name[50];
    int item_qty;
};

// Defining the structure for the warehouse
struct warehouse{
    int warehouse_id;
    char warehouse_location[100];
    struct item items[MAX_ITEMS];
};

// Function to add items to the warehouse
void add_item(struct warehouse* w, int item_no, char item_name[50], int item_qty){
    int i = 0;

    // Finding the next available item index for the warehouse
    while (w->items[i].item_no != 0 && i < MAX_ITEMS){
        i++;
    }

    // Adding the item to the warehouse
    w->items[i].item_no = item_no;
    strcpy(w->items[i].item_name, item_name);
    w->items[i].item_qty = item_qty;
}

// Function to remove items from the warehouse
void remove_item(struct warehouse* w, int item_no, int item_qty){
    int i = 0;

    // Finding the item in the warehouse
    while (w->items[i].item_no != item_no && i < MAX_ITEMS){
        i++;
    }

    // Removing the item from the warehouse
    w->items[i].item_qty -= item_qty;
}

// Function to display the contents of the warehouse
void display_warehouse(struct warehouse* w){
    printf("Warehouse ID: %d\n", w->warehouse_id);
    printf("Warehouse Location: %s\n", w->warehouse_location);

    // Displaying the items in the warehouse
    printf("Items:\n");
    for(int i = 0; i < MAX_ITEMS && w->items[i].item_no != 0; i++){
        printf("%d. %s - %d\n", w->items[i].item_no, w->items[i].item_name, w->items[i].item_qty);
    }
}

int main(){
    // Creating a warehouse
    struct warehouse w1;
    w1.warehouse_id = 1;
    strcpy(w1.warehouse_location, "New York");

    // Adding items to the warehouse
    add_item(&w1, 1, "Mobile phone", 10);
    add_item(&w1, 2, "Laptop", 5);

    // Displaying the contents of the warehouse
    display_warehouse(&w1);

    // Removing items from the warehouse
    remove_item(&w1, 1, 3);

    // Displaying the updated contents of the warehouse
    display_warehouse(&w1);

    return 0;
}