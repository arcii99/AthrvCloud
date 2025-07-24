//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50 // maximum number of items that can be ordered 
#define QUANTITY_LIMIT 10 // limit of quantity that can be ordered for one item 

// structure definition for an item in the menu
typedef struct MenuItem {
    int item_code;
    char item_name[20];
    float item_price;
} MenuItem;

MenuItem menu[] = {
    {1, "Cappuccino", 3.5},
    {2, "Latte", 4.0},
    {3, "Espresso", 2.5},
    {4, "Mocha", 4.5},
    {5, "Hot Chocolate", 3.0}
};

int item_quantities[MAX_ITEMS]; // array to store quantities of items ordered 
int num_items = 0; // counter for number of items ordered 

// function prototypes 
void show_menu();
void place_order();
void display_bill();

int main() {
    printf("Welcome to the C Cafe!\n");
    show_menu(); // display the menu 
    
    // loop to take multiple orders 
    char order_again;
    do {
        place_order(); // take order 
        printf("\nEnter 'Y' to place another order, any other key to view bill: ");
        scanf(" %c", &order_again);
    } while (order_again == 'Y' || order_again == 'y');
    
    display_bill(); // display the final bill 
    
    return 0;
}

void show_menu() {
    printf("\nMenu:\n");
    printf("Code\tName\t\tPrice\n");
    printf("=========================\n");
    for (int i = 0; i < sizeof(menu) / sizeof(*menu); i++) {
        printf("%d\t%-15s\t$%.2f\n", menu[i].item_code, menu[i].item_name, menu[i].item_price);
    }
}

void place_order() {
    int item_code, quantity;
    printf("\nEnter item code and quantity (max %d): ", QUANTITY_LIMIT);
    scanf("%d %d", &item_code, &quantity);
    
    // validations 
    if (item_code < 1 || item_code > sizeof(menu) / sizeof(*menu)) {
        printf("Invalid item code. Please enter a valid code.\n");
        place_order();
        return;
    }
    if (quantity < 1 || quantity > QUANTITY_LIMIT) {
        printf("Invalid quantity. Please enter a valid quantity (max %d).\n", QUANTITY_LIMIT);
        place_order();
        return;
    }
    
    // update the quantities array 
    item_quantities[num_items] = quantity;
    num_items++;
    
    printf("%d %s added to order.\n", quantity, menu[item_code - 1].item_name);
}

void display_bill() {
    float total = 0;
    printf("\nC Cafe\n");
    for (int i = 0; i < num_items; i++) {
        MenuItem item = menu[i];
        float price = item.item_price * item_quantities[i];
        total += price;
        printf("%2d x %-15s $%.2f\n", item_quantities[i], item.item_name, price);
    }
    printf("\nTotal bill: $%.2f", total);
}