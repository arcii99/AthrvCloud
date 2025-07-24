//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: unmistakable
#include <stdio.h>
#include <math.h>

int main() {
    // Initialize variables
    double principle, rate, years, monthlyPayment, totalPayment, interest;
    int monthlyPayments;

    // Get user input
    printf("Enter the principle: ");
    scanf("%lf", &principle);
    printf("Enter the interest rate (as a decimal): ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%lf", &years);

    // Calculate monthly interest rate and monthly number of payments
    double monthlyRate = rate / 12.0;
    monthlyPayments = (int) years * 12;

    // Calculate monthly payment
    double numerator = monthlyRate * pow(1 + monthlyRate, monthlyPayments);
    double denominator = pow(1 + monthlyRate, monthlyPayments) - 1;
    monthlyPayment = principle * numerator / denominator;

    // Calculate total payment and interest
    totalPayment = monthlyPayment * monthlyPayments;
    interest = totalPayment - principle;

    // Output results
    printf("Monthly payment: $%.2f\n", monthlyPayment);
    printf("Total payment: $%.2f\n", totalPayment);
    printf("Total interest paid: $%.2f\n", interest);

    return 0;
}