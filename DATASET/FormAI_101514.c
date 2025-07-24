//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: energetic
// Welcome to the Mortgage Calculator!
// This program will calculate your monthly mortgage payments based on your loan amount, interest rate, and payment term

#include <stdio.h>
#include <math.h>

int main() {
    // Get user inputs
    float loan_amount, interest_rate;
    int payment_term;
    
    printf("Enter loan amount: ");
    scanf("%f", &loan_amount);
    
    printf("Enter interest rate per year (e.g. 3.5 for 3.5%%): ");
    scanf("%f", &interest_rate);
    interest_rate /= 100; // convert from percentage to decimal
    
    printf("Enter payment term in years: ");
    scanf("%d", &payment_term);
    int num_payments = payment_term * 12; // convert from years to months

    // Calculate monthly payment using formula
    float monthly_rate = interest_rate / 12.0;
    float monthly_payment = loan_amount * monthly_rate / (1.0 - pow(1.0 + monthly_rate, -num_payments));
    
    // Display results
    printf("\n--- RESULTS ---\nLoan amount: $%.2f\nInterest rate: %.2f%% per year\nPayment term: %d years\n", loan_amount, interest_rate * 100, payment_term);
    printf("Number of payments: %d\n", num_payments);
    printf("Monthly payment: $%.2f\n", monthly_payment);

    return 0;
}