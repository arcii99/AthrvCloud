//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store details of each item in the menu
typedef struct {
    char name[20];
    double price;
} MenuItem;

// Global array of menu items
MenuItem menu[5];

// Function to print the menu
void printMenu() {
    printf("Menu:\n");
    printf("------\n");
    for(int i=0; i<5; i++) {
        printf("%d. %s - %.2lf\n", i+1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

// Function to add an item to the menu
void addItem() {
    char name[20];
    double price;
    printf("Enter name of item: ");
    fgets(name, 20, stdin);
    printf("Enter price of item: ");
    scanf("%lf", &price);
    getchar(); // Consume newline character left over by scanf
    // Add item to menu
    for(int i=0; i<5; i++) {
        if(strcmp(menu[i].name, "") == 0) {
            strcpy(menu[i].name, name);
            menu[i].price = price;
            break;
        }
    }
    printf("Item added to menu.\n\n");
}

// Function to calculate total bill and print it along with items ordered
void calculateBill(int orders[], int numOrders) {
    double total = 0.0;
    printf("\n\n");
    printf("========================================================\n");
    printf("                   C Cafe Billing System                 \n");
    printf("========================================================\n");
    printf("Bill:\n");
    for(int i=0; i<numOrders; i++) {
        int index = orders[i] - 1;
        printf("%d. %s - %.2lf\n", i+1, menu[index].name, menu[index].price);
        total += menu[index].price;
    }
    printf("Total: %.2lf\n", total);
    printf("Thank you for ordering from C Cafe!\n");
}

int main() {
    // Initialize menu
    strcpy(menu[0].name, "Espresso");
    menu[0].price = 2.50;
    strcpy(menu[1].name, "Latte");
    menu[1].price = 3.00;
    strcpy(menu[2].name, "Cappuccino");
    menu[2].price = 3.50;
    strcpy(menu[3].name, "Mocha");
    menu[3].price = 4.00;
    strcpy(menu[4].name, "Iced Coffee");
    menu[4].price = 3.50;

    int orders[10]; // Array to store orders
    int numOrders = 0; // Number of orders

    // Loop to ask user for input
    while(1) {
        printf("Enter 1 to view menu\n");
        printf("Enter 2 to add an item to menu\n");
        printf("Enter 3 to place an order\n");
        printf("Enter 4 to exit\n");
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character left over by scanf
        switch(choice) {
            case 1:
                printMenu();
                break;
            case 2:
                addItem();
                break;
            case 3:
                printf("Enter item number to order (0 to finish): ");
                int item;
                scanf("%d", &item);
                while(item != 0) {
                    orders[numOrders] = item;
                    numOrders++;
                    printf("Enter another item number (0 to finish): ");
                    scanf("%d", &item);
                }
                calculateBill(orders, numOrders);
                return 0;
            case 4:
                printf("Exiting C Cafe Billing System.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}