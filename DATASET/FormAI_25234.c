//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20

// Structure to store the menu items
typedef struct MenuItem {
    char name[50];
    float price;
} MenuItem;

// Array to store the menu items
MenuItem menu[MAX_ITEMS];

// Global variable to keep track of the number of items on the menu
int numItems = 0;

// Function to add a new item to the menu
void addItem(char *name, float price) {
    if (numItems >= MAX_ITEMS) {
        printf("Sorry! Cannot add more items to the menu.\n");
    } else {
        MenuItem newItem;
        strcpy(newItem.name, name);
        newItem.price = price;
        menu[numItems++] = newItem;
        printf("%s added to the menu.\n", name);
    }
}

// Function to display the menu
void displayMenu() {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to get the total bill amount
float getTotal(int *items, int numItems) {
    float total = 0;
    for (int i = 0; i < numItems; i++) {
        total += menu[items[i]-1].price;
    }
    return total;
}

int main() {
    printf("Welcome to Cryptic Cafe Billing System!\n");

    // Adding some items to the menu
    addItem("Black Coffee", 2.5);
    addItem("Cappuccino", 3.5);
    addItem("Latte", 3.0);
    addItem("Espresso", 2.0);
    addItem("Mocha", 4.0);
    addItem("Iced Tea", 2.5);
    addItem("Chai Latte", 3.5);
    addItem("Hot Chocolate", 3.0);
    addItem("Smoothie", 4.0);
    addItem("Juice", 2.5);

    // Displaying the menu
    displayMenu();

    // Taking the order from the customer
    int items[MAX_ITEMS];
    int numItemsOrdered = 0;
    int menuItemNumber;
    printf("Enter the item numbers you want to order or -1 to finish:\n");
    do {
        scanf("%d", &menuItemNumber);
        if (menuItemNumber >= 1 && menuItemNumber <= numItems) {
            items[numItemsOrdered++] = menuItemNumber;
        } else if (menuItemNumber != -1) {
            printf("Sorry! Invalid item number.\n");
        }
    } while (menuItemNumber != -1);

    // Getting the total bill amount
    float total = getTotal(items, numItemsOrdered);

    // Displaying the bill amount
    printf("Your total bill amount is $%.2f.\n", total);

    return 0;
}