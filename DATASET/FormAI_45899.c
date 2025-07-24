//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// function to calculate the total bill amount
float calculateBill(int coffee_qty, int snack_qty, int coffee_price, int snack_price) {
    float total_amount = (coffee_qty * coffee_price) + (snack_qty * snack_price);
    if (total_amount >= 500) {
        return total_amount - (0.1 * total_amount); // 10% discount if bill amount is greater than or equal to 500
    } else {
        return total_amount;
    }
}

int main() {
    int coffee_qty, snack_qty, choice;
    const int coffee_price = 50, snack_price = 20;
    float total_amount;
    
    // menu for user to choose the items and enter the quantity
    printf("Welcome to Cafe Billing System\n");
    printf("1. Coffee - Rs.50\n2. Snack - Rs.20\n");
    printf("Please enter the item number you want to order: ");
    scanf("%d", &choice);
    printf("Enter the quantity: ");
    scanf("%d", &coffee_qty);
    
    // if user selects snack, ask for snack quantity
    if (choice == 2) {
        printf("Enter the quantity: ");
        scanf("%d", &snack_qty);
    } else {
        snack_qty = 0; // if user selects coffee, set snack quantity to 0
    }
    
    total_amount = calculateBill(coffee_qty, snack_qty, coffee_price, snack_price); // calculate the total bill amount
    printf("Total bill amount: Rs.%.2f\n", total_amount);

    return 0;
}