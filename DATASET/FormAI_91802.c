//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: optimized
#include <stdio.h>
#include <math.h>

int main()
{
    float loan_amount, interest_rate, monthly_payment, principal_paid, interest_paid, remaining_balance;
    int loan_period, i;

    // Input loan data
    printf("Enter loan amount: ");
    scanf("%f", &loan_amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter loan period (in months): ");
    scanf("%d", &loan_period);

    // Calculate monthly interest rate
    float monthly_interest_rate = interest_rate / 1200;

    // Calculate monthly payment
    monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -loan_period));

    printf("\n\n");

    // Print table header
    printf("Payment\t\tPrincipal\tInterest\tBalance\n");

    // Loop through each month
    for (i = 1; i <= loan_period; ++i)
    {
        // Calculate principal and interest paid for the month
        interest_paid = remaining_balance * monthly_interest_rate;
        principal_paid = monthly_payment - interest_paid;

        // Calculate remaining balance
        remaining_balance -= principal_paid;

        // Print row for the month
        printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", i, principal_paid, interest_paid, remaining_balance);

        // If remaining balance is zero, loan is paid off
        if (remaining_balance <= 0)
        {
            printf("\nLoan paid off in %d months!\n", i);
            break;
        }
    }

    return 0;
}