//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Sherlock Holmes
/*The Adventure of the Mortgage Calculator*/
/*By Sherlock Holmes*/

#include<stdio.h>

int main()
{
    int principle, rate, time, emi;
    printf("Welcome to the adventure of the Mortgage Calculator!\n\n");
    printf("Please enter the Principle amount: ");
    scanf("%d", &principle);
    printf("\nExcellent! Now enter the Interest Rate: ");
    scanf("%d", &rate);
    printf("\nWonderful! Finally, how many years do you require the loan for?: ");
    scanf("%d", &time);
    printf("\nCalculating the Equated Monthly Installment\n");

    /*Calculating the EMI as per the formula onfinance formula*/
    emi = (principle * rate * ((1 + rate)^time)) / (((1+rate)^time)-1);
    
    printf("Your EMI is %d\n\n", emi);
    printf("Oh! This is brilliant. You'll have the loan paid off in no time!\n");
    
    return 0;
}