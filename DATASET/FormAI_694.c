//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: cheerful
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment, principal_amount, monthly_interest_rate, balance_owing;
    int num_payments, i;

    printf("\n\n");
    printf("***************************\n");
    printf("Welcome to the Mortgage Calculator!\n");
    printf("***************************\n\n");

    printf("Please enter the loan amount: $");
    scanf("%f", &loan_amount);

    printf("Please enter the interest rate (as a decimal): ");
    scanf("%f", &interest_rate);

    printf("Please enter the number of payments: ");
    scanf("%d", &num_payments);

    monthly_interest_rate = (interest_rate / 12);
    principal_amount = loan_amount;

    monthly_payment = (loan_amount * monthly_interest_rate) / (1 - (pow((1 + monthly_interest_rate), (-1*num_payments))));

    balance_owing = loan_amount;

    printf("\n\n");
    printf("***********************************************\n");
    printf("Your monthly payment will be: $%.2f\n", monthly_payment);
    printf("***********************************************\n\n");

    printf("Here is a breakdown of your payments:\n");

    printf("Payment Number  |  Payment Amount  |  Principal Paid  |  Interest Paid  |  Balance Owing\n");

    for (i = 1; i <= num_payments; i++) {
        float interest_paid = monthly_interest_rate * balance_owing;
        float principal_paid = monthly_payment - interest_paid;
        balance_owing -= principal_paid;

        printf("       %d               $%.2f             $%.2f            $%.2f              $%.2f\n", i, monthly_payment, principal_paid, interest_paid, balance_owing);

    }

    printf("\n\n");
    printf("*******************************************\n");
    printf("Thank you for using the Mortgage Calculator!\n");
    printf("*******************************************\n\n");

    return 0;
}