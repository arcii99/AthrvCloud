//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Ken Thompson
#include<stdio.h>

int main()
{
    float principal, rate, time, interest;
    
    printf("Enter Principal amount: ");
    scanf("%f", &principal);

    printf("Enter the rate of interest: ");
    scanf("%f", &rate);
    
    printf("Enter time in years: ");
    scanf("%f", &time);
    
    interest = (principal * rate * time) / 100;
    
    printf("\nTotal Interest: %.2f", interest);
    printf("\nTotal amount payable: %.2f", (interest+principal));

    return 0;
}