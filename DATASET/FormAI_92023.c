//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global variables
int numOfItems;
float totalCost;

//structure definition
typedef struct menuItem {
    int itemNumber;
    char itemName[30];
    float itemPrice;
} MenuItem;

//function declarations
void displayMenu(MenuItem[]);
void placeOrder(MenuItem[]);
void showBill();

//main function
int main() {
    int choice;
    MenuItem menu[5] = {
        {1, "Cappuccino", 3.50},
        {2, "Latte", 3.75},
        {3, "Espresso", 2.50},
        {4, "Muffin", 2.25},
        {5, "Croissant", 1.75}
    };
    do {
        printf("\nWelcome to C Cafe!\n");
        printf("--------------------\n");
        printf("1. Display Menu\n");
        printf("2. Place Order\n");
        printf("3. Show Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                displayMenu(menu);
                break;
            case 2:
                placeOrder(menu);
                break;
            case 3:
                showBill();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    } while(1);
    return 0;
}

//function to display menu
void displayMenu(MenuItem menu[]) {
    int i;
    printf("\nMenu\n");
    printf("----\n");
    printf("No.\tName\t\tPrice\n");
    for(i=0;i<5;i++) {
        printf("%d.\t%s\t\t%.2f\n", menu[i].itemNumber, menu[i].itemName, menu[i].itemPrice);
    }
}

//function to place order
void placeOrder(MenuItem menu[]) {
    int choice, quantity;
    printf("\nEnter Item No.: ");
    scanf("%d", &choice);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    totalCost += menu[choice-1].itemPrice * quantity;
    numOfItems += quantity;
    printf("%d %s added successfully!\n", quantity, menu[choice-1].itemName);
}

//function to show bill
void showBill() {
    printf("\nBill\n");
    printf("----\n");
    printf("Total Items: %d\n", numOfItems);
    printf("Total Cost: $%.2f\n", totalCost);
    printf("Thank you for choosing C Cafe!\n");
}