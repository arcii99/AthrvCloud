//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: optimized
#include <stdio.h>
#include <math.h>

// Function to calculate Mortgage Payment
float calcMortgagePayment(float principal, float rate, int term) {
    // Convert rate to monthly
    rate /= 100.0 * 12.0;
    int numPayments = term * 12;
    float monthlyPayment = (principal * rate) / (1 - pow(1 + rate, -numPayments));
    return monthlyPayment;
}

// Function to calculate total payment
float calcTotalPayment(float principal, float rate, int term) {
    float mortgagePayment = calcMortgagePayment(principal, rate, term);
    return mortgagePayment * term * 12;
}

int main() {
    float principal, rate;
    int term;

    // Get principal, rate and term from user
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the interest rate: ");
    scanf("%f", &rate);
    printf("Enter the term (in years): ");
    scanf("%d", &term);

    // Calculate mortgage payment and total payment
    float monthlyPayment = calcMortgagePayment(principal, rate, term);
    float totalPayment = calcTotalPayment(principal, rate, term);

    // Output the calculations
    printf("Mortgage Payment: $%.2f/month\n", monthlyPayment);
    printf("Total Payment: $%.2f\n", totalPayment);

    return 0;
}