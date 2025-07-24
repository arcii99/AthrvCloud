//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: innovative
#include<stdio.h>
#include<math.h>

int main()
{
    float loan_amount, yearly_interest_rate, monthly_interest_rate, monthly_payment, temp, balance, equity;
    int years, months, number_of_payments;

    // Input
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    printf("Enter the interest rate (yearly): ");
    scanf("%f", &yearly_interest_rate);
    printf("Enter the number of years: ");
    scanf("%d", &years);

    // Calculation
    monthly_interest_rate = yearly_interest_rate / 1200.0;
    number_of_payments = years * 12;
    temp = pow((1 + monthly_interest_rate), number_of_payments);
    monthly_payment = (loan_amount * monthly_interest_rate * temp) / (temp - 1);

    // Output
    balance = loan_amount;
    printf("\n");
    printf("|-------|---------------|--------------|--------------|-------------|\n");
    printf("| Month | Monthly Payment | Interest Paid | Principal Paid | Loan Balance |\n");
    printf("|-------|---------------|--------------|--------------|-------------|\n");
    for(months = 1;months <= number_of_payments;months++)
    {
        equity = (loan_amount - balance);
        printf("| %5d | $%11.2f | $%10.2f | $%10.2f | $%11.2f |\n", months, monthly_payment, balance * monthly_interest_rate, monthly_payment - (balance * monthly_interest_rate), balance = balance - (monthly_payment - (balance * monthly_interest_rate)));
    }
    printf("|-------|---------------|--------------|--------------|-------------|\n");
    printf("\n");
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Total Interest Paid: $%.2f\n", (monthly_payment * number_of_payments) - loan_amount);
    printf("Total Amount Paid: $%.2f\n", monthly_payment * number_of_payments);
    printf("Final Equity Value: $%.2f\n", equity);
    printf("\n");
    return 0;
}