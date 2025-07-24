//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: accurate
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, years;
    int period;

    // Get user input for principal, rate, and years
    printf("Enter principal amount: ");
    scanf("%f", &principal);
    printf("Enter annual interest rate: ");
    scanf("%f", &rate);
    printf("Enter total number of years: ");
    scanf("%f", &years);
    
    // Convert years to months
    period = years * 12;

    // Calculate monthly interest rate
    float monthly_rate = (rate / 100) / 12;

    // Calculate monthly payment
    float numerator = monthly_rate * pow(1 + monthly_rate, period);
    float denominator = pow(1 + monthly_rate, period) - 1;
    float monthly_payment = principal * (numerator / denominator);

    // Output monthly payment to user
    printf("Your monthly payment is: $%.2f\n", monthly_payment);

    return 0;
}