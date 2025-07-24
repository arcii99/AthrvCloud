//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
    int menu[10][2] = {{1, 25}, {2, 20}, {3, 30}, {4, 15}, {5, 10}, {6, 18}, {7, 28}, {8, 35}, {9, 40}, {10, 45}};
    // menu array stores menu items and their respective prices

    int choice, quantity, bill = 0;
    char ch;

    printf("Welcome to the C Cafe!\n");

    do {
        printf("\nPlease enter the choice of the item you want to order (1-10): ");
        scanf("%d", &choice);

        printf("Please enter the quantity: ");
        scanf("%d", &quantity);

        if (choice > 0 && choice < 11) {
            bill += menu[choice-1][1] * quantity;  // calculate the total cost for the selected item and quantity
            printf("\nItem: %d - Rs.%d x %d = Rs.%d\n", menu[choice-1][0], menu[choice-1][1], quantity, menu[choice-1][1] * quantity);
        }
        else {
            printf("\nInvalid choice. Please choose again.\n");
        }

        printf("Do you want to order anything else? (y/n) ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    printf("\n\nYour total bill amount is Rs.%d\n", bill);

    printf("\n\nThank you for visiting the C Cafe!\n\n");

    return 0;
}