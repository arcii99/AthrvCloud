//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ORDERS 100

// Struct to hold each menu item
typedef struct MenuItem {
    char name[50];
    int quantity;
    double price;
} MenuItem;

// Struct to hold each order
typedef struct Order {
    int tableNumber;
    MenuItem items[50];
    int numItems;
    double total;
} Order;

// Function to print out the menu
void printMenu(MenuItem menu[], int numItems) {
    printf("\nMENU:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t$%.2f\n", menu[i].name, menu[i].price);
    }
}

// Function to add a new order
void addOrder(Order orders[], int* numOrders, MenuItem menu[], int numItems) {
    // Get the table number
    int tableNum;
    printf("\nEnter table number: ");
    scanf("%d", &tableNum);

    // Get the menu items
    bool done = false;
    int numMenuItems = 0;
    MenuItem items[50];
    while (!done) {
        printf("Enter item name (or 'done' to finish): ");
        char itemName[50];
        scanf("%s", itemName);

        if (strcmp(itemName, "done") == 0) {
            done = true;
        } else {
            // Find the item in the menu
            bool itemFound = false;
            for (int i = 0; i < numItems; i++) {
                if (strcmp(menu[i].name, itemName) == 0) {
                    itemFound = true;

                    // Add the item to the order
                    MenuItem newItem;
                    strcpy(newItem.name, itemName);
                    printf("Enter quantity: ");
                    scanf("%d", &newItem.quantity);
                    newItem.price = menu[i].price;
                    items[numMenuItems] = newItem;
                    numMenuItems++;
                    break;
                }
            }

            if (!itemFound) {
                printf("Invalid item name.\n");
            }
        }
    }

    // Calculate the total for the order
    double orderTotal = 0.0;
    for (int i = 0; i < numMenuItems; i++) {
        orderTotal += items[i].quantity * items[i].price;
    }

    // Add the order to the list
    Order newOrder;
    newOrder.tableNumber = tableNum;
    for (int i = 0; i < numMenuItems; i++) {
        newOrder.items[i] = items[i];
    }
    newOrder.numItems = numMenuItems;
    newOrder.total = orderTotal;
    orders[*numOrders] = newOrder;
    *numOrders += 1;

    printf("\nOrder added.\n");
}

// Function to display all orders
void displayOrders(Order orders[], int numOrders) {
    printf("\nORDERS:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("Table %d:\n", orders[i].tableNumber);
        for (int j = 0; j < orders[i].numItems; j++) {
            printf("\t%s\t%d\t$%.2f\n", orders[i].items[j].name, orders[i].items[j].quantity, orders[i].items[j].price);
        }
        printf("\tTotal: $%.2f\n", orders[i].total);
    }
}

int main() {
    // Set up the menu
    MenuItem menu[5];
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 1.5;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 1.25;
    strcpy(menu[2].name, "Muffin");
    menu[2].price = 2.0;
    strcpy(menu[3].name, "Bagel");
    menu[3].price = 2.5;
    strcpy(menu[4].name, "Croissant");
    menu[4].price = 3.0;

    // Set up the orders
    Order orders[MAX_ORDERS];
    int numOrders = 0;

    // Loop until the user quits
    bool done = false;
    while (!done) {
        printf("\n1. Add Order\n");
        printf("2. Display Orders\n");
        printf("3. Quit\n");
        printf("Enter option number: ");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                printMenu(menu, 5);
                addOrder(orders, &numOrders, menu, 5);
                break;
            case 2:
                displayOrders(orders, numOrders);
                break;
            case 3:
                done = true;
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    printf("\nGoodbye!\n");

    return 0;
}