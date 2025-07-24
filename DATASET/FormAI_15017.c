//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: peaceful
#include <stdio.h>
#include <math.h>

int main()
{
    // Variable declaration
    float loan_amount, interest_rate, monthly_payment, balance, monthly_interest_rate;
    int years, months, total_months;

    printf("Welcome to the Peaceful Mortgage Calculator!\n\n");

    // Input loan amount and interest rate
    printf("Please enter your loan amount (in dollars): ");
    scanf("%f", &loan_amount);

    printf("Please enter the interest rate (as a percentage): ");
    scanf("%f", &interest_rate);

    // Convert interest rate to monthly interest rate
    monthly_interest_rate = interest_rate / 1200;

    // Input loan term in years
    printf("Please enter the loan term (in years): ");
    scanf("%d", &years);

    // Calculate total months based on loan term
    total_months = years * 12;

    // Calculate monthly payment using formula
    monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -total_months));

    // Print monthly payment
    printf("\nYour monthly payment is: $%.2f\n", monthly_payment);

    // Print amortization table
    printf("\nAmortization Table:\n");
    printf("Payment #\t Payment Amount\t Interest Amount\t Principal Amount\t Loan Balance\n");

    // Loop through each month
    for(months = 1; months <= total_months; months++)
    {
        // Calculate interest amount, principal amount and balance
        float interest_amount = balance * monthly_interest_rate;
        float principal_amount = monthly_payment - interest_amount;
        balance -= principal_amount;

        // Print payment information
        printf("%d\t\t $%.2f\t\t $%.2f\t\t $%.2f\t\t $%.2f\n", months, monthly_payment, interest_amount, principal_amount, balance);

        // If loan is fully paid off
        if(balance <= 0)
        {
            printf("\nYour loan has been fully paid off! Congratulations!\n");
            break;
        }
    }

    // End program
    printf("\nThank you for using the Peaceful Mortgage Calculator. Have a nice day!\n");

    return 0;
}