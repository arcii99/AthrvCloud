//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float interestRate(int n,float r)
{
    float i=0;
    i=pow((1+(r/100)),n);
    return i;
}
    
float amountPerMonth(float p,float i,float emi)
{
    float e=0;
    e=emi*((p*i)/(i-1));
    return e;
}

float totalInterest(float t,float p)
{
    float interests=0;
    interests=t-p;
    return interests;
}

void display(int y,float loanAmount,float rate,float monthly,float total,int n)
{
    printf("\nLoan Details:\n");
    printf("Loan Amount\t:\t%.2f\n",loanAmount);
    printf("Interest Rate\t:\t%.2f\n",rate);
    printf("Time Period(years):\t%d\n",y);
    printf("No of Months\t:\t%d\n",n);
    printf("Monthly Payment\t:\t%.2f\n",monthly);
    printf("Total Payment\t:\t%.2f\n",total);
}

int main()
{
    int year;
    float loan,rate,emi=1.00f;
    printf("\nEnter your Loan Amount\t\t:");
    scanf("%f",&loan);
    printf("\nWhat is Interest rate\t\t:");
    scanf("%f",&rate);
    printf("\nEnter the number of years to pay back the loan:");
    scanf("%d",&year);
    
    float r=rate/12.00,t=(float)year*12.00;
    float i=interestRate(t,r);
    float p=loan;
    
    emi=i*loan*r/100;
    float monthly=amountPerMonth(loan,i,emi);
    float total=monthly*t;

    display(year,loan,rate,monthly,total,t);

    return 0;
}