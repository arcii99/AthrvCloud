//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ITEMS 100 // maximum items on menu
#define MAX_NAME_LENGTH 50 // maximum length of item name
#define MAX_CAT_LENGTH 20 // maximum length of category name

//structure to hold menu item details
struct MenuItem {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CAT_LENGTH];
    float price;
    int quantity;
};

//structure to hold order details
struct OrderItem {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
};

//function to display menu items
void printMenu(struct MenuItem menu[], int menuSize) {
    printf("===== MENU =====\n");
    printf("Name\t\tCategory\t\tPrice\n");
    for(int i=0;i<menuSize;i++) {
        printf("%s\t\t%s\t\t%.2f\n", menu[i].name, menu[i].category, menu[i].price);
    }
}

//function to search menu for a given item name
int searchMenuForItem(struct MenuItem menu[], int menuSize, char *name) {
    for(int i=0;i<menuSize;i++) {
        if(strcmp(menu[i].name, name)==0) {
            return i;
        }
    }
    return -1;
}

//function to take order from customer
void takeOrder(struct MenuItem menu[], int menuSize, struct OrderItem order[], int *orderSize) {
    char itemName[MAX_NAME_LENGTH];
    int itemQuantity;
    printf("Enter item name: ");
    scanf("%s", itemName);
    int itemIndex = searchMenuForItem(menu, menuSize, itemName);
    if(itemIndex==-1) {
        printf("Item not found in menu\n");
    }
    else {
        printf("Enter quantity: ");
        scanf("%d", &itemQuantity);
        if(itemQuantity<=0) {
            printf("Quantity cannot be zero or negative\n");
        }
        else if(order[*orderSize].quantity+itemQuantity>10) {
            printf("Cannot order more than 10 items at a time\n");
        }
        else {
            strcpy(order[*orderSize].name, menu[itemIndex].name);
            order[*orderSize].price = menu[itemIndex].price;
            order[*orderSize].quantity += itemQuantity;
            printf("Order added\n");
            (*orderSize)++;
        }
    }
}

//function to calculate bill amount
void calculateBill(struct OrderItem order[], int orderSize, float *billAmount) {
    (*billAmount) = 0;
    printf("================ BILL ================\n");
    printf("Name\t\tPrice\t\tQuantity\tTotal\n");
    for(int i=0;i<orderSize;i++) {
        float itemTotal = order[i].price * order[i].quantity;
        printf("%s\t\t%.2f\t\t%d\t\t%.2f\n", order[i].name, order[i].price, order[i].quantity, itemTotal);
        (*billAmount) += itemTotal;
    }
    printf("======================================\n");
    printf("Total bill amount = %.2f\n", *billAmount);
}

int main() {
    struct MenuItem menu[MAX_ITEMS]; //array to hold menu items
    int menuSize = 0; //number of items on menu
    struct OrderItem order[10]; //array to hold order items
    int orderSize = 0; //number of items in order
    float billAmount = 0; //total bill amount
    int choice = -1; //customer's menu choice
    //pre-populate menu with some items for testing
    strcpy(menu[menuSize].name, "Cappuccino");
    strcpy(menu[menuSize].category, "Coffee");
    menu[menuSize].price = 2.5;
    menu[menuSize].quantity = 10;
    menuSize++;
    strcpy(menu[menuSize].name, "Latte");
    strcpy(menu[menuSize].category, "Coffee");
    menu[menuSize].price = 3.0;
    menu[menuSize].quantity = 5;
    menuSize++;
    //display welcome message
    printf("Welcome to C Cafe Billing System\n");
    //main loop of the program
    while(choice!=0) {
        printf("\nMenu:\n");
        printf("1. View menu\n");
        printf("2. Take order\n");
        printf("3. Calculate bill\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printMenu(menu, menuSize);
                break;
            case 2:
                takeOrder(menu, menuSize, order, &orderSize);
                break;
            case 3:
                if(orderSize==0) {
                    printf("No order items found\n");
                }
                else {
                    calculateBill(order, orderSize, &billAmount);
                    orderSize = 0; //reset order items
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}