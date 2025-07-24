//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

float getMonthlyPayment(float amount, float interestRate, int numberOfYears) {
    float monthlyInterestRate = interestRate / 1200;
    float num = amount * monthlyInterestRate;
    float denom = 1 - pow(1 + monthlyInterestRate, -numberOfYears * 12);
    return num / denom;
}

int main() {
    float amount, interestRate;
    int numberOfYears;

    printf("Enter the mortgage amount: ");
    scanf("%f", &amount);

    printf("Enter the interest rate (as a percentage): ");
    scanf("%f", &interestRate);

    printf("Enter the mortgage term in years: ");
    scanf("%d", &numberOfYears);

    float monthlyPayment = getMonthlyPayment(amount, interestRate, numberOfYears);

    printf("Monthly payment: $%.2f\n", monthlyPayment);
    printf("Total payment: $%.2f\n", monthlyPayment * numberOfYears * 12);
    return 0;
}