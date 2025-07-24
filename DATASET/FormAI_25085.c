//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: lively
#include<stdio.h>

int main()
{
    float principal, rate, time, amount, interest;
    
    printf("\nWelcome to the Mortgage Calculator");
    printf("\n---------------------------------\n");
    
    printf("Enter the principal value of your loan: ");
    scanf("%f", &principal);
    
    printf("Enter the interest rate: ");
    scanf("%f", &rate);
    
    printf("Enter the time period of loan (in years): ");
    scanf("%f", &time);
    
    interest = (principal * rate * time) / 100;
    amount = principal + interest;
    
    printf("\n=================================\n");
    printf("Loan Details\n");
    printf("=================================\n");
    
    printf("Principal Value: $%.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", rate);
    printf("Time Period: %.2f years\n", time);
    
    printf("\n=================================\n");
    printf("Mortgage Payment Details\n");
    printf("=================================\n");
    
    printf("Interest Amount: $%.2f\n", interest);
    printf("Total Amount: $%.2f\n", amount);
    
    printf("Monthly Payment: $%.2f\n", amount / (time * 12));
    
    return 0;
}