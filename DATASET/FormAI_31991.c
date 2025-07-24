//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: intelligent
#include <stdio.h>

int main() {
    float P, r, n, m, EMI, total_amount;
    printf("Enter the loan amount: ");
    scanf("%f", &P);
    printf(" Enter the interest rate (in percentage): ");
    scanf("%f", &r);
    printf(" Enter the number of years: ");
    scanf("%f", &n);
    printf(" Enter the number of payments per year: ");
    scanf("%f", &m);

    float R = (r/100)/m;
    float N = n*m;

    EMI = (P*R*pow(1+R,N))/(pow(1+R,N)-1);
    total_amount = EMI*N;

    printf("Loan amount: $%.2f\n", P);
    printf("Interest rate: %.2f%%\n", r);
    printf("Loan duration: %.0f years\n", n);
    printf("Number of payments per year: %.0f\n", m);
    printf("EMI: $%.2f\n", EMI);
    printf("Total amount payable: $%.2f\n", total_amount);

    return 0;
}