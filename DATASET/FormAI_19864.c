//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Linus Torvalds
#include <stdio.h>

float calculateMortgage(int principal, float interestRate, int years) {
    float monthlyInterest = interestRate / 12;
    int months = years * 12;
    float mortgage = principal * monthlyInterest * pow(1 + monthlyInterest, months) / (pow(1 + monthlyInterest, months) - 1);
    return mortgage;
}

int main() {
    int principal, years;
    float interestRate;
    printf("Enter principal amount: ");
    scanf("%d", &principal);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter number of years: ");
    scanf("%d", &years);
    float mortgage = calculateMortgage(principal, interestRate, years);
    printf("Your monthly mortgage payment is $%.2f\n", mortgage);
    return 0;
}