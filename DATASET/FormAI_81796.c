//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100 // maximum number of items on the menu
#define MAX_CHOICE 20 // maximum length of menu item name

// define a struct to represent a menu item
struct MenuItem {
    char name[MAX_CHOICE];
    double price;
};

// function to print the menu
void print_menu(struct MenuItem *menu, int num_items) {
    printf("\nMenu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

int main() {
    // initialize the menu
    struct MenuItem menu[MAX_ITEMS];
    int num_items = 0;
    strcpy(menu[num_items].name, "Coffee");
    menu[num_items].price = 1.50;
    num_items++;
    strcpy(menu[num_items].name, "Tea");
    menu[num_items].price = 1.25;
    num_items++;
    strcpy(menu[num_items].name, "Bagel");
    menu[num_items].price = 2.50;
    num_items++;
    strcpy(menu[num_items].name, "Croissant");
    menu[num_items].price = 2.00;
    num_items++;
    strcpy(menu[num_items].name, "Muffin");
    menu[num_items].price = 1.75;
    num_items++;
    strcpy(menu[num_items].name, "Scone");
    menu[num_items].price = 2.25;
    num_items++;

    // print the menu
    print_menu(menu, num_items);

    // initialize variables
    char choice[MAX_CHOICE];
    int quantity;
    double total = 0.00;

    // loop to take orders
    while (1) {
        // take input for menu choice
        printf("\nEnter a menu item (or 'done' to finish): ");
        scanf("%s", choice);
        // convert to lowercase for case-insensitive comparison
        for (int i = 0; choice[i]; i++) {
            choice[i] = tolower(choice[i]);
        }
        // check if 'done'
        if (strcmp(choice, "done") == 0) {
            break;
        }
        // take input for quantity
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        // find the item in the menu
        int found = 0;
        for (int i = 0; i < num_items; i++) {
            if (strcmp(menu[i].name, choice) == 0) {
                // item found
                found = 1;
                total += menu[i].price * quantity;
                printf("%d x %s added to order.\n", quantity, menu[i].name);
                break;
            }
        }
        if (found == 0) {
            printf("Invalid menu item.\n");
        }
    }

    // print the total
    printf("Total: $%.2f\n", total);

    return 0;
}