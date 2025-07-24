//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>

int main()
{
    int menu_items[5] = {50, 70, 80, 60, 90}; // prices of menu items
    int choice, item_quantity;
    int total = 0;
    char again = 'Y';

    printf("\t\tWelcome to the Cafe Bill Calculator\n\n");
    printf("Menu Items:\n");
    printf("1. Coffee: Rs %d\n", menu_items[0]);
    printf("2. Tea: Rs %d\n", menu_items[1]);
    printf("3. Sandwich: Rs %d\n", menu_items[2]);
    printf("4. Pasta: Rs %d\n", menu_items[3]);
    printf("5. Pizza: Rs %d\n", menu_items[4]);

    do {
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        // Check if choice is valid
        if (choice < 1 || choice > 5) {
            printf("\nInvalid choice. Please enter a valid number\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &item_quantity);

        // Calculate total cost of item(s)
        total += menu_items[choice-1] * item_quantity;

        printf("\nDo you want to order anything else? (Y/N): ");
        scanf(" %c", &again);
    } while (again == 'Y' || again == 'y');

    // Print total bill amount
    printf("\nTotal amount: Rs %d", total);

    return 0;
}