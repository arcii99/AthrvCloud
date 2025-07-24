//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: satisfied
#include <stdio.h>
#include <math.h>

int main()
{
    double principal, rate, years, monthly_payment, total_payment, interest;
    int num_payments;

    // taking input from user
    printf("Enter loan amount: ");
    scanf("%lf", &principal);

    printf("Enter interest rate (per year): ");
    scanf("%lf", &rate);

    printf("Enter duration of loan (in years): ");
    scanf("%lf", &years);

    // calculating the monthly interest rate
    double monthly_rate = (rate / 100) / 12;

    // calculating total number of payments
    num_payments = years * 12;

    // calculating monthly payment amount
    monthly_payment = (principal * monthly_rate * pow(1 + monthly_rate, num_payments)) / (pow(1 + monthly_rate, num_payments) - 1);

    // calculating total payment amount
    total_payment = monthly_payment * num_payments;

    // calculating interest paid
    interest = total_payment - principal;

    printf("\nMonthly Payment: $%.2lf\n", monthly_payment);
    printf("Total Payment: $%.2lf\n", total_payment);
    printf("Interest Paid: $%.2lf\n", interest);

    return 0;
}