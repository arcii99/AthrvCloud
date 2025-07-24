//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include<stdio.h>
#include<string.h>

/*defining item structure*/
typedef struct {
    char item_name[20];
    int quantity;
    float cost_price;
    float selling_price;
} ITEM;

/*defining warehouse structure*/
typedef struct {
    char warehouse_name[20];
    ITEM items[50];
    int num_items;
} WAREHOUSE;

/*function to add item to warehouse*/
void addItemToWarehouse(ITEM item, WAREHOUSE *warehouse) {
    int i;
    for (i=0; i<warehouse->num_items; i++) {
        /*if item already exists, update quantity*/
        if (strcmp(item.item_name, warehouse->items[i].item_name) == 0) {
            warehouse->items[i].quantity += item.quantity;
            return;
        }
    }
    /*if item doesn't exist, add item to warehouse*/
    strcpy(warehouse->items[warehouse->num_items].item_name, item.item_name);
    warehouse->items[warehouse->num_items].quantity = item.quantity;
    warehouse->items[warehouse->num_items].cost_price = item.cost_price;
    warehouse->items[warehouse->num_items].selling_price = item.selling_price;
    warehouse->num_items++;
}

/*function to remove item from warehouse*/
void removeItemFromWarehouse(char *item_name, WAREHOUSE *warehouse) {
    int i;
    for (i=0; i<warehouse->num_items; i++) {
        /*if item found, remove item*/
        if (strcmp(item_name, warehouse->items[i].item_name) == 0) {
            warehouse->num_items--;
            for (; i<warehouse->num_items; i++) {
                warehouse->items[i] = warehouse->items[i+1];
            }
            return;
        }
    }
}

/*function to display all items in warehouse*/
void displayWarehouseItems(WAREHOUSE warehouse) {
    int i;
    printf("\n%-20s%-10s%-15s%-15s\n", "Item Name", "Quantity", "Cost Price", "Selling Price");
    for (i=0; i<warehouse.num_items; i++) {
        printf("%-20s%-10d%-15.2f%-15.2f\n", warehouse.items[i].item_name, warehouse.items[i].quantity, warehouse.items[i].cost_price, warehouse.items[i].selling_price);
    }
}

/*main function*/
int main() {
    WAREHOUSE warehouse;
    strcpy(warehouse.warehouse_name, "My Warehouse");
    warehouse.num_items = 0;

    ITEM item1 = {"Apple", 100, 1.50, 2.00};
    addItemToWarehouse(item1, &warehouse);

    ITEM item2 = {"Banana", 200, 1.00, 1.50};
    addItemToWarehouse(item2, &warehouse);

    ITEM item3 = {"Grapes", 50, 2.00, 2.50};
    addItemToWarehouse(item3, &warehouse);

    ITEM item4 = {"Apple", 50, 1.50, 2.00};
    addItemToWarehouse(item4, &warehouse);

    removeItemFromWarehouse("Banana", &warehouse);

    displayWarehouseItems(warehouse);

    return 0;
}