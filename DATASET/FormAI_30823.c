//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: single-threaded
#include <stdio.h>

int main() {
    double loan_amount, interest_rate, monthly_payment;

    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter the monthly payment: ");
    scanf("%lf", &monthly_payment);

    double monthly_interest = (interest_rate / 100) / 12;
    double total_interest = 0, total_loan = loan_amount;

    int month = 0;
    while (total_loan > 0) {
        month++;

        double interest = total_loan * monthly_interest;
        total_interest += interest;

        double principal = monthly_payment - interest;
        total_loan -= principal;

        if (total_loan < 0) {
            principal += total_loan;
            total_loan = 0;
        }

        printf("Month %d:\n", month);
        printf("  Payment: $%.2f\n", monthly_payment);
        printf("  Principal: $%.2f\n", principal);
        printf("  Interest: $%.2f\n", interest);

        if (total_loan == 0) {
            printf("Loan paid off in %d months.\n", month);
            printf("Total interest paid: $%.2f\n", total_interest);
        }
    }

    return 0;
}