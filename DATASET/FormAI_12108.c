//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, time;
    
    printf("Welcome to the Mortgage Calculator!\n\n");
    printf("Please enter the principal amount: ");
    scanf("%f", &principal);
    
    printf("Please enter the annual interest rate (in percentage): ");
    scanf("%f", &rate);
    
    printf("Please enter the time (in years): ");
    scanf("%f", &time);
    
    float monthly_interest = rate / 1200; // dividing by 1200 to convert interest rate from percentage to decimal
    int number_of_payments = time * 12; // multiplying by 12 to convert time from years to months
    
    // calculating monthly payment using formula
    float monthly_payment = (principal * monthly_interest * pow(1 + monthly_interest, number_of_payments)) / (pow(1 + monthly_interest, number_of_payments) - 1);
    
    printf("\nYour monthly payment is: $%.2f\n\n", monthly_payment);
    
    // displaying payment schedule
    printf("Payment Schedule:\n");
    printf("------------------\n");
    printf("%10s %10s %15s %15s %15s\n", "Month", "Payment", "Interest", "Principal", "Balance");
    
    float balance = principal;
    float total_interest = 0;
    
    for(int i=1; i<=number_of_payments; i++)
    {
        // calculating interest for the month
        float interest = balance * monthly_interest;
        
        // calculating principal for the month
        float principal_pay = monthly_payment - interest;
        
        // adjusting last payment to the remaining balance
        if(i==number_of_payments)
        {
            principal_pay = balance;
            monthly_payment = interest + principal_pay;
        }
        
        // calculating remaining balance after payment
        balance -= principal_pay;
        
        // calculating total interest paid
        total_interest += interest;
        
        printf("%10d $%-10.2f $%-15.2f $%-15.2f $%-15.2f\n", i, monthly_payment, interest, principal_pay, balance);
    }
    
    printf("\nTotal interest paid: $%.2f\n", total_interest);
    
    return 0;
}