//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: happy
#include <stdio.h>

int main()
{
    printf("Welcome to the Happy Mortgage Calculator!\n\n");
    printf("Please enter the loan principal amount: ");
    double loan_amount;
    scanf("%lf", &loan_amount);

    printf("Please enter the annual interest rate (as a percentage): ");
    double interest_rate;
    scanf("%lf", &interest_rate);

    printf("Please enter the loan term (in years): ");
    int loan_term;
    scanf("%d", &loan_term);

    double monthly_interest_rate = interest_rate / 1200.0;
    int num_payments = loan_term * 12;

    double monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -num_payments));

    printf("\nYour monthly mortgage payment will be: $%.2lf\n\n", monthly_payment);
    printf("You will make a total of %d payments and pay a total of $%.2lf over the life of the loan.\n\n", num_payments, monthly_payment * num_payments);

    printf("Thank you for using the Happy Mortgage Calculator!\n");

    return 0;
}