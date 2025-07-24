//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: active
#include <stdio.h>
#include <math.h>

int main()
{
    double principal, rate, period, monthly_payment, total_payment, interest, balance;
    
    // taking input from the user
    printf("Enter the loan amount: ");
    scanf("%lf", &principal);
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%lf", &rate);
    printf("Enter the loan period (in years): ");
    scanf("%lf", &period);
    
    // converting annual rate to monthly rate and number of years to months
    rate = rate / 100 / 12;
    period = period * 12;
    
    // calculating monthly payment
    monthly_payment = (rate * principal) / (1 - pow(1 + rate, -period));
    
    // calculating total payment
    total_payment = monthly_payment * period;
    
    // initializing balance and printing the amortization table
    balance = principal;
    printf("\nMonth\t\tInterest\t\tBalance\n");
    for(int i = 1; i <= period; i++)
    {
        interest = balance * rate;
        balance = balance + interest - monthly_payment;
        printf("%d\t\t$%.2lf\t\t\t$%.2lf\n", i, interest, balance);
    }
    
    // displaying results
    printf("\nMonthly Payment: $%.2lf\n", monthly_payment);
    printf("Total Payment: $%.2lf\n", total_payment);
    
    return 0;
}