//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20
#define ITEM_NAME_LENGTH 50

struct item {
    char name[ITEM_NAME_LENGTH];
    double price;
    int quantity;
};

void print_menu(struct item items[]) {
    printf("\nWelcome to Cafe Biller!\n\n");
    printf("Menu:\n");
    for(int i = 0; i < MAX_ITEMS; i++) {
        if (strlen(items[i].name) > 0) {
            printf("%s\t\t$%.2f\n", items[i].name, items[i].price);
        }
    }
}

void add_item_to_order(struct item items[], char item_name[], int item_quantity, struct item* order[], int order_size) {
    for(int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            struct item* order_item = (struct item*)malloc(sizeof(struct item));
            strcpy(order_item->name, item_name);
            order_item->price = items[i].price;
            order_item->quantity = item_quantity;
            order[order_size] = order_item;
            break;
        }
    }
}

void print_order(struct item* order[], int order_size) {
    printf("\nOrder:\n");
    double total = 0;
    for(int i = 0; i < order_size; i++) {
        struct item* item = order[i];
        double item_total = item->price * item->quantity;
        printf("%s\t%d\t$%.2f\t$%.2f\n", item->name, item->quantity, item->price, item_total);
        total += item_total;
    }
    printf("Total:\t\t\t\t$%.2f\n", total);
}

int main() {
    struct item items[MAX_ITEMS];
    strcpy(items[0].name, "Coffee");
    items[0].price = 2.50;
    items[0].quantity = 100;
    strcpy(items[1].name, "Tea");
    items[1].price = 2.00;
    items[1].quantity = 50;
    strcpy(items[2].name, "Muffin");
    items[2].price = 3.50;
    items[2].quantity = 25;
    struct item* order[MAX_ITEMS];
    int order_size = 0;

    char command[10];
    while(1) {
        print_menu(items);
        printf("\nType 'order' to place an order, or 'exit' to exit: ");
        scanf("%s", command);
        if (strcmp(command, "order") == 0) {
            printf("Enter item name: ");
            char item_name[ITEM_NAME_LENGTH];
            scanf("%s", item_name);
            printf("Enter quantity: ");
            int item_quantity;
            scanf("%d", &item_quantity);
            add_item_to_order(items, item_name, item_quantity, order, order_size);
            order_size++;
        }
        else if (strcmp(command, "exit") == 0) {
            print_order(order, order_size);
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}