//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Alan Touring
// Alan Turing Mortgage Calculator

#include <stdio.h>
#include <math.h>

int main(void) {
    // Initialize variables
    double principal, interest_rate, monthly_rate, payment;
    int num_payments;

    // Get user input
    printf("Welcome to the Alan Turing Mortgage Calculator.\n");
    printf("Please enter the principal amount of the loan (in dollars): ");
    scanf("%lf", &principal);
    printf("Please enter the annual interest rate (as a percentage): ");
    scanf("%lf", &interest_rate);
    printf("Please enter the number of payments (in months): ");
    scanf("%d", &num_payments);

    // Convert interest rate to monthly rate
    monthly_rate = interest_rate / (12 * 100);

    // Calculate monthly payment
    payment = (monthly_rate * principal * pow(1 + monthly_rate, num_payments)) / (pow(1 + monthly_rate, num_payments) - 1);

    // Print results
    printf("Your monthly payment will be: $%.2lf\n", payment);

    return 0;
}