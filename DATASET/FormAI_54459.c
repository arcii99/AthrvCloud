//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: invasive
#include <stdio.h>
#include <math.h>

int main() 
{
    double loan_amount, interest_rate, monthly_payment, balance_left;
    int num_years, num_months, num_payments;

    printf("MORTGAGE CALCULATOR\n\n");
    printf("Enter loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Enter annual interest rate (e.g 5.5 for 5.5%): ");
    scanf("%lf", &interest_rate);

    printf("Enter number of years: ");
    scanf("%d", &num_years);
    num_months = num_years * 12;

    printf("Enter desired monthly payment: ");
    scanf("%lf", &monthly_payment);

    // Calculate monthly interest rate and number of payments
    double monthly_rate = interest_rate / 1200.0;
    num_payments = ceil(log10((monthly_payment / (monthly_payment - (loan_amount * monthly_rate)))) / log10(1 + monthly_rate));

    printf("\nRESULTS:\n");

    // Print out payment schedule
    balance_left = loan_amount;
    for (int i = 1; i <= num_payments; i++) {
        double interest_paid = balance_left * monthly_rate;
        double principal_paid = monthly_payment - interest_paid;
        balance_left -= principal_paid;

        printf("Month %2d : Payment:$%9.2f, Interest:$%9.2f, Principal:$%9.2f, Balance:$%10.2f\n", i, monthly_payment, interest_paid, principal_paid, balance_left);

        if (i == num_payments && balance_left > 0) {
            printf("\nWith your desired monthly payment of $%.2f, your loan will not be fully paid off after %d years.\n", monthly_payment, num_years);
        }
    }

    return 0;
}