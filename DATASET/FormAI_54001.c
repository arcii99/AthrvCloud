//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: imaginative
#include <stdio.h>

int main() {
    float principal, rate, time, emi, interest, total_amount;

    printf("Enter Loan Amount: ");
    scanf("%f", &principal);
    printf("Enter Rate of Interest: ");
    scanf("%f", &rate);
    printf("Enter Time (in years): ");
    scanf("%f", &time);

    // Converting year to month and interest rate to month
    time *= 12;
    rate /= 1200;

    // Calculation of EMI and Interest
    emi = principal * rate * (pow(1 + rate, time) / (pow(1 + rate, time) - 1));
    interest = emi * time - principal;
    total_amount = interest + principal;

    // Displaying Result
    printf("\nEMI: %.2f\n", emi);
    printf("Total Interest: %.2f\n", interest);
    printf("Total Amount Payable: %.2f", total_amount);

    return 0;
}