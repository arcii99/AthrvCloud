//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complex
#include <stdio.h>
#include <math.h>

int main()
{
    double principal, interest_rate, years, monthly_payment, total_paid, interest_paid, remaining_balance;

    printf("Please enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Please enter the interest rate (e.g. 5.5): ");
    scanf("%lf", &interest_rate);

    printf("Please enter the number of years: ");
    scanf("%lf", &years);

    double monthly_rate = interest_rate / 1200; // 12 months per year, 100 for percentage

    int months = years * 12;

    monthly_payment = principal * monthly_rate / (1 - pow(1 + monthly_rate, -months)); // formula for monthly payment

    total_paid = monthly_payment * months; // total amount paid over the life of the loan

    interest_paid = total_paid - principal; // total interest paid

    printf("\nThe monthly payment is: $%.2f", monthly_payment);
    printf("\nThe total amount paid over %d months is: $%.2f", months, total_paid);
    printf("\nThe total interest paid is: $%.2f", interest_paid);

    printf("\n\nMonth\t\tPayment\t\tInterest\tBalance\n");

    remaining_balance = principal;

    for (int i = 1; i <= months; i++)
    {
        double interest = remaining_balance * monthly_rate; // interest for the month
        double principle_paid = monthly_payment - interest; // principle paid for the month
        remaining_balance -= principle_paid; // update remaining balance
        printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", i, monthly_payment, interest, remaining_balance); // print the results
    }

    return 0;
}