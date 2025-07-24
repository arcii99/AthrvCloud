//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: excited
// Yay! Welcome to the C Cafe Billing System!
// Get ready to dazzle your customers!
// This exciting program will surely impress everyone who visits your cafe.

#include <stdio.h>

int main() {
    int order_count, i;
    float total_price = 0.0, price;
    char item_name[20];

    printf("Welcome to the C Cafe!\n");
    printf("Enter the number of items you would like to order: ");
    scanf("%d", &order_count);

    printf("\nEnter the item name and price for each item:\n");

    for (i=0; i<order_count; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: ");
        scanf("%s", item_name);
        printf("Price: $");
        scanf("%f", &price);

        total_price += price;

        printf("\n%s has been added to the order!\n\n", item_name);
    }

    printf("Thank you for your order!\n");
    printf("Your total is: $%.2f", total_price);

    return 0;
}