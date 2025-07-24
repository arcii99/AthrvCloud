//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>

int main() {
    int choice, qty, price;
    char ans;

    printf("Welcome to the Wacky Cafe!\n");
    printf("1. Coffee - Rs. 50\n");
    printf("2. Tea - Rs. 20\n");
    printf("3. Sandwich - Rs. 100\n");

    do {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        printf("Enter quantity: ");
        scanf("%d", &qty);

        switch (choice) {
            case 1:
                price = qty * 50;
                printf("Your total bill for coffee is Rs.%d\n", price);
                break;
            case 2:
                price = qty * 20;
                printf("Your total bill for tea is Rs.%d\n", price);
                break;
            case 3:
                price = qty * 100;
                printf("Your total bill for sandwich is Rs.%d\n", price);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("Do you want anything else? (y/n): ");
        scanf(" %c", &ans);

    } while (ans == 'y' || ans == 'Y');

    printf("Thank you for visiting the Wacky Cafe! Come again soon!\n");

    return 0;
}