//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct warehouseItem{
    int id;
    char name[20];
    int quantity;
    float price;
};

struct warehouse{
    struct warehouseItem items[100];
    int count;
};

void addItem(struct warehouse *w, int id, char name[], int quantity, float price){
    w->items[w->count].id = id;
    strcpy(w->items[w->count].name, name);
    w->items[w->count].quantity = quantity;
    w->items[w->count].price = price;
    w->count++;
}

void removeItem(struct warehouse *w, int id){
    int i, j = 0;
    for(i=0; i<w->count; i++){
        if(w->items[i].id == id){
            j = i;
            break;
        }
    }
    for(i=j; i<w->count-1; i++){
        w->items[i] = w->items[i+1];
    }
    w->count--;
}

void displayItems(struct warehouse *w){
    printf("\nID\tName\t\tQuantity\tPrice");
    int i;
    for(i=0; i<w->count; i++){
        printf("\n%d\t%s\t\t%d\t\t%.2f", w->items[i].id, w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

int main(){
    struct warehouse w;
    w.count = 0;
    addItem(&w, 1, "Shirts", 50, 19.99);
    addItem(&w, 2, "Pants", 75, 29.99);
    addItem(&w, 3, "Shoes", 100, 49.99);
    printf("\nWarehouse Management System");
    displayItems(&w);
    removeItem(&w, 2);
    printf("\n\nAfter removing item with ID 2:");
    displayItems(&w);
    printf("\n\n");
    return 0;
}