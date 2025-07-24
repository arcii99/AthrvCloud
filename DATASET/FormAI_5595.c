//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: happy
#include <stdio.h>
#include <math.h>

int main() {
    float loan_amount, interest_rate, monthly_payment, total_interest;
    int loan_term, num_payments;

    // get loan details from user
    printf("Welcome to the Mortgage Calculator!\n");
    printf("Please enter the loan amount: ");
    scanf("%f", &loan_amount);
    printf("Please enter the interest rate (as a percentage): ");
    scanf("%f", &interest_rate);
    printf("Please enter the loan term (in years): ");
    scanf("%d", &loan_term);

    // calculate monthly payment
    num_payments = loan_term * 12;
    interest_rate = interest_rate / 100 / 12;
    monthly_payment = loan_amount * (interest_rate * pow(1 + interest_rate, num_payments)) / (pow(1 + interest_rate, num_payments) - 1);

    // calculate total interest paid
    total_interest = (monthly_payment * num_payments) - loan_amount;

    // display results to user
    printf("\nThank you! Here are your results:\n");
    printf("Loan Amount: $%.2f\n", loan_amount);
    printf("Interest Rate: %.2f%%\n", interest_rate * 100 * 12);
    printf("Loan Term: %d years\n", loan_term);
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Total Interest Paid: $%.2f\n", total_interest);
    printf("We hope this has been helpful. Have a great day!\n");

    return 0;
}