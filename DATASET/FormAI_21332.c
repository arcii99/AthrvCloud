//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: unmistakable
#include <stdio.h>
#include <math.h>

int main() {
    float loan_amount, interest_rate, monthly_interest_rate, home_insurance, property_tax, principal, interest, monthly_payment;
    int mortgage_term, num_payments;

    // Input loan details
    printf("Enter loan amount: ");
    scanf("%f", &loan_amount);

    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter mortgage term in years: ");
    scanf("%d", &mortgage_term);

    printf("Enter home insurance amount: ");
    scanf("%f", &home_insurance);

    printf("Enter annual property tax: ");
    scanf("%f", &property_tax);

    // Calculate monthly interest rate and number of payments
    monthly_interest_rate = interest_rate / (12 * 100);
    num_payments = mortgage_term * 12;

    // Calculate monthly payment
    principal = loan_amount;
    interest = 0;
    monthly_payment = (principal * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -num_payments));
    printf("Monthly payment: $%.2f\n", monthly_payment);

    // Calculate total cost of the loan
    float total_interest = 0;
    for (int i = 1; i <= num_payments; i++) {
        interest = principal * monthly_interest_rate;
        total_interest += interest;
        principal = principal - (monthly_payment - interest);
    }

    float total_cost = loan_amount + total_interest + home_insurance + (property_tax * mortgage_term);
    printf("Total cost of the loan: $%.2f\n", total_cost);

    return 0;
}