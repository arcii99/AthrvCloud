//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

int main()
{
    double principal, interest_rate, monthly_payment, remaining_balance, total_interest_paid;
    int num_of_months = 0;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the annual interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter the monthly payment amount: ");
    scanf("%lf", &monthly_payment);

    
    interest_rate = interest_rate / (12*100); // converting annual rate to monthly rate
    remaining_balance = principal; //initialize the remaining balance as principal

    printf("\nMonth\t Payment\t Balance\n");

    while (remaining_balance > 0)
    {
        num_of_months++;

        if (remaining_balance < monthly_payment)
        {
            monthly_payment = remaining_balance; // pay remainder amount if remaining balance is less than monthly payment
            remaining_balance = 0;
        }
        else
        {
            remaining_balance = remaining_balance * (1 + interest_rate) - monthly_payment;
        }
        total_interest_paid += (remaining_balance < 0 ? monthly_payment + remaining_balance : monthly_payment) * interest_rate;
        
        printf("%d\t $%.2lf\t $%.2lf\n", num_of_months, monthly_payment, remaining_balance);
    }
    
    printf("\nIt takes %d months to pay off the loan.\n", num_of_months);
    printf("Total interest paid is $%.2lf.\n", total_interest_paid);

    return 0;
}