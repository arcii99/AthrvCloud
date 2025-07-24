//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

typedef struct item{
    int id, qty;
    char name[100];
    float price;
}Item;

typedef struct warehouse{
    char name[100];
    Item items[MAX_SIZE];
    int num_items;
}Warehouse;

Warehouse newWarehouse(char* name){
    Warehouse w;
    strcpy(w.name, name);
    w.num_items = 0;
    return w;
}

void addItem(Warehouse* w_ptr, int id, char* name, int qty, float price){
    Item item = {id, qty, "", price};
    strcpy(item.name, name);
    w_ptr->items[w_ptr->num_items++] = item;
}

void printWarehouse(Warehouse w){
    printf("Warehouse Name: %s\n", w.name);
    printf("Item ID\tItem Name\tQuantity\tPrice\n");
    for(int i = 0; i < w.num_items; i++){
        printf("%d\t%s\t\t%d\t%.2f\n", w.items[i].id, w.items[i].name, w.items[i].qty, w.items[i].price);
    }
}

int main(){
    Warehouse warehouse = newWarehouse("XYZ Warehouse");
    addItem(&warehouse, 1, "Item1", 20, 100.0);
    addItem(&warehouse, 2, "Item2", 10, 200.0);
    addItem(&warehouse, 3, "Item3", 5, 300.0);
    addItem(&warehouse, 4, "Item4", 30, 50.0);

    printWarehouse(warehouse);

    return 0;
}