//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scientific
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MONTHS 12 // Number of months in a year

int main() {
    int principal; // Mortgage Principal
    float interest_rate, monthly_rate; // Interest rate and Monthly Rate
    int years; // Number of years for the mortgage
    int num_payments; // Number of payments needed
    bool exit_program = false; // Flag to indicate whether to exit the program

    while (!exit_program) {
        // Prompt the user for the principal
        printf("Enter the mortgage principal (in dollars): $");
        scanf("%d", &principal);

        // Prompt the user for the annual interest rate
        printf("Enter the annual interest rate (as a percentage): ");
        scanf("%f", &interest_rate);

        // Prompt the user for the duration of the mortgage
        printf("Enter the duration of the mortgage (in years): ");
        scanf("%d", &years);

        // Convert the interest rate to a monthly rate
        monthly_rate = interest_rate / (MONTHS * 100);

        // Calculate the number of payments needed
        num_payments = years * MONTHS;

        // Calculate the monthly payment amount
        float numerator = monthly_rate * pow(1 + monthly_rate, num_payments);
        float denominator = pow(1 + monthly_rate, num_payments) - 1;
        float monthly_payment = principal * numerator / denominator;

        // Display the result
        printf("\n\n");
        printf("Mortgage Principal: $%d\n", principal);
        printf("Interest Rate: %.2f%%\n", interest_rate);
        printf("Mortgage Duration: %d years\n", years);
        printf("Number of Payments: %d\n", num_payments);
        printf("Monthly Payment: $%.2f\n", monthly_payment);

        // Ask the user if they want to calculate another mortgage
        char another_mortgage;
        printf("\nDo you want to calculate another mortgage? (Y/N) ");
        scanf(" %c", &another_mortgage);

        if (another_mortgage == 'N' || another_mortgage == 'n') {
            exit_program = true;
        }
    }

    return 0;
}