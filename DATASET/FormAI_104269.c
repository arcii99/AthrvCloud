//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: dynamic
#include<stdio.h>
#include<math.h>

int main()
{
    float p, r, n, emi, total_amount;
    printf("Enter the principal amount: ");
    scanf("%f",&p);
    printf("\nEnter the rate of interest: ");
    scanf("%f",&r);
    printf("\nEnter the tenure (in years): ");
    scanf("%f",&n);
    r=r/(12*100);
    n=n*12;
    emi=p*r*pow(1+r,n)/(pow(1+r,n)-1);
    total_amount=emi*n;
    printf("\nMonthly EMI : %.2f",emi);
    printf("\nTotal Amount Payable : %.2f",total_amount);
    return 0;
}