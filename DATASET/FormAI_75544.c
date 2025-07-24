//FormAI DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// This is a program to manage the monthly expenses of a person

int main() {
    int choice;
    float amount;
    char option;
    float total_amount = 0;

    printf("\t\t====EXPENSE TRACKER====\n\n");

    do {
        printf("Enter\n1 to add expense\n2 to view total expense\n3 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter amount spent: $");
                scanf("%f", &amount);
                total_amount += amount; // add amount spent to the total_amount
                printf("Expense added.\n\n");
                break;
            case 2:
                printf("Total expense: $%.2f\n\n", total_amount);
                break;
            case 3:
                printf("Are you sure you want to exit? (y/n)\n");
                scanf(" %c", &option);
                if(option == 'y' || option == 'Y') {
                    printf("\n\nExiting expense tracker. Thank you!\n");
                    exit(0);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while(1);

    return 0;
}