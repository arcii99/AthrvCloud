//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDER_SIZE 50
#define MAX_MENU_SIZE 10
#define TAX_RATE 0.05
#define MAX_NAME_LENGTH 20

/* Menu struct */
typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} MenuItem;

/* Global variables */
MenuItem menu[MAX_MENU_SIZE];
int numMenuItems = 0;

/* Function prototypes */
void initMenu();
void displayMenu();
int takeOrder(char orderList[MAX_ORDER_SIZE][MAX_NAME_LENGTH], double orderPrices[MAX_ORDER_SIZE]);
double calculateTotal(double orderPrices[MAX_ORDER_SIZE], int numOrders);
double calculateTax(double subtotal);
double calculateTip(double subtotal);
void printReceipt(char orderList[MAX_ORDER_SIZE][MAX_NAME_LENGTH], double orderPrices[MAX_ORDER_SIZE], double subtotal, double tax, double tip, double total);


int main() {

    initMenu();
    displayMenu();

    char orderList[MAX_ORDER_SIZE][MAX_NAME_LENGTH];
    double orderPrices[MAX_ORDER_SIZE];

    int numOrders = takeOrder(orderList, orderPrices);
    double subtotal = calculateTotal(orderPrices, numOrders);
    double tax = calculateTax(subtotal);
    double tip = calculateTip(subtotal);
    double total = subtotal + tax + tip;

    printReceipt(orderList, orderPrices, subtotal, tax, tip, total);

    return 0;
}

/* Initialization function */
void initMenu() {
    strcpy(menu[0].name, "Cappuccino");
    menu[0].price = 3.99;
    numMenuItems++;

    strcpy(menu[1].name, "Latte");
    menu[1].price = 4.49;
    numMenuItems++;

    strcpy(menu[2].name, "Espresso");
    menu[2].price = 2.99;
    numMenuItems++;

    strcpy(menu[3].name, "Americano");
    menu[3].price = 2.99;
    numMenuItems++;

    strcpy(menu[4].name, "Mocha");
    menu[4].price = 4.99;
    numMenuItems++;
}

/* Display menu function */
void displayMenu() {
    printf("===== MENU =====\n");
    for (int i = 0; i < numMenuItems; i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
    printf("================\n");
}

/* Take order function */
int takeOrder(char orderList[MAX_ORDER_SIZE][MAX_NAME_LENGTH], double orderPrices[MAX_ORDER_SIZE]) {
    int numOrders = 0;

    while (1) {
        char itemName[MAX_NAME_LENGTH];
        printf("Enter item name (type 'done' to finish): ");
        scanf("%s", itemName);

        if (strcmp(itemName, "done") == 0) {
            break;
        }

        /* Find item in menu */
        int itemIndex = -1;
        for (int i = 0; i < numMenuItems; i++) {
            if (strcmp(itemName, menu[i].name) == 0) {
                itemIndex = i;
                break;
            }
        }

        /* If item found, add to order */
        if (itemIndex != -1) {
            strcpy(orderList[numOrders], itemName);
            orderPrices[numOrders] = menu[itemIndex].price;
            numOrders++;
        } else {
            printf("Item not found.\n");
        }

        /* Check if order size limit reached */
        if (numOrders == MAX_ORDER_SIZE) {
            printf("Order limit reached.\n");
            break;
        }
    }

    return numOrders;
}

/* Calculate subtotal function */
double calculateTotal(double orderPrices[MAX_ORDER_SIZE], int numOrders) {
    double subtotal = 0;
    for (int i = 0; i < numOrders; i++) {
        subtotal += orderPrices[i];
    }
    return subtotal;
}

/* Calculate tax function */
double calculateTax(double subtotal) {
    return subtotal * TAX_RATE;
}

/* Calculate tip function */
double calculateTip(double subtotal) {
    return subtotal * 0.15;
}

/* Print receipt function */
void printReceipt(char orderList[MAX_ORDER_SIZE][MAX_NAME_LENGTH], double orderPrices[MAX_ORDER_SIZE], double subtotal, double tax, double tip, double total) {
    printf("\n--- RECEIPT ---\n");
    for (int i = 0; i < MAX_ORDER_SIZE; i++) {
        if (strlen(orderList[i]) > 0) {
            printf("%s - $%.2f\n", orderList[i], orderPrices[i]);
        }
    }
    printf("----------------\n");
    printf("Subtotal:\t$%.2f\n", subtotal);
    printf("Tax:\t\t$%.2f\n", tax);
    printf("Tip:\t\t$%.2f\n", tip);
    printf("Total:\t\t$%.2f\n", total);
    printf("---------------\n");
}