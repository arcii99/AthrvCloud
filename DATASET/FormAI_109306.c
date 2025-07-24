//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
#include<stdio.h>
#include<math.h>

int main()
{
    float principal, rate, time, emi, interest, total_amount, monthly_interest;
    int total_months;

    printf("Welcome to the Mortgage Calculator\n\n");
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the rate of interest: ");
    scanf("%f", &rate);

    printf("Enter the repayment time in months: ");
    scanf("%f", &time);

    monthly_interest = rate / 1200;
    total_months = time;
    emi = (principal*monthly_interest*pow(1+monthly_interest, total_months))/(pow(1+monthly_interest, total_months)-1);
    total_amount = emi * total_months;
    interest = total_amount - principal;

    printf("\n");
    printf("Principal Amount: $%.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", rate);
    printf("Repayment Time: %.0f months\n\n", time);
    printf("Monthly Payment: $%.2f\n", emi);
    printf("Total Interest Paid: $%.2f\n", interest);
    printf("Total amount to be paid: $%.2f\n", total_amount);

    return 0;
}