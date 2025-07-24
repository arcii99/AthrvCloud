//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Dennis Ritchie
#include <stdio.h>

int main()
{
    double principal, rate, time, monthly_payment, total_payment, interest;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate: ");
    scanf("%lf", &rate);

    printf("Enter the time (in months): ");
    scanf("%lf", &time);

    rate /= 1200; // converting %p.a. to monthly interest rate

    // Calculate monthly payment amount
    monthly_payment = (principal * rate) / (1 - pow(1 + rate, -time));

    // Calculate total payment and interest amount
    total_payment = monthly_payment * time;
    interest = total_payment - principal;

    // Display monthly payment, total payment and interest amount
    printf("\nMonthly Payment: $%.2lf\n", monthly_payment);
    printf("Total Payment: $%.2lf\n", total_payment);
    printf("Interest Amount: $%.2lf\n", interest);

    return 0;
}