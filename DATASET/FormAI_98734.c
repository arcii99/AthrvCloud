//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, time, monthly_payment;
    
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate: ");
    scanf("%f", &rate);

    printf("Enter the time (in years): ");
    scanf("%f", &time);

    rate = rate / 100;
    rate = rate / 12;

    monthly_payment = (principal * rate * pow(1 + rate, time * 12))
                      / (pow(1 + rate, time * 12) - 1);

    printf("Monthly Payment: %.2f", monthly_payment);

    return 0;
}