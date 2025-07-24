//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char item[100];
    int quantity;
    float price;
} Menu;

int menu_size = 10;
Menu menu[10];

void initialize_menu() {
    strcpy(menu[0].item, "Coffee");
    menu[0].quantity = 10;
    menu[0].price = 2.50;

    strcpy(menu[1].item, "Tea");
    menu[1].quantity = 15;
    menu[1].price = 2.00;

    strcpy(menu[2].item, "Juice");
    menu[2].quantity = 7;
    menu[2].price = 3.50;

    strcpy(menu[3].item, "Sandwich");
    menu[3].quantity = 5;
    menu[3].price = 4.50;

    strcpy(menu[4].item, "Burger");
    menu[4].quantity = 3;
    menu[4].price = 5.00;

    strcpy(menu[5].item, "Pizza");
    menu[5].quantity = 2;
    menu[5].price = 6.50;

    strcpy(menu[6].item, "Pasta");
    menu[6].quantity = 5;
    menu[6].price = 7.00;

    strcpy(menu[7].item, "Salad");
    menu[7].quantity = 9;
    menu[7].price = 3.00;

    strcpy(menu[8].item, "French fries");
    menu[8].quantity = 7;
    menu[8].price = 2.50;

    strcpy(menu[9].item, "Ice cream");
    menu[9].quantity = 4;
    menu[9].price = 2.00;
}

int main() {
    initialize_menu();
    float total = 0;
    printf("Welcome to our C Cafe!\n\n");

    while(1) {
        printf("\n\n~~ MENU ~~\n\n");
        printf("Item\t\tAvailable Quantity\tPrice\n");

        for(int i=0; i<menu_size; i++) {
            printf("%s\t\t%d\t\t%.2f\n", menu[i].item, menu[i].quantity, menu[i].price);
        }

        printf("\nEnter the item number you want to order (0 to exit): ");
        int item_number;
        scanf("%d", &item_number);

        if(item_number == 0) {
            break;
        }

        printf("Enter the quantity you want to order: ");
        int quantity;
        scanf("%d", &quantity);

        if(quantity > menu[item_number-1].quantity) {
            printf("\nSorry, we don't have enough %s. Available quantity: %d", menu[item_number-1].item, menu[item_number-1].quantity);
            continue;
        }

        menu[item_number-1].quantity -= quantity;
        printf("\n%s x %d ordered successfully!", menu[item_number-1].item, quantity);

        float item_total = quantity * menu[item_number-1].price;
        printf("\nTotal price for %s x %d: %.2f", menu[item_number-1].item, quantity, item_total);

        total += item_total;
    }

    printf("\n\nTotal bill: %.2f\n\n", total);
    printf("Thank you for visiting our C Cafe!");
    return 0;
}