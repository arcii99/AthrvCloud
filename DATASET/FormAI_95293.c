//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structure for each item */
typedef struct {
    char name[20];
    int price;
} Item;

/* Define the structure for each order */
typedef struct {
    char itemName[20];
    int quantity;
    int price;
} Order;

/* Define the function to display the menu */
void displayMenu(Item menu[], int menuSize) {
    printf("Welcome to C Cafe!\n");
    printf("Menu:\n");
    for(int i=0; i<menuSize; i++) {
        printf("%d. %s\t\tRs. %d\n", i+1, menu[i].name, menu[i].price);
    }
}

/* Define the function to get user order */
void getUserOrder(Item menu[], int menuSize, Order userOrder[], int *orderSize) {
    char input[20];
    int itemNo, quantity;
    do {
        printf("Enter item number to order (Press 0 to exit): ");
        fgets(input, 20, stdin);
        itemNo = atoi(input);
        if(itemNo < 0 || itemNo > menuSize) {
            printf("Invalid item number. Try again.\n");
            continue;
        } else if(itemNo == 0) {
            break;
        }
        printf("Enter quantity: ");
        fgets(input, 20, stdin);
        quantity = atoi(input);
        if(quantity < 1) {
            printf("Invalid quantity. Try again.\n");
            continue;
        }
        userOrder[*orderSize].quantity = quantity;
        userOrder[*orderSize].price = menu[itemNo-1].price * quantity;
        strcpy(userOrder[*orderSize].itemName, menu[itemNo-1].name);
        (*orderSize)++;
    } while(itemNo != 0);
}

/* Define the function to print user order */
void printUserOrder(Order userOrder[], int orderSize) {
    printf("Order summary:\n");
    printf("%-20s%-10s%-10s\n", "Item", "Quantity", "Price");
    for(int i=0; i<orderSize; i++) {
        printf("%-20s%-10d%-10d\n", userOrder[i].itemName, userOrder[i].quantity, userOrder[i].price);
    }
}

/* Define the main function */
int main() {
    /* Define variables */
    Item menu[5] = { {"Coffee", 50}, {"Tea", 20}, {"Sandwich", 70}, {"Muffin", 40}, {"Cake", 100} };
    int menuSize = 5;
    Order userOrder[10];
    int orderSize = 0;

    /* Display the menu */
    displayMenu(menu, menuSize);

    /* Get user order */
    getUserOrder(menu, menuSize, userOrder, &orderSize);

    /* Print user order */
    printUserOrder(userOrder, orderSize);

    /* Calculate total price */
    int totalPrice = 0;
    for(int i=0; i<orderSize; i++) {
        totalPrice += userOrder[i].price;
    }
    printf("Total price: Rs. %d\n", totalPrice);

    return 0;
}