//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float loan, interest_rate, payment, principle, monthly_interest, balance;
    int term;

    printf("Enter the loan amount: ");
    scanf("%f", &loan);
    printf("Enter the annual interest rate (in decimal form): ");
    scanf("%f", &interest_rate);
    printf("Enter the loan term (in years): ");
    scanf("%d", &term);

    principle = loan;
    monthly_interest = interest_rate / 12;
    term *= 12;

    payment = (monthly_interest * principle) / (1 - pow(1 + monthly_interest, -term));
    balance = principle;

    printf("\nMonthly Payment: %.2f\n", payment);

    printf("\nAmortization Schedule:\n");
    printf("%15s %15s %15s %15s\n", "Payment #", "Payment Amt", "Interest", "Balance");

    for(int i = 1; i <= term; i++)
    {
        float interest = monthly_interest * balance;
        float principle_paid = payment - interest;

        printf("%15d %15.2f %15.2f %15.2f\n", i, payment, interest, balance);

        balance -= principle_paid;

        if(balance <= 0) break;
    }

    return 0;
}