//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_LEN 50
#define MAX_ITEMS 100

// Define a structure for the menu item
typedef struct MenuItem {
    char name[MAX_ITEM_LEN];
    double price;
} MenuItem;

// Define a structure for the order
typedef struct Order {
    MenuItem item;
    int quantity;
} Order;

// Declare global variables
MenuItem menu[MAX_ITEMS];
int num_menu_items = 0;
Order orders[MAX_ITEMS];
int num_orders = 0;

// Declare functions for the program
void add_menu_item(char* name, double price);
void print_menu();
void add_order(char* name, int quantity);
double calculate_bill();

int main() {
    // Add initial items to the menu
    add_menu_item("Coffee", 2.50);
    add_menu_item("Latte", 3.50);
    add_menu_item("Cappuccino", 3.00);
    add_menu_item("Mocha", 4.00);
    
    // Print the menu
    print_menu();
    
    // Take orders from customers
    char input[MAX_ITEM_LEN];
    int quantity;
    while (1) {
        printf("Enter an item to order (or q to quit): ");
        fgets(input, MAX_ITEM_LEN, stdin);
        if (strcmp(input, "q\n") == 0) {
            break;
        }
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        getchar(); // consume the newline character
        
        add_order(input, quantity);
    }
    
    // Calculate the bill for the orders
    double bill = calculate_bill();
    printf("Total bill: $%.2lf\n", bill);
    
    return 0;
}

// Function to add a new item to the menu
void add_menu_item(char* name, double price) {
    if (num_menu_items >= MAX_ITEMS) {
        printf("Error: maximum number of menu items reached\n");
        exit(1);
    }
    MenuItem item;
    strcpy(item.name, name);
    item.price = price;
    menu[num_menu_items] = item;
    num_menu_items++;
}

// Function to print the menu to the console
void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < num_menu_items; i++) {
        MenuItem item = menu[i];
        printf("%s\t$%.2lf\n", item.name, item.price);
    }
}

// Function to add a new order to the list of orders
void add_order(char* name, int quantity) {
    // Find the item in the menu
    MenuItem item;
    int found = 0;
    for (int i = 0; i < num_menu_items; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            item = menu[i];
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Error: item not found in menu\n");
        return;
    }
    
    // Add the order to the list
    Order order;
    order.item = item;
    order.quantity = quantity;
    orders[num_orders] = order;
    num_orders++;
}

// Function to calculate the total bill for the orders
double calculate_bill() {
    double total = 0.0;
    for (int i = 0; i < num_orders; i++) {
        Order order = orders[i];
        total += order.item.price * order.quantity;
    }
    return total;
}