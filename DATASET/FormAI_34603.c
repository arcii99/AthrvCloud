//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100
#define BILL_FILE "bill.txt"

// Define the structure of an item in the menu
typedef struct MenuItem {
    char name[20];
    float price;
} menuItem;

// Define the structure of an item in the bill
typedef struct BillItem {
    char name[20];
    float price;
    int quantity;
} billItem;

// Function to display menu and return the selected item index
int displayMenu(menuItem items[]) {
    int choice;
    printf("Menu:\n");
    for(int i=0; i<MAX_ITEMS; i++) {
        if(strlen(items[i].name) == 0) {
            break;
        }
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
    printf("Enter the item number (or 0 to end): ");
    scanf("%d", &choice);
    return choice;
}

// Function to add item to the bill
void addItemToBill(billItem bill[], menuItem item, int *billSize) {
    int exists = 0;
    for(int i=0; i<MAX_ITEMS; i++) {
        if(strcmp(item.name, bill[i].name) == 0) {
            exists = 1;
            bill[i].quantity++;
            break;
        }
    }
    if(!exists) {
        strcpy(bill[*billSize].name, item.name);
        bill[*billSize].price = item.price;
        bill[*billSize].quantity = 1;
        (*billSize)++;
    }
}

// Function to calculate the total amount of the bill
float calculateBillTotal(billItem bill[], int billSize) {
    float total = 0.0;
    for(int i=0; i<billSize; i++) {
        total += (bill[i].price * bill[i].quantity);
    }
    return total;
}

// Function to display the bill and save it to file
void displayBill(billItem bill[], int billSize) {
    printf("\nBill:\n");
    for(int i=0; i<billSize; i++) {
        printf("%d %s - $%.2f\n", bill[i].quantity, bill[i].name, bill[i].price * bill[i].quantity);
    }
    float total = calculateBillTotal(bill, billSize);
    printf("Total: $%.2f\n", total);
    
    // Save the bill to file
    FILE *fp = fopen(BILL_FILE, "w");
    fprintf(fp, "Bill:\n");
    for(int i=0; i<billSize; i++) {
        fprintf(fp, "%d %s - $%.2f\n", bill[i].quantity, bill[i].name, bill[i].price * bill[i].quantity);
    }
    fprintf(fp, "Total: $%.2f\n", total);
    fclose(fp);
}

int main() {

    menuItem menu[MAX_ITEMS];
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 2.50;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 2.00;
    strcpy(menu[2].name, "Cappuccino");
    menu[2].price = 3.50;
    strcpy(menu[3].name, "Latte");
    menu[3].price = 3.00;

    billItem bill[MAX_ITEMS];
    int billSize = 0;

    printf("Welcome to C Cafe!\n");

    int choice;
    do {
        choice = displayMenu(menu);
        if(choice > 0 && choice <= MAX_ITEMS) {
            addItemToBill(bill, menu[choice-1], &billSize);
            printf("Added %s to bill\n\n", menu[choice-1].name);
        }
    } while(choice != 0);
    
    displayBill(bill, billSize);

    printf("Thank you for visiting C Cafe. See you soon!\n");

    return 0;
}