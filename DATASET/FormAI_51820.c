//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complete
#include <stdio.h>
#include <math.h>

int main() {

    // defining variables
    double loan_amount, interest_rate, monthly_rate, num_payments, monthly_payment, total_interest;
    int years;

    // getting user input for loan amount, interest rate, and loan duration
    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter the duration of the loan (in years): ");
    scanf("%d", &years);

    // converting interest rate from percentage to decimal
    interest_rate = interest_rate / 100;

    // calculating monthly interest rate and number of payments
    monthly_rate = interest_rate / 12;
    num_payments = years * 12;

    // calculating monthly payment and total interest
    monthly_payment = (loan_amount * pow(1 + monthly_rate, num_payments) * monthly_rate) / (pow(1 + monthly_rate, num_payments) - 1);
    total_interest = monthly_payment * num_payments - loan_amount;

    // displaying results to user
    printf("\nLoan amount: $%.2lf\n", loan_amount);
    printf("Interest rate: %.2lf%%\n", interest_rate * 100);
    printf("Loan duration: %d years\n", years);
    printf("Monthly payment: $%.2lf\n", monthly_payment);
    printf("Total interest: $%.2lf\n", total_interest);

    return 0;
}