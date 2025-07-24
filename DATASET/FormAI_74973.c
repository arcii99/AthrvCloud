//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char item_name[50];
    int quantity;
    float price;
}Item;

typedef struct {
    char location[100];
    Item items[100];
    int total_items;
    float total_value;
}Warehouse;

void add_item(Warehouse *w, Item newItem) {
    int index = w->total_items;
    w->items[index] = newItem;
    w->total_items++;
    w->total_value += (newItem.price * newItem.quantity);
    printf("A new item has been added to the warehouse.\n");
}

void remove_item(Warehouse *w, char itemName[]) {
    int index = -1;
    for (int i = 0; i < w->total_items; i++) {
        if (strcmp(w->items[i].item_name, itemName) == 0) {
            index = i;
            w->total_value -= (w->items[i].price * w->items[i].quantity);
            break;
        }
    }
    if (index == -1) {
        printf("The item is not available in the warehouse.\n");
    }
    else {
        for (int i = index; i < w->total_items - 1; i++) {
            w->items[i] = w->items[i + 1];
        }
        w->total_items--;
        printf("The item has been removed from the warehouse.\n");
    }
}

void display_stock(Warehouse *w) {
    printf("**********\n");
    printf("Location: %s\n", w->location);
    printf("Total Items: %d\n", w->total_items);
    printf("Total Value: %.2f\n", w->total_value);
    printf("ITEMS\n");
    for (int i = 0; i < w->total_items; i++) {
        printf("%d. %s\t%d\t%.2f\n", i + 1, w->items[i].item_name, w->items[i].quantity, w->items[i].price);
    }
    printf("**********\n");
}

int main() {
    Warehouse w;
    strcpy(w.location, "Main Warehouse");
    w.total_items = 0;
    w.total_value = 0;

    int choice;
    do {
        printf("\nWelcome to the Warehouse Management System!\n");
        printf("Location: %s\n", w.location);
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Stock\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Item newItem;
                printf("Enter the item name: ");
                scanf("%s", newItem.item_name);
                printf("Enter the item quantity: ");
                scanf("%d", &newItem.quantity);
                printf("Enter the item price: ");
                scanf("%f", &newItem.price);
                add_item(&w, newItem);
                break;
            }
            case 2: {
                char itemName[50];
                printf("Enter the item name you want to remove: ");
                scanf("%s", itemName);
                remove_item(&w, itemName);
                break;
            }
            case 3: {
                display_stock(&w);
                break;
            }
            case 4: {
                printf("Thank you for using the Warehouse Management System!\n");
                break;
            }
            default: {
                printf("Invalid choice. Please enter a valid choice.\n");
            }
        }
    } while (choice != 4);
    
    return 0;
}