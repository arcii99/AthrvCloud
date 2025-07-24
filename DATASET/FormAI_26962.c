//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: expert-level
#include <stdio.h>
#include <math.h>

void printMortgageTable(float P, float r, int n) {
    float A, B, C, d;
    A = P * r / 12;

    printf("%-10s%-20s%-20s%-20s%-20s\n", "Month", "Payment", "Principal Paid", "Interest Paid", "Remaining Balance");
    printf("%-10s%-20s%-20s%-20s%-20s\n", "-----", "-------", "--------------", "-------------", "-----------------");

    for (int i = 1; i <= n; i++) {
        B = P * r / 12;
        C = A - B;
        d = P - C;
        printf("%-10d%-20.2f%-20.2f%-20.2f%-20.2f\n", i, A, C, B, d);
        P = d;
    }
}

float calculateMortgage(float P, float r, int n) {
    float A, B, C, d;
    A = P * r / 12;
    B = pow(1 + r/12, n);
    C = B - 1;
    d = A * B / C;
    return d;
}

int main() {
    float principal, annualRate;
    int years;

    printf("Enter the loan amount: ");
    scanf("%f", &principal);
    printf("Enter the annual interest rate: ");
    scanf("%f", &annualRate);
    printf("Enter the number of years of the mortgage: ");
    scanf("%d", &years);

    float monthlyRate = annualRate / 100 / 12;

    float monthlyPayment = calculateMortgage(principal, monthlyRate, years*12);
    printf("\nMonthly payment: %.2f\n", monthlyPayment);

    printMortgageTable(principal, monthlyRate, years*12);

    return 0;
}