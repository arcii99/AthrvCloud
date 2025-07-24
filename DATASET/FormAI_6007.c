//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Ken Thompson
#include <stdio.h>

float calculateMortgage(float p, float r, int n) {
    float monthlyRate = r / 1200;
    return p * monthlyRate / (1 - (float)pow(1 + monthlyRate, -n));
}

int main() {
    float principal, rate;
    int years;
    printf("Enter principal amount: ");
    scanf("%f", &principal);
    printf("Enter interest rate per year: ");
    scanf("%f", &rate);
    printf("Enter number of years: ");
    scanf("%d", &years);

    float mortgage = calculateMortgage(principal, rate, years * 12);
    printf("\nMortgage Payment: $%.2f\n", mortgage);
    return 0;
}