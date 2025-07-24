//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: single-threaded
#include <stdio.h>

int main() {
    float principal, rate, monthlyRate, totalInterest, monthlyPayment;
    int years, months, totalMonths;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the yearly interest rate: ");
    scanf("%f", &rate);
    printf("Enter the number of years: ");
    scanf("%d", &years);

    totalMonths = years * 12;
    monthlyRate = rate / 1200.0;
    monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -totalMonths));
    totalInterest = monthlyPayment * totalMonths - principal;

    printf("\nMORTGAGE PAYMENT\n");
    printf("================\n");
    printf("Principal Amount:  %.2f\n", principal);
    printf("Interest Rate:     %.2f%%\n", rate);
    printf("Years:             %d\n", years);
    printf("Monthly Payment:   $%.2f\n", monthlyPayment);
    printf("Total Interest:    $%.2f\n", totalInterest);
    printf("Total Payment:     $%.2f\n", principal + totalInterest);

    return 0;
}