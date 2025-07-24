//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Cryptic
#include<stdio.h>
#include<math.h>

int main()
{
    float principal, rate, time, emi, interest, totalPayment;

    printf("Enter the Principal Amount: ");
    scanf("%f", &principal);

    printf("Enter the Rate of Interest (in percentage): ");
    scanf("%f", &rate);

    printf("Enter the Time Period (in years): ");
    scanf("%f", &time);

    rate = rate / (12 * 100);  // Monthly interest rate
    time = time * 12;  // Time period in months

    emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

    totalPayment = emi * time;
    interest = totalPayment - principal;

    printf("\nEMI: %.2f", emi);
    printf("\nTotal Payment: %.2f", totalPayment);
    printf("\nInterest: %.2f", interest);

    return 0;
}