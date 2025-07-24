//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item { // Structure defining an item in the menu
    char name[20];
    int price;
} Item;

typedef struct Order { // Structure defining an order placed by a customer
    char item_name[20];
    int quantity;
    int price;
} Order;

Item menu[] = { // Menu containing items and their prices
    {"Coffee", 50},
    {"Sandwich", 60},
    {"Burger", 75},
    {"Pizza", 120},
    {"Coke", 35},
    {"Tea", 30}
};

void display_menu() { // Function to display the menu
    printf("------------MENU--------------\n");
    printf("ITEM\t\tPRICE\n");
    for(int i = 0; i < 6; i++) {
        printf("%s\t\t%d\n", menu[i].name, menu[i].price);
    }
}

int search_item(char input[]) { // Helper function to search for an item in the menu
    for(int i = 0; i < 6; i++) {
        if(strcmp(input, menu[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

Order take_order() { // Function to take an order from the customer
    printf("Enter the name of the item: ");
    char input[20];
    scanf("%s", input);
    int index = search_item(input);
    if(index == -1) {
        printf("Item not found in menu. Please try again.\n");
        return take_order();
    }
    else {
        printf("Enter the quantity: ");
        int quantity;
        scanf("%d", &quantity);
        Order order;
        strcpy(order.item_name, input);
        order.quantity = quantity;
        order.price = quantity * menu[index].price;
        return order;
    }
}

void display_order(Order order) { // Helper function to display an order
    printf("%s x %d\t\t%d\n", order.item_name, order.quantity, order.price);
}

int main() {
    printf("*****Welcome to C Cafe*****\n");
    display_menu();

    Order orders[10]; // Array to store orders placed by customers
    int index = 0; // Index of the next empty element in the orders array

    while(1) { // Loop to take multiple orders
        char choice;
        printf("Would you like to place an order? (y/n): ");
        scanf(" %c", &choice);
        if(choice == 'n') {
            break;
        }
        else if(choice == 'y') {
            printf("Please place your order:\n");
            Order order = take_order();
            display_order(order);
            orders[index] = order;
            index++;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nORDER DETAILS\n");
    printf("--------------\n");
    printf("ITEM\tQUANTITY\tPRICE\n");
    int total_amount = 0;
    for(int i = 0; i < index; i++) {
        display_order(orders[i]);
        total_amount += orders[i].price;
    }
    printf("Total Amount: %d\n", total_amount);

    printf("\nThank you for choosing C Cafe!\n");
    return 0;
}