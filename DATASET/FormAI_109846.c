//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: dynamic
#include<stdio.h>
#include<math.h>

int main()
{
    float principal,rate,time;
    float monthlyPayment,totalPayment,interest;
    printf("Enter principal amount: ");
    scanf("%f",&principal);
    printf("Enter annual interest rate: ");
    scanf("%f",&rate);
    printf("Enter time in years: ");
    scanf("%f",&time);

    //calculating monthly interest rate
    float monthlyRate = rate/1200;

    //calculating monthly payment
    monthlyPayment = principal*monthlyRate/(1-pow(1+monthlyRate,-12*time));

    //calculating total payment
    totalPayment = monthlyPayment*12*time;

    //calculating total interest
    interest = totalPayment - principal;

    //printing results
    printf("\n\nMortgage Calculation Results\n");
    printf("---------------------------\n");
    printf("Principal: %.2f\n",principal);
    printf("Annual Interest Rate: %.2f\n",rate);
    printf("Time (in years): %.2f\n",time);
    printf("Monthly Payment: %.2f\n",monthlyPayment);
    printf("Total Payment: %.2f\n",totalPayment);
    printf("Total Interest: %.2f\n",interest);

    return 0;
}