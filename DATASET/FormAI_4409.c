//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: grateful
#include <stdio.h>
#include <math.h>

// Function to calculate the monthly mortgage payment
float mortgagePayment(float principal, float interest_rate, int number_of_payments)
{
    float monthly_interest_rate = interest_rate / 1200;
    float numerator = principal * monthly_interest_rate * pow(1 + monthly_interest_rate, number_of_payments);
    float denominator = pow(1 + monthly_interest_rate, number_of_payments) - 1;
    return numerator / denominator;
}

int main()
{
    printf("Welcome to the Mortgage Calculator!\n\n");

    // Get the principal amount
    float principal;
    printf("Please enter the principal amount (e.g. 250000.00): ");
    scanf("%f", &principal);

    // Get the annual interest rate
    float interest_rate;
    printf("Please enter the annual interest rate (e.g. 5.25 for 5.25%%): ");
    scanf("%f", &interest_rate);

    // Get the number of years for the mortgage term
    int years;
    printf("Please enter the number of years for the mortgage term: ");
    scanf("%d", &years);

    // Calculate the number of payments
    int number_of_payments = years * 12;

    // Calculate the monthly mortgage payment
    float monthly_payment = mortgagePayment(principal, interest_rate, number_of_payments);

    // Print the results
    printf("\nYour monthly mortgage payment is: $%.2f\n", monthly_payment);

    return 0;
}