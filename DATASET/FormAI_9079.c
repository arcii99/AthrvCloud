//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include<stdio.h>
#include<math.h>

int main()
{
    float amount, interest, monthly_interest_rate, payment, monthly_payment, principal, total_interest;
    int tenure, n;

    printf("Enter the amount of the mortgage: ");
    scanf("%f", &amount);

    printf("Enter the interest rate: ");
    scanf("%f", &interest);

    printf("Enter the tenure (in years): ");
    scanf("%d", &tenure);

    printf("Calculating the monthly payment for a mortgage of %.2f for %d years at %.2f interest rate\n", amount, tenure, interest);

    n = tenure*12;
    monthly_interest_rate = interest/(12*100);

    payment = (amount*monthly_interest_rate*pow(1+monthly_interest_rate,n))/(pow(1+monthly_interest_rate,n)-1);

    principal = payment/monthly_interest_rate;
    total_interest = n*payment-principal;

    printf("Monthly Payment: $%.2f\n", payment);
    printf("Total Principal paid: $%.2f\n", principal);
    printf("Total Interest paid: $%.2f\n", total_interest);

    return 0;
}