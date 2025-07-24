//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: peaceful
#include <stdio.h>
#include <math.h>

int main() {
    double principal, interest_rate, interest_per_month, monthly_payment;
    int loan_duration;

    printf("Welcome to the Peaceful Mortgage Calculator!\n\n");

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate (in percentage): ");
    scanf("%lf", &interest_rate);

    printf("Enter the loan duration (in years): ");
    scanf("%d", &loan_duration);

    interest_per_month = (interest_rate / 100) / 12;
    int number_of_payments = loan_duration * 12;

    // Calculate monthly payment
    monthly_payment = (principal * pow((1 + interest_per_month), number_of_payments) * interest_per_month) / (pow((1 + interest_per_month), number_of_payments) - 1);

    printf("\n\nHere's your mortgage payment:\n");
    printf("Monthly Payment: $%.2lf\n", monthly_payment);
    printf("Total Payment: $%.2lf\n", number_of_payments * monthly_payment);
    printf("Total Interest Paid: $%.2lf\n", (number_of_payments * monthly_payment) - principal);
    printf("\n\nThank you for using the Peaceful Mortgage Calculator!\n");

    return 0;
}