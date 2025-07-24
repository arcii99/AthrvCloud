//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: future-proof
#include <stdio.h>

int main() {
    double principal = 0.0; // Principal amount
    double interest_rate = 0.0; // Interest rate
    double num_years = 0.0; // Number of years
    double monthly_payment = 0.0; // Monthly payment
    double total_payment = 0.0; // Total payment
    double monthly_interest = 0.0; // Monthly interest rate
    int num_payments = 0; // Number of payments
 
    printf("Enter the principal amount: $"); // Prompt for principal amount
    scanf("%lf", &principal);
 
    printf("Enter the interest rate per annum: %"); // Prompt for interest rate
    scanf("%lf", &interest_rate);
 
    printf("Enter the number of years: "); // Prompt for number of years
    scanf("%lf", &num_years);
 
    monthly_interest = interest_rate / 1200; // Calculate the monthly interest rate
    num_payments = num_years * 12; // Calculate the number of payments
 
    // Use the formula to calculate monthly and total payment amount
    monthly_payment = (principal * monthly_interest) / (1 - pow(1 + monthly_interest, -num_payments));
    total_payment = monthly_payment * num_payments;
 
    // Print the output
    printf("\n");
    printf("Principal Amount: $%.2lf\n", principal);
    printf("Interest Rate: %.2lf%\n", interest_rate);
    printf("Number of Years: %.2lf\n", num_years);
    printf("Number of Monthly Payments: %d\n", num_payments);
    printf("Monthly Payment: $%.2lf\n", monthly_payment);
    printf("Total Payment: $%.2lf\n", total_payment);
 
    return 0;
}