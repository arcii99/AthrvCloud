//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>

int main() {
    // Declare variables
    float salary, expenses, savings, rent, utilities, food, transportation;
    char cont = 'y';

    printf("Welcome to the Personal Finance Planner!\n");

    // Keep prompting user to input values until they decide to stop
    while (cont == 'y') {
        // Get user input
        printf("\nEnter your monthly salary: $");
        scanf("%f", &salary);
        printf("Enter your monthly expenses:\n");
        printf("\tRent/mortgage: $");
        scanf("%f", &rent);
        printf("\tUtilities: $");
        scanf("%f", &utilities);
        printf("\tFood: $");
        scanf("%f", &food);
        printf("\tTransportation: $");
        scanf("%f", &transportation);

        // Calculate savings and display result
        expenses = rent + utilities + food + transportation;
        savings = salary - expenses;
        printf("\nYour monthly savings: $%.2f\n", savings);

        // Prompt user to continue or not
        printf("\nWould you like to calculate again? (y/n): ");
        scanf(" %c", &cont); // Use space before %c to ignore whitespace character
    }

    printf("\nThank you for using the Personal Finance Planner!\n");

    return 0;
}