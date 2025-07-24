//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item
{
    int id;
    char name[30];
    int quantity;
    float price;
};

struct warehouse
{
    struct item items[100];
    int count;
};

void addItem(struct warehouse* w, int id, char* name, int quantity, float price)
{
    struct item i;
    i.id = id;
    strcpy(i.name, name);
    i.quantity = quantity;
    i.price = price;
    w->items[w->count++] = i;
}

void removeItem(struct warehouse* w, int id)
{
    int i;
    for(i = 0; i < w->count; i++)
    {
        if(w->items[i].id == id)
        {
            int j;
            for(j = i; j < w->count - 1; j++)
            {
                w->items[j] = w->items[j+1];
            }
            w->count--;
            break;
        }
    }
}

void displayItems(struct warehouse* w){
    printf("ID\tName\tQuantity\tPrice\n");
    int i;
    for(i=0; i<w->count; i++){
        printf("%d\t%s\t%d\t\t%.2f\n",w->items[i].id,w->items[i].name,w->items[i].quantity,w->items[i].price);
    }
}

int main()
{
    struct warehouse w;
    w.count = 0;

    addItem(&w, 1001, "Shoes", 20, 49.99);
    addItem(&w, 1002, "Shirt", 30, 19.99);
    addItem(&w, 1003, "Pants", 25, 29.99);
    addItem(&w, 1004, "Socks", 50, 4.99);

    displayItems(&w);

    removeItem(&w, 1003);

    displayItems(&w);

    return 0;
}