//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Donald Knuth
#include <stdio.h>

int main(void) {
    float principal, rate, time;
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the annual interest rate: ");
    scanf("%f", &rate);
    printf("Enter the number of years: ");
    scanf("%f", &time);

    float monthlyRate = rate / 1200;
    float monthlyPayment = (principal * monthlyRate) / (1 - (pow(1/(1 + monthlyRate), time * 12)));
    float totalInterest = monthlyPayment * time * 12 - principal;

    printf("Monthly payment: %.2f\n", monthlyPayment);
    printf("Total interest paid: %.2f\n", totalInterest);

    return 0;
}