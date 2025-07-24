//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int coffee_cost = 4;
    int croissant_cost = 3;
    int sandwich_cost = 8;
    int total = 0;

    printf("**************************************\n");
    printf("Welcome to the Cafe Billing System!\n");
    printf("**************************************\n\n");

    while (1) {
        printf("What would you like to order?\n");
        printf("1. Coffee ($%d)\n", coffee_cost);
        printf("2. Croissant ($%d)\n", croissant_cost);
        printf("3. Sandwich ($%d)\n", sandwich_cost);
        printf("4. Done Ordering\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                total += coffee_cost;
                printf("You added a coffee to your order. Your total is now $%d.\n\n", total);
                break;
            case 2:
                total += croissant_cost;
                printf("You added a croissant to your order. Your total is now $%d.\n\n", total);
                break;
            case 3:
                total += sandwich_cost;
                printf("You added a sandwich to your order. Your total is now $%d.\n\n", total);
                break;
            case 4:
                printf("Thank you for your order! Your total comes out to $%d.\n", total);
                exit(0);
            default:
                printf("Invalid choice. Please choose a valid option.\n\n");
                break;
        }
    }

    return 0;
}