//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store details of each item
typedef struct item {
    char name[50];
    float price;
    int quantity;
} Item;

// Main function to run the cafe billing system
int main() {
    // Welcome message
    printf("Welcome to the Surrealist Cafe Billing System!\n\n");

    // Array to store available menu items
    Item menu[10];

    // Initializing menu items
    strcpy(menu[0].name, "Espresso");
    menu[0].price = 2.5;
    menu[0].quantity = 10;
    strcpy(menu[1].name, "Cappuccino");
    menu[1].price = 3.0;
    menu[1].quantity = 8;
    strcpy(menu[2].name, "Latte");
    menu[2].price = 3.5;
    menu[2].quantity = 5;
    strcpy(menu[3].name, "Croissant");
    menu[3].price = 2.0;
    menu[3].quantity = 15;
    strcpy(menu[4].name, "Bagel");
    menu[4].price = 2.5;
    menu[4].quantity = 12;
    strcpy(menu[5].name, "Muffin");
    menu[5].price = 2.0;
    menu[5].quantity = 10;
    strcpy(menu[6].name, "Brownie");
    menu[6].price = 2.5;
    menu[6].quantity = 8;
    strcpy(menu[7].name, "Cake");
    menu[7].price = 3.0;
    menu[7].quantity = 6;
    strcpy(menu[8].name, "Pie");
    menu[8].price = 3.5;
    menu[8].quantity = 4;
    strcpy(menu[9].name, "Ice Cream");
    menu[9].price = 4.0;
    menu[9].quantity = 3;

    // Array to store customer order
    Item order[10];

    int i = 0;
    float total = 0;
    char choice = 'y';

    // Loop to take customer order
    while (choice == 'y' || choice == 'Y') {
        // Display menu
        printf("\n----------------------------------\n");
        printf("          Surrealist Cafe          \n");
        printf("----------------------------------\n");
        printf(" Code - Name        - Price        \n");
        printf("----------------------------------\n");
        for (int j = 0; j < 10; j++) {
            printf(" %-2d   - %-12s - $ %4.2f    \n", j+1, menu[j].name, menu[j].price);
        }
        printf("----------------------------------\n");

        // Take order input
        int code, quantity;
        printf("Enter item code: ");
        scanf("%d", &code);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Check if item is available
        if (menu[code-1].quantity < quantity) {
            printf("Sorry, only %d %s left.\n", menu[code-1].quantity, menu[code-1].name);
        } else {
            // Add item to customer order and deduct quantity from menu
            strcpy(order[i].name, menu[code-1].name);
            order[i].price = menu[code-1].price;
            order[i].quantity = quantity;
            menu[code-1].quantity -= quantity;
            total += order[i].price * order[i].quantity;
            i++;
        }

        // Ask if customer wants to order more
        printf("\nDo you want to order more? (y/n): ");
        scanf(" %c", &choice);
    }

    // Display final order and total amount
    printf("\n----------------------------------\n");
    printf("           Surrealist Cafe         \n");
    printf("----------------------------------\n");
    printf(" Item        - Price     - Quantity \n");
    printf("----------------------------------\n");
    for (int j = 0; j < i; j++) {
        printf(" %-12s - $ %4.2f - %d        \n", order[j].name, order[j].price, order[j].quantity);
    }
    printf("----------------------------------\n");
    printf(" Total amount: $ %4.2f\n", total);

    return 0;
}