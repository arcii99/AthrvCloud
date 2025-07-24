//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Global variables to store menu items and prices
char menu_items[10][20] = {"Espresso", "Latte", "Cappuccino", "Americano", "Mocha", "Hot Chocolate", "Tea", "Iced Tea", "Fruit Smoothie", "Milkshake"};
float menu_prices[10] = {2.5, 3.0, 3.5, 2.75, 4.0, 3.0, 2.0, 2.5, 4.5, 3.5};

// Function to display menu
void display_menu() {
    printf("\nMenu:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu_items[i], menu_prices[i]);
    }
}

int main() {
    int order_num, quantity;
    float total_cost = 0;

    printf("Welcome to the C Cafe Billing System!\n\n");

    // Display menu
    display_menu();

    // Ask for order
    while(1) {
        printf("\nEnter Order Number (0 to exit): ");
        scanf("%d", &order_num);
        if(order_num == 0) break;

        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        if(order_num < 1 || order_num > 10) {
            printf("Invalid order number. Please try again.\n");
            continue;
        }

        // Add cost to total
        total_cost += menu_prices[order_num-1] * quantity;
    }

    printf("\nTotal Cost: $%.2f\n", total_cost);
    printf("Thank you for dining at the C Cafe!\n");

    return 0;
}