//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>

int main() {
    // Define variables
    int numItems, i;
    float price, subtotal = 0.0, tax, total;

    // Get number of items from user
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    // Loop through each item and get price
    for (i = 1; i <= numItems; i++) {
        printf("Enter the price for item %d: ", i);
        scanf("%f", &price);
        subtotal += price;
    }

    // Calculate tax and total
    tax = subtotal * 0.06;
    total = subtotal + tax;

    // Display receipt
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", tax);
    printf("Total: $%.2f\n", total);

    return 0;
}