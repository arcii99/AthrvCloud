//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: calm
#include <stdio.h>
#include <math.h>

int main() {
    double P, r, n, m;
    double monthly_payment, total_payment, total_interest;
    int option;

    printf("========== Mortgage Calculator ==========\n\n");

    // Get user input
    printf("Enter the loan amount (P): ");
    scanf("%lf", &P);
    printf("Enter the annual interest rate (r): ");
    scanf("%lf", &r);
    printf("Enter the loan term (n) in years: ");
    scanf("%lf", &n);

    // Convert years to months
    m = n * 12;

    // Print menu
    printf("\nChoose payment frequency:\n");
    printf("  1. Monthly\n");
    printf("  2. Bi-Monthly\n");
    printf("  3. Quarterly\n");
    printf("  4. Semi-Annually\n");
    printf("  5. Annually\n");
    printf("Enter option: ");
    scanf("%d", &option);

    // Determine payment period
    switch(option) {
        case 1:
            m = m * 1; // monthly, no change necessary
            break;
        case 2:
            m = m / 2; // bi-monthly, divide by 2
            break;
        case 3:
            m = m / 3; // quarterly, divide by 3
            break;
        case 4:
            m = m / 6; // semi-annually, divide by 6
            break;
        case 5:
            m = m / 12; // annually, divide by 12
            break;
        default:
            printf("Invalid option\n");
            return 0;
    }

    // Calculate monthly payment
    double i = r / 100 / 12;
    double tmp = pow(1 + i, m);
    monthly_payment = P * i * tmp / (tmp - 1);

    // Calculate total payment and total interest
    total_payment = monthly_payment * m;
    total_interest = total_payment - P;

    // Print results
    printf("\n========== Mortgage Summary ==========\n\n");
    printf("Loan amount: $%.2lf\n", P);
    printf("Interest rate: %.2lf%%\n", r);
    printf("Loan term: %.0lf years\n", n);
    printf("Payment frequency: ");

    switch(option) {
        case 1:
            printf("Monthly\n");
            break;
        case 2:
            printf("Bi-Monthly\n");
            break;
        case 3:
            printf("Quarterly\n");
            break;
        case 4:
            printf("Semi-Annually\n");
            break;
        case 5:
            printf("Annually\n");
            break;
        default:
            break;
    }

    printf("Monthly payment: $%.2lf\n", monthly_payment);
    printf("Total payment: $%.2lf\n", total_payment);
    printf("Total interest: $%.2lf\n", total_interest);

    return 0;
}