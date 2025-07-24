//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

int main() {
    double P, r, n, M, total_interest;
    
    printf("Enter the loan amount: ");
    scanf("%lf", &P);
    
    printf("Enter the interest rate: ");
    scanf("%lf", &r);
    
    printf("Enter the number of payments: ");
    scanf("%lf", &n);
    
    r = r / (12 * 100); // converting annual interest rate to monthly rate
    
    M = (P * r * pow(1 + r, n)) / (pow(1 + r, n) - 1); // monthly payment calculation
    
    total_interest = M * n - P; // total interest calculation
    
    printf("\nMonthly Payment = $%.2lf\n", M);
    printf("\nTotal Interest = $%.2lf\n", total_interest);
    
    return 0;
}