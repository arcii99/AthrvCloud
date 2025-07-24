//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: light-weight
#include<stdio.h>

int main()
{
    float principle, rate, time, interest, total;

    printf("Enter the principal amount: ");
    scanf("%f", &principle);

    printf("Enter the annual interest rate: ");
    scanf("%f", &rate);

    printf("Enter the loan term in years: ");
    scanf("%f", &time);

    interest = (principle*rate*time)/100;
    total = principle + interest;

    printf("\nTotal interest payable: $%.2f\n",interest);
    printf("Total amount payable: $%.2f\n",total);

    return 0;
}