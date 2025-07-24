//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for item in the menu
typedef struct MenuItem {
    int id;
    char name[50];
    float price;
    int quantity;
} MenuItem;

// Function to display menu
void displayMenu(MenuItem menu[], int n) {
    printf("******************************\n");
    printf("            MENU\n");
    printf("******************************\n");
    printf("ID\tName\t\tPrice\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("******************************\n");
}

// Function to place order
void placeOrder(MenuItem menu[], int n) {
    char choice[10];
    int itemID, quantity;
    float total = 0;
    printf("Enter 'done' to stop ordering\n");
    do {
        printf("Enter item ID: ");
        scanf("%d", &itemID);
        if(itemID > n || itemID < 1) {
            printf("Invalid item ID. Try again.\n");
            continue;
        }
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        if(quantity < 1) {
            printf("Invalid quantity. Try again.\n");
            continue;
        }
        total += (menu[itemID-1].price * quantity);
        menu[itemID-1].quantity += quantity;
        printf("Item added to cart.\n");
        printf("Order another item? (yes/no): ");
        scanf("%s", choice);
    } while(strcmp(choice, "done") != 0);
    printf("******************************\n");
    printf("          INVOICE\n");
    printf("******************************\n");
    printf("ID\tName\t\tPrice\tQuantity\tTotal\n");
    for(int i = 0; i < n; i++) {
        if(menu[i].quantity > 0) {
            printf("%d\t%s\t\t%.2f\t%d\t\t%.2f\n", menu[i].id, menu[i].name, menu[i].price, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }
    printf("******************************\n");
    printf("\t\t\t\tTotal: %.2f\n", total);
}

int main() {
    MenuItem menu[5];
    strcpy(menu[0].name, "Coffee");
    menu[0].id = 1;
    menu[0].price = 3.50;
    menu[0].quantity = 0;
    strcpy(menu[1].name, "Tea");
    menu[1].id = 2;
    menu[1].price = 2.50;
    menu[1].quantity = 0;
    strcpy(menu[2].name, "Cake");
    menu[2].id = 3;
    menu[2].price = 4.00;
    menu[2].quantity = 0;
    strcpy(menu[3].name, "Sandwich");
    menu[3].id = 4;
    menu[3].price = 5.50;
    menu[3].quantity = 0;
    strcpy(menu[4].name, "Muffin");
    menu[4].id = 5;
    menu[4].price = 2.00;
    menu[4].quantity = 0;
    int choice;
    do {
        printf("\n1. Display menu\n");
        printf("2. Place order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                displayMenu(menu, 5);
                break;
            case 2:
                placeOrder(menu, 5);
                break;
            case 3:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(1);
    return 0;
}