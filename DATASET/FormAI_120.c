//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: interoperable
#include <stdio.h>
#include <math.h>

int main() {
    double loan_amount, interest_rate, monthly_payment, balance;
    int loan_term, i;

    // Get the user input
    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter the loan term (in years): ");
    scanf("%d", &loan_term);

    // Calculate the monthly interest rate
    interest_rate = interest_rate / 1200;

    // Calculate the monthly payment
    monthly_payment = loan_amount * (interest_rate / (1 - pow(1 + interest_rate, -loan_term * 12)));

    // Print the monthly payment
    printf("Your monthly payment is: $%.2lf\n", monthly_payment);

    // Print the amortization table
    printf("\nAmortization Table:\n");
    printf("-------------------\n");
    balance = loan_amount;
    printf("Month\tBalance\t\tPayment\t\tInterest\tPrincipal\n");
    for (i = 1; i <= loan_term * 12; i++) {
        double interest, principal;
        interest = balance * interest_rate;
        principal = monthly_payment - interest;
        balance -= principal;

        printf("%d\t$%.2lf\t$%.2lf\t\t$%.2lf\t\t$%.2lf\n", i, balance, monthly_payment, interest, principal);
    }

    return 0;
}