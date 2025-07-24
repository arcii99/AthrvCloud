//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: unmistakable
#include<stdio.h>
#include<math.h>

int main(){

    float loanAmount,interestRate,monthlyPayment,tempRate,tempAmount,totalInterest=0;
    int numberOfYears,totalMonths;

    printf("Enter the Loan amount: ");
    scanf("%f",&loanAmount);

    printf("Enter the Annual Interest Rate: ");
    scanf("%f",&interestRate);
    tempRate = interestRate/1200; 

    printf("Enter the Number of Years : ");
    scanf("%d",&numberOfYears);
    totalMonths = numberOfYears*12;

    tempAmount = pow((1+tempRate),totalMonths);
    monthlyPayment = (loanAmount*tempRate*tempAmount)/(tempAmount-1); 

    printf("\n");
    printf("Loan Amount: $%.2f\n",loanAmount);
    printf("Annual Interest Rate: %.2f%%\n",interestRate);
    printf("Number of Years: %d years\n",numberOfYears);
    printf("Monthly Payment: $%.2f\n",monthlyPayment);

    printf("\n");
    printf("Payment Schedule:\n");
    printf("--------------------\n");
    printf("Month\t\tPayment\t\tPrincipal\t\tInterest\t\tBalance\n");
    printf("-------------------------------------------------------------------------------\n");

    float balance = loanAmount;

    for(int i=0;i<totalMonths;i++)
    {
        float interest = balance*tempRate;
        float principal = monthlyPayment-interest;

        if(principal>balance) 
        {
            principal = balance;
            monthlyPayment = principal+interest;
        }

        balance -= principal;
        totalInterest += interest;

        printf("%d\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t\t%.2f\n",i+1,monthlyPayment,principal,interest,balance);
    }

    printf("\nTotal Interest: $%.2f\n",totalInterest);

    return 0;
}