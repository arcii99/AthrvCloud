//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Claude Shannon
// This program calculates the monthly mortgage payments for a given loan amount using Claude Shannon's concept of Information Theory

#include <stdio.h>
#include <math.h>

int main()
{
    // declare variables
    float loan_amount, interest_rate, monthly_rate, term_years, term_months;
    float monthly_payment, total_payment, interest_payment, principal_payment;
    int num_payments;

    // get user input
    printf("Enter the loan amount in dollars: ");
    scanf("%f", &loan_amount);

    printf("Enter the interest rate (APR): ");
    scanf("%f", &interest_rate);

    printf("Enter the loan term in years: ");
    scanf("%f", &term_years);

    // calculate monthly interest rate
    monthly_rate = (interest_rate / 100.0) / 12.0;

    // calculate total number of payments
    num_payments = term_years * 12;

    // calculate monthly payment
    monthly_payment = (loan_amount * monthly_rate) / (1.0 - pow(1.0 + monthly_rate, -num_payments));

    // calculate total payment
    total_payment = monthly_payment * num_payments;

    // calculate total interest paid
    interest_payment = total_payment - loan_amount;

    // print results
    printf("\nMortgage Payment Calculator\n");
    printf("--------------------------\n");
    printf("Loan Amount: $%.2f\n", loan_amount);
    printf("Interest Rate: %.2f%%\n", interest_rate);
    printf("Loan Term: %.0f years\n", term_years);
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Total Payment: $%.2f\n", total_payment);
    printf("Total Interest Paid: $%.2f\n", interest_payment);

    // calculate Shannon's entropy for loan amount
    float p = (loan_amount / total_payment);
    float entropy = -p * log2(p) - (1.0 - p) * log2(1.0 - p);
    printf("\nShannon's Entropy for Loan Amount: %.2f bits\n", entropy);

    // calculate Shannon's entropy for interest rate
    p = (interest_rate / 100.0);
    entropy = -p * log2(p) - (1.0 - p) * log2(1.0 - p);
    printf("Shannon's Entropy for Interest Rate: %.2f bits\n", entropy);

    // calculate Shannon's entropy for loan term
    term_months = term_years * 12.0;
    p = (term_months / (float)num_payments);
    entropy = -p * log2(p) - (1.0 - p) * log2(1.0 - p);
    printf("Shannon's Entropy for Loan Term: %.2f bits\n", entropy);

    // calculate Shannon's entropy for monthly payment
    float payment_range = monthly_payment * 0.1;    // range is 10% of monthly payment
    float min_payment = monthly_payment - payment_range;
    float max_payment = monthly_payment + payment_range;
    p = ((max_payment - min_payment) / monthly_payment);
    entropy = -p * log2(p) - (1.0 - p) * log2(1.0 - p);
    printf("Shannon's Entropy for Monthly Payment: %.2f bits\n", entropy);

    // calculate Shannon's entropy for total payment
    float total_range = total_payment * 0.1;    // range is 10% of total payment
    float min_total = total_payment - total_range;
    float max_total = total_payment + total_range;
    p = ((max_total - min_total) / total_payment);
    entropy = -p * log2(p) - (1.0 - p) * log2(1.0 - p);
    printf("Shannon's Entropy for Total Payment: %.2f bits\n", entropy);

    return 0;
}