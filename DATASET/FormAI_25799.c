//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complete
#include <stdio.h>
#include <math.h>

int main()
{
    //declaring variables
    double principle, interest_rate, monthly_interest_rate, payment, balance, monthly_payment, total_interest;
    int years, months, total_months;

    //taking input from user
    printf("Enter loan amount: ");
    scanf("%lf", &principle);
    printf("Enter interest rate (percent): ");
    scanf("%lf", &interest_rate);
    printf("Enter years of loan: ");
    scanf("%d", &years);

    //converting years to months
    total_months = years * 12;

    //converting interest rate to monthly interest rate
    monthly_interest_rate = interest_rate / 1200;

    //calculating monthly payment
    monthly_payment = (principle * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -total_months));

    //calculating total interest and remaining balance for each month
    balance = principle;    //starting balance
    total_interest = 0;     //total interest
    printf("\nPayment Schedule\n");
    printf("=================\n");
    for(int i=1; i<=total_months; i++)
    {
        //calculating payment for each month
        payment = monthly_payment;
        if(balance < monthly_payment)
        {
            payment = balance + (balance * monthly_interest_rate);
        }
        //calculating interest for each month
        double interest = balance * monthly_interest_rate;
        total_interest += interest;
        //calculating remaining balance for each month
        balance -= payment - interest;
        //converting remaining balance to positive if it is negative
        if(balance < 0)
        {
            balance = fabs(balance);
        }
        //displaying payment, interest, and remaining balance for each month
        printf("Month %d - Payment: $%.2lf, Interest: $%.2lf, Balance: $%.2lf\n", i, payment, interest, balance);
    }
    //displaying total interest paid and monthly payment
    printf("\nTotal Interest Paid: $%.2lf", total_interest);
    printf("\nMonthly Payment: $%.2lf", monthly_payment);

    return 0;
}