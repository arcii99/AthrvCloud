//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, years, monthly_payment, total_payment, interest_paid;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate (per annum): ");
    scanf("%f", &rate);

    printf("Enter the number of years for the loan: ");
    scanf("%f", &years);

    // convert interest rate to monthly rate
    rate = rate / (12*100);

    // calculate monthly payment
    monthly_payment = (principal * rate * pow(1+rate, years*12)) / (pow(1+rate, years*12) - 1);

    // calculate total payment
    total_payment = monthly_payment * years * 12;

    // calculate interest paid
    interest_paid = total_payment - principal;

    // display results
    printf("\nMonthly Payment: $%.2f\n", monthly_payment);
    printf("Total Payment: $%.2f\n", total_payment);
    printf("Total Interest Paid: $%.2f\n", interest_paid);

    return 0;
}