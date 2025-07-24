//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>

int main()
{
    float principal, interest_rate, monthly_payment, balance;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter the monthly payment: ");
    scanf("%f", &monthly_payment);

    printf("\n");

    int payment_count = 0;
    balance = principal;

    printf("Payment #\tInterest Paid\tPayment Paid\tBalance\n");

    while (balance > 0)
    {
        // Calculating interest for the month
        float interest = (interest_rate / 100) / 12 * balance;

        // Calculating the payment that goes towards the principal
        float principal_payment = monthly_payment - interest;

        printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", payment_count + 1, interest, principal_payment, balance);

        balance -= principal_payment;

        // If the balance is less than the monthly payment, just pay off the balance
        if (balance < monthly_payment)
        {
            balance -= balance;
        }

        payment_count++;
    }

    printf("\nIt took %d months to pay off the mortgage.\n", payment_count);

    return 0;
}