//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>
#include <math.h>

int main() {
    float principle, rate, time, emi, interest, total_amount;
    char option;

    printf("\n----------------------");
    printf("\nMORTGAGE CALCULATOR");
    printf("\n----------------------");

    // Read user input
    printf("\nEnter the principle amount: ");
    scanf("%f", &principle);

    printf("\nEnter the interest rate: ");
    scanf("%f", &rate);

    printf("\nEnter the time period (in years): ");
    scanf("%f", &time);

    // Calculate monthly interest rate
    float r = rate/(12*100);

    // Calculate monthly payment
    emi = (principle*r*pow(1+r, time*12))/(pow(1+r, time*12)-1);

    // Calculate total amount paid
    total_amount = emi*time*12;

    // Display results
    printf("\nMonthly EMI: $%.2f", emi);
    printf("\nTotal amount paid: $%.2f", total_amount);

    // Ask user if they want to see extra details
    printf("\n\nDo you want to see the complete amortization schedule? (Y/N): ");
    scanf(" %c", &option);

    // Display extra details
    if (option == 'Y' || option == 'y') {
        printf("\n--------------------");
        printf("\nAMORTIZATION SCHEDULE");
        printf("\n--------------------");

        printf("\nMonth\t\tInterest\t\tPrincipal\t\tBalance");

        float balance = principle;
        for (int i = 1; i <= time*12; i++) {
            // Calculate monthly interest
            interest = balance*r;
            // Calculate monthly principal
            float principal = emi - interest;
            // Calculate balance at end of month
            balance -= principal;
            // Display details for current month
            printf("\n%i\t\t%.2f\t\t%.2f\t\t%.2f", i, interest, principal, balance);
        }
    }

    printf("\n\nThank you for using our mortgage calculator! :)");
    return 0;
}