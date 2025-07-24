//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    int quantity;
};

struct warehouse {
    struct item items[1000];
    int numItems;
};

void addItem(struct warehouse *w, char *name, int quantity);
void removeItem(struct warehouse *w, char *name, int quantity);
void printInventory(struct warehouse *w);

int main()
{
    struct warehouse w;
    w.numItems = 0;

    addItem(&w, "Apples", 10);
    addItem(&w, "Bananas", 5);
    addItem(&w, "Oranges", 7);
    
    printf("Initial inventory: \n");
    printInventory(&w);
    
    removeItem(&w, "Apples", 4);
    removeItem(&w, "Bananas", 2);
    
    printf("\nAfter removing items: \n");
    printInventory(&w);
    
    return 0;
}

void addItem(struct warehouse *w, char *name, int quantity)
{
    for(int i = 0; i < w->numItems; i++) {
        if(strcmp(w->items[i].name, name) == 0) {
            w->items[i].quantity += quantity;
            return;
        }
    }
    
    struct item newItem;
    strcpy(newItem.name, name);
    newItem.quantity = quantity;
    w->items[w->numItems] = newItem;
    w->numItems++;
}

void removeItem(struct warehouse *w, char *name, int quantity)
{
    for(int i = 0; i < w->numItems; i++) {
        if(strcmp(w->items[i].name, name) == 0) {
            w->items[i].quantity -= quantity;
            if(w->items[i].quantity < 0) {
                w->items[i].quantity = 0;
            }
            return;
        }
    }
}

void printInventory(struct warehouse *w)
{
    printf("Name\t\tQuantity\n");
    for(int i = 0; i < w->numItems; i++) {
        printf("%s\t\t%d\n", w->items[i].name, w->items[i].quantity);
    }
}