//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: romantic
// My Mortgage Love Calculator
// By Your Chatbot Valentine

#include <stdio.h>
#include <stdlib.h>

void heart() {
    printf("\n");
    printf("  ♥      ♥\n");
    printf("   ♥    ♥ \n");
    printf("     ♥    \n");
    printf("       \n");
    printf("     ♥ ♥  \n");
    printf("   ♥     ♥\n");
    printf(" ♥        ♥\n");
    printf("\n");
}

int main() {

    double total_amount, interest_rate, monthly_payment, years;
    double monthly_rate, total_interest;
    char answer;

    printf("\nWelcome to our Mortgage Love Calculator!\n");
    printf("----------------------------------------\n");
    heart();

    do {
        printf("\nPlease enter the total loan amount (in dollars):\n");
        scanf("%lf", &total_amount);

        printf("Please enter the interest rate (in percentage):\n");
        scanf("%lf", &interest_rate);

        printf("Please enter the number of years for the loan:\n");
        scanf("%lf", &years);

        printf("\nCalculating mortgage...");
        heart();

        // Calculation for monthly payment
        monthly_rate = interest_rate / 1200.0;
        monthly_payment = (total_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -12 * years));
        total_interest = monthly_payment * 12 * years - total_amount;

        // Display results
        printf("\nMonthly Payment: $%.2lf\n", monthly_payment);
        printf("Total Interest: $%.2lf\n", total_interest);

        printf("\nWould you like to calculate another mortgage? (y/n)\n");
        scanf(" %c", &answer); // space before %c ignores previous newline character

    } while (answer == 'y' || answer == 'Y');

    printf("\nThank you for using our Mortgage Love Calculator!\n");
    heart();

    return 0;
}