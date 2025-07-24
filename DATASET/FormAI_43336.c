//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scientific
#include<stdio.h>
#include<math.h>

int main()
{
    float principal, rate, time, emi, interest, total_amount_paid;
    int months;

    printf("Enter the loan amount: ");
    scanf("%f",&principal);

    printf("Enter the rate of interest per annum: ");
    scanf("%f",&rate);

    printf("Enter the time (in years): ");
    scanf("%f",&time);

    printf("Enter the number of months: ");
    scanf("%d",&months);

    rate = rate/(12*100); //converts yearly rate of interest to monthly rate of interest

    emi = (principal*rate*pow(1+rate,months))/((pow(1+rate,months)-1)); //calculates the monthly EMI

    total_amount_paid = emi * months; //calculates the total amount paid by the borrower

    interest = total_amount_paid - principal; //calculates the total interest paid

    printf("\nMonthly EMI is: Rs.%.2f\n",emi);

    printf("\nTotal interest paid: Rs.%.2f\n",interest);

    printf("\nTotal amount paid: Rs.%.2f\n",total_amount_paid);

    return 0;
}