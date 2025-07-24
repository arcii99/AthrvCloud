//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>
#include <math.h>

// Function to calculate mortgage payment 
double calcMortgagePayment(int principal, double interestRate, int term) {
    double r = interestRate / 1200.0; // Monthly interest rate
    int n = term * 12; // Total number of payments
    double payment = (principal * r) / (1 - pow(1 + r, -n));
    return payment;
}

int main() {
    int principal, term;
    double interestRate;

    // Get user input for mortgage information
    printf("Enter the principal amount of the mortgage: $");
    scanf("%d", &principal);
    printf("Enter the interest rate of the mortgage: ");
    scanf("%lf", &interestRate);
    printf("Enter the term of the mortgage (in years): ");
    scanf("%d", &term);

    // Calculate monthly mortgage payment
    double monthlyPayment = calcMortgagePayment(principal, interestRate, term);

    // Print results
    printf("\nFor a mortgage of $%d at an interest rate of %.2lf%% for %d years:\n", principal, interestRate, term);
    printf("The monthly mortgage payment is: $%.2lf\n", monthlyPayment);
    printf("The total amount paid over the life of the mortgage is: $%.2lf\n", monthlyPayment * (term * 12));
    printf("The total interest paid over the life of the mortgage is: $%.2lf\n", (monthlyPayment * (term * 12)) - principal);
    return 0;
}