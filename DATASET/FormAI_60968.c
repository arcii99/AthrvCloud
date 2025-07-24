//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: high level of detail
#include <stdio.h>
#include <math.h>

int main()
{
    double principal, interest_rate, monthly_rate, monthly_payment, balance, total_paid, total_interest;
    int years, num_payments, month;

    printf("Enter principal amount: ");
    scanf("%lf", &principal);

    printf("Enter interest rate: ");
    scanf("%lf", &interest_rate);
    
    printf("Enter number of years: ");
    scanf("%d", &years);

    monthly_rate = interest_rate / 1200;
    num_payments = years * 12;
    monthly_payment = (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -num_payments));
    balance = principal;
    total_paid = 0.0;
    total_interest = 0.0;

    printf("\nAmortization Table:\n");
    printf("Month   Payment   Interest   Principal   Balance\n");

    for (month = 1; month <= num_payments; month++)
    {
        double interest = balance * monthly_rate;
        double principle = monthly_payment - interest;
        balance -= principle;
        total_paid += monthly_payment;
        total_interest += interest;

        printf("%d.    $%6.2lf    $%6.2lf    $%6.2lf    $%10.2lf\n", month, monthly_payment, interest, principle, balance);

        if (balance < 0.01)
        {
            break; // The balance is paid off
        }
    }

    printf("\nTotal monthly payment: $%6.2lf\n", monthly_payment);
    printf("Total amount paid: $%6.2lf\n", total_paid);
    printf("Total interest paid: $%6.2lf\n", total_interest);

    return 0;
}