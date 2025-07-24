//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[20]; 
    float price; 
    int quantity; 
};

void print_menu(struct item *menu, int size) {
    int i;
    printf("\n%-10s %-15s %-10s\n", "Item No.", "Name", "Price");
    for(i=0; i<size; i++) {
        printf("%-10d %-15s %-10.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

int main() {
    int choice, quantity, total_items = 0;
    float total_price = 0;
    struct item menu[5]; 
    strcpy(menu[0].name, "Latte");
    menu[0].price = 3.50;
    menu[0].quantity = 10;
    strcpy(menu[1].name, "Cappuccino");
    menu[1].price = 4.00;
    menu[1].quantity = 8;
    strcpy(menu[2].name, "Espresso");
    menu[2].price = 2.50;
    menu[2].quantity = 12;
    strcpy(menu[3].name, "Iced Coffee");
    menu[3].price = 3.75;
    menu[3].quantity = 15;
    strcpy(menu[4].name, "Hot Chocolate");
    menu[4].price = 3.00;
    menu[4].quantity = 10;
    printf("Welcome to the C Cafe Billing System!\n");
    do {
        print_menu(menu, 5);
        printf("\nEnter the item number you would like to order (0 to exit): ");
        scanf("%d", &choice);
        if(choice == 0) {
            break;
        }
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        if(quantity <= 0) {
            printf("Invalid quantity! Please enter a positive integer\n");
            continue;
        }
        if(menu[choice-1].quantity < quantity) {
            printf("Sorry, we only have %d %s left\n", menu[choice-1].quantity, menu[choice-1].name);
            continue;
        }
        printf("%d %s added to your order!\n", quantity, menu[choice-1].name);
        menu[choice-1].quantity -= quantity;
        total_items += quantity;
        total_price += menu[choice-1].price * quantity;
    } while(1);
    printf("\nThank you for your order! You ordered %d items for a total of $%.2f\n", total_items, total_price);
    return 0;
}