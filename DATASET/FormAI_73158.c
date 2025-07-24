//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, quantity, bill = 0;
    printf("Welcome to C Cafe!\n\n");
    printf("MENU:\n");
    printf("1. Coffee - $2\n");
    printf("2. Tea - $1.50\n");
    printf("3. Sandwich - $5\n");
    printf("4. Cake - $3\n");
    printf("5. Exit\n\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 5) {
            printf("\nTotal bill: $%d\n", bill);
            break;
        }
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        switch (choice) {
            case 1:
                bill += 2 * quantity;
                printf("%d cups of coffee added to the bill.\n", quantity);
                break;
            case 2:
                bill += 1.5 * quantity;
                printf("%d cups of tea added to the bill.\n", quantity);
                break;
            case 3:
                bill += 5 * quantity;
                printf("%d sandwiches added to the bill.\n", quantity);
                break;
            case 4:
                bill += 3 * quantity;
                printf("%d cakes added to the bill.\n", quantity);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    printf("\nThank you for choosing C Cafe!\n");
    return 0;
}