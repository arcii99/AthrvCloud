//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Menu {
    char name[50];
    float price;
};

struct Order {
    char name[50];
    int quantity;
    float totalPrice;
};

void displayMenu(struct Menu menu[], int size) {
    printf("********************************************\n");
    printf("***                MENU                  ***\n");
    printf("********************************************\n");
    printf("Name\t\t\t Price\n");
    for (int i = 0; i < size; i++) {
        printf("%-25s %.2f\n", menu[i].name, menu[i].price);
    }
    printf("--------------------------------------------\n");
}

int findMenuIndex(struct Menu menu[], int size, char name[50]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void placeOrder(struct Menu menu[], int menuSize, struct Order orderList[], int *orderSize) {
    int index, quantity;
    char option;
    float subtotal;
    char orderName[50];

    do {
        displayMenu(menu, menuSize);
        printf("Enter Item Name to Order:");
        scanf("%s", orderName);
        index = findMenuIndex(menu, menuSize, orderName);

        if (index != -1) {
            printf("Enter Quantity: ");
            scanf("%d", &quantity);
            subtotal = menu[index].price * quantity;

            strcpy(orderList[*orderSize].name, menu[index].name);
            orderList[*orderSize].quantity = quantity;
            orderList[*orderSize].totalPrice = subtotal;
            (*orderSize)++;
            printf("%d %s Added to Cart Successfully!\n", quantity, menu[index].name);
        } else {
            printf("Sorry, the Item You have entered is not available in the menu\n");
        }
        printf("Do you want to add another Item (y/n)? ");
        scanf(" %c", &option);
    } while (option == 'y' || option == 'Y');
}

void printBill(struct Order orderList[], int orderSize) {
    printf("********************************************\n");
    printf("***                BILL                  ***\n");
    printf("********************************************\n");
    printf("Name\t\tQuantity\tPrice\n");
    for (int i = 0; i < orderSize; i++) {
        printf("%-25s %d x %.2f\t%.2f\n", orderList[i].name, orderList[i].quantity, (orderList[i].totalPrice / orderList[i].quantity), orderList[i].totalPrice);
    }
    printf("--------------------------------------------\n");
}

void main() {
    struct Menu menu[5];

    // Adding Items to Menu
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 1.50;

    strcpy(menu[1].name, "Tea");
    menu[1].price = 1.00;

    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 2.50;

    strcpy(menu[3].name, "Burger");
    menu[3].price = 3.50;

    strcpy(menu[4].name, "Cake");
    menu[4].price = 4.00;

    struct Order orderList[20];
    int orderSize = 0;
    char option;

    do {
        printf("********************************************\n");
        printf("***          CAFE BILLING SYSTEM         ***\n");
        printf("********************************************\n\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. Print Bill\n");
        printf("4. Exit\n");

        printf("Enter Your Option: ");
        scanf(" %c", &option);

        switch (option) {
        case '1':
            displayMenu(menu, 5);
            break;
        case '2':
            placeOrder(menu, 5, orderList, &orderSize);
            break;
        case '3':
            if (orderSize > 0) {
                printBill(orderList, orderSize);
            } else {
                printf("No Items Ordered Yet\n");
            }
            break;
        case '4':
            exit(0);
        default:
            printf("Invalid option\n");
        }
        printf("Press any key to continue...\n");
        getchar();
        getchar();
        system("clear");
    } while (option != '4');
}