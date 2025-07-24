//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

float calculate_bill(float [], float []);
void print_bill(int, float [], float [], float);

int main() {
    int n;
    printf("Enter the number of items in the menu: ");
    scanf("%d", &n);

    float menu_prices[n];
    float menu_quantity[n];

    // take input of prices and quantities of items in the menu
    for(int i=0; i<n; i++) {
        printf("Enter the price of item %d: ", i+1);
        scanf("%f", &menu_prices[i]);

        printf("Enter the quantity of item %d: ", i+1);
        scanf("%f", &menu_quantity[i]);
    }

    printf("Enter the number of orders: ");
    scanf("%d", &n);

    // initialize empty arrays for order prices and quantities
    float order_prices[n];
    float order_quantity[n];

    // take input of prices and quantities of each item in an order
    for(int i=0; i<n; i++) {
        printf("Order %d:\n", i+1);
        for(int j=0; j<sizeof(menu_prices)/sizeof(menu_prices[0]); j++) {
            printf("How many %d? ", j+1);
            scanf("%f", &order_quantity[j]);

            order_prices[j] += order_quantity[j] * menu_prices[j];
        }
    }

    // calculate total bill
    float total_bill = calculate_bill(menu_prices, order_quantity);

    // print the bill
    print_bill(n, menu_prices, order_quantity, total_bill);

    return 0;
}

float calculate_bill(float menu_prices[], float order_quantity[]) {
    float total_bill = 0;
    for(int i=0; i<sizeof(menu_prices)/sizeof(menu_prices[0]); i++) {
        total_bill += order_quantity[i] * menu_prices[i];
    }

    return total_bill;
}

void print_bill(int n, float menu_prices[], float order_quantity[], float total_bill) {
    printf("------- C CAFE -------\n");
    for(int i=0; i<sizeof(menu_prices)/sizeof(menu_prices[0]); i++) {
        printf("Item %d (%.2f x %.2f): %.2f\n", i+1, menu_prices[i], order_quantity[i], order_quantity[i]*menu_prices[i]);
    }
    printf("----------------------\n");
    printf("Total: %.2f\n", total_bill);
    printf("----------------------\n");
}