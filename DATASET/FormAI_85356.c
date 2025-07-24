//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: sophisticated
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, payment;
    int years, payments_per_year;
    float numerator, denominator, intermediate;
    
    printf("Welcome to the Mortgage Calculator!\n");
    printf("Please enter the principal amount: ");
    scanf("%f", &principal);
    
    printf("Please enter the annual interest rate (as a decimal): ");
    scanf("%f", &rate);
    
    printf("Please enter the length of the mortgage (in years): ");
    scanf("%d", &years);
    
    printf("Please enter the number of payments you will make per year: ");
    scanf("%d", &payments_per_year);
    
    rate /= payments_per_year;
    years *= payments_per_year;
    
    numerator = rate * pow((1 + rate), years);
    denominator = pow((1 + rate), years) - 1;
    intermediate = numerator / denominator;
    payment = principal * intermediate;
    
    printf("\n\n");
    printf("Mortgage Summary:\n");
    printf("Principal Amount: %.2f\n", principal);
    printf("Annual Interest Rate: %.3f\n", rate);
    printf("Number of Payments: %d\n", years);
    printf("Payments per Year: %d\n", payments_per_year);
    printf("Monthly Payment: $%.2f\n", payment);
    
    return 0;
}