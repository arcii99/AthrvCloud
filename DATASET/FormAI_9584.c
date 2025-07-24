//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: secure
#include <stdio.h>
#include <math.h>

int main() {
    double principal, interest_rate, amount, monthly_payment, balance, total_interest;
    int no_of_years, no_of_months, i;

    // get input values
    printf("Enter loan principal: ");
    scanf("%lf", &principal);
    printf("Enter interest rate (per annum): ");
    scanf("%lf", &interest_rate);
    printf("Enter number of years: ");
    scanf("%d", &no_of_years);

    // calculate monthly interest rate, no of months, and amount
    double monthly_interest_rate = interest_rate / (12 * 100);
    no_of_months = no_of_years * 12;
    amount = principal * pow((1 + monthly_interest_rate), no_of_months);

    // calculate monthly payment
    monthly_payment = amount / no_of_months;

    // print details
    printf("\nLoan details:\n");
    printf("Principal: %.2lf\n", principal);
    printf("Interest rate (per annum): %.2lf%%\n", interest_rate);
    printf("Number of years: %d\n", no_of_years);
    printf("Monthly payment: $%.2lf\n", monthly_payment);
    printf("Total payment: $%.2lf\n", monthly_payment * no_of_months);

    // calculate and print the amortization table
    printf("\nAmortization table:\n");
    printf("Month\tBalance\t\tPayment\t\tInterest\tPrincipal\n");

    balance = principal;

    for (i = 1; i <= no_of_months; i++) {
        // calculate interest and principal for the current month
        double interest = balance * monthly_interest_rate;
        double principal = monthly_payment - interest;

        // update balance and total interest
        balance = balance - principal;
        total_interest += interest;

        printf("%d\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", i, balance, monthly_payment, interest, principal);
    }

    printf("\nTotal interest paid: $%.2lf\n", total_interest);

    return 0;
}