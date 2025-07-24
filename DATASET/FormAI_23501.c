//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Mortgage Calculator!\n\n");

    double loan_amount, interest_rate, monthly_payment, remaining_balance, total_interest = 0;
    int mortgage_term, i = 1;

    printf("Please enter the loan amount: $");
    scanf("%lf", &loan_amount);

    printf("Please enter the interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Please enter the mortgage term (in years): ");
    scanf("%d", &mortgage_term);

    int num_payments = 12 * mortgage_term;

    double monthly_rate = (interest_rate / 100) / 12;
    double power = pow(1 + monthly_rate, num_payments);

    monthly_payment = (loan_amount * (monthly_rate * power)) / (power - 1);

    remaining_balance = loan_amount;

    printf("\nMonthly Payment: $%.2f\n\n", monthly_payment);

    printf("\nMonth\t\tPayment\t\tRemaining Balance\n");

    while(i <= num_payments) {

        double interest = remaining_balance * monthly_rate;

        double principal = monthly_payment - interest;

        remaining_balance = remaining_balance - principal;

        total_interest = total_interest + interest;

        printf("%d\t\t$%.2lf\t\t$%.2lf\n", i, monthly_payment, remaining_balance);

        i++;
    }

    printf("\nTotal Interest: $%.2lf\n", total_interest);

    return 0;
}