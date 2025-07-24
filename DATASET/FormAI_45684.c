//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: standalone
#include <stdio.h>
#include <math.h>

int main()
{
    double principal, rate, interest, monthly_payment, balance;
    int num_of_payments;

    printf("Enter principal amount: $");
    scanf("%lf", &principal);

    printf("Enter interest rate per year (in percentage): ");
    scanf("%lf", &rate);

    printf("Enter number of payments: ");
    scanf("%d", &num_of_payments);

    rate /= 100.0;

    interest = rate / 12.0;

    monthly_payment = (interest * principal) / (1.0 - pow(1.0 + interest, -num_of_payments));

    printf("\n");

    printf("Principal amount: $%.2lf\n", principal);
    printf("Annual interest rate: %.2lf%%\n", rate * 100.0);
    printf("Number of payments: %d\n\n", num_of_payments);

    printf("Monthly Payment: $%.2lf\n", monthly_payment);

    printf("\nAmortization Schedule:\n\n");
    printf("Payment\tInterest\tPrincipal\tBalance\n");

    balance = principal;

    for(int i = 1; i <= num_of_payments; i++)
    {
        double monthly_interest = balance * interest;
        double monthly_principal = monthly_payment - monthly_interest;
        balance -= monthly_principal;
        printf("%d\t%.2lf\t\t%.2lf\t\t%.2lf\n", i, monthly_interest, monthly_principal, balance);
    }

    return 0;
}