//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salary, expenses, savings;
    int option;

    printf("---------- PERSONAL FINANCE PLANNER ----------\n\n");
    printf("Please enter your monthly salary: $");
    scanf("%f", &salary);
    printf("Please enter your monthly expenses: $");
    scanf("%f", &expenses);

    savings = salary - expenses;
    printf("\nYour monthly savings is: $%.2f\n\n", savings);

    printf("What would you like to do?\n");
    printf("1. Calculate your annual savings\n");
    printf("2. Determine if you can afford to make a large purchase\n");
    printf("3. Exit program\n");
    scanf("%d", &option);

    switch (option) {
        case 1: 
            printf("Your annual savings is: $%.2f\n", (savings * 12));
            break;
        case 2:
            float purchase_cost, months_saved;
            printf("Please enter the cost of the large purchase: $");
            scanf("%f", &purchase_cost);
            months_saved = purchase_cost / savings;
            if (months_saved > 12) {
                printf("Sorry, it will take more than a year to save enough for this purchase.\n");
            } else {
                printf("You can afford this purchase in %.0f months.\n", months_saved);
            }
            break;
        case 3:
            printf("Thank you for using the Personal Finance Planner.\n");
            exit(0);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    return 0;
}