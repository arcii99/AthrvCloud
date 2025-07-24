//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

float calculateMonthlyPayment(float principal, float interestRate, int numberOfYears) {
    float monthlyInterestRate = interestRate / 12.0;
    int numberOfPayments = numberOfYears * 12;
    float discountFactor = (pow((1 + monthlyInterestRate), numberOfPayments) - 1) / (monthlyInterestRate * pow((1 + monthlyInterestRate), numberOfPayments));
    float monthlyPayment = principal / discountFactor;
    return monthlyPayment;
}

int main() {

    float principal, interestRate;
    int numberOfYears;

    printf("Welcome to the Mortgage Calculator!");
    printf("\nEnter the principal amount (e.g. 100000): ");
    scanf("%f", &principal);
    printf("\nEnter the interest rate (e.g. 7.5 for 7.5%%): ");
    scanf("%f", &interestRate);
    printf("\nEnter the number of years (e.g. 15): ");
    scanf("%d", &numberOfYears);

    float monthlyPayment = calculateMonthlyPayment(principal, interestRate, numberOfYears);

    printf("\nYour monthly payment is: %.2f", monthlyPayment);

    return 0;
}