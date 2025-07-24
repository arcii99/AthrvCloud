//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    char items[10][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pizza", "Pasta", "Brownie", "Ice Cream", "Fries", "Salad"};
    float prices[10] = {2.50, 2.00, 3.50, 4.00, 8.00, 6.50, 2.00, 3.00, 2.50, 5.00};
    int quantities[10] = {0};
    char choice;
    printf("\t\t=====Welcome to C Cafe!=====\n\n");
    do {
        printf("Menu:\n");
        for(int i=0; i<10; i++) {
            printf("%d. %s - $%.2f\n", i+1, items[i], prices[i]);
        }
        printf("Enter the item number to order: ");
        int item;
        scanf("%d", &item);
        printf("Enter the quantity: ");
        int qty;
        scanf("%d", &qty);
        quantities[item-1] += qty;
        printf("Would you like to order anything else? (Y/N): ");
        scanf("%s", &choice);

    } while(choice == 'Y' || choice == 'y');

    printf("\n");
    printf("Order Summary:\n");
    float total = 0.0;
    for(int i=0; i<10; i++) {
        if(quantities[i] > 0) {
            printf("%s - %d x $%.2f = $%.2f\n", items[i], quantities[i], prices[i], quantities[i]*prices[i]);
            total += quantities[i] * prices[i];
        }
    }

    printf("Total: $%.2f\n", total);
    printf("Thank you for choosing C Cafe. Please come again!\n");

    return 0;
}