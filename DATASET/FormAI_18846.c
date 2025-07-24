//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>

#define TAX_RATE 0.05
#define TIP_RATE 0.15

int main() {
    int item_count;
    float item_price;
    float subtotal, tax, total, tip;

    // Prompt the user for the number of items and their price
    printf("Enter the number of items: ");
    scanf("%d", &item_count);

    printf("Enter the price per item: ");
    scanf("%f", &item_price);

    // Calculate the subtotal, tax, and total amount with tax included
    subtotal = item_count * item_price;
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    // Calculate the tip based on the total amount
    tip = total * TIP_RATE;

    // Display the results
    printf("Subtotal: %.2f\n", subtotal);
    printf("Tax: %.2f\n", tax);
    printf("Total (with tax): %.2f\n", total);
    printf("Tip (15%%): %.2f\n", tip);
    printf("Grand Total: %.2f\n", total + tip);

    return 0;
}