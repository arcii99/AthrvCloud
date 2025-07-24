//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int option;
    float espresso = 2.5, latte = 3.0, cappuccino = 2.75, total = 0.0;
    printf("Welcome to Cafe Baker Street Billing System!\n");
    printf("What would you like to order?\n");
    printf("1. Espresso - $2.5\n2. Latte - $3.0\n3. Cappuccino - $2.75\n4. Exit\n");

    do {
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                total += espresso;
                printf("Espresso added to your order. Current total: $%.2f", total);
                break;
            case 2:
                total += latte;
                printf("Latte added to your order. Current total: $%.2f", total);
                break;
            case 3:
                total += cappuccino;
                printf("Cappuccino added to your order. Current total: $%.2f", total);
                break;
            case 4:
                printf("Thank you for visiting Cafe Baker Street!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while(option != 4);

    printf("Your total bill is $%.2f", total);

    return 0;
}