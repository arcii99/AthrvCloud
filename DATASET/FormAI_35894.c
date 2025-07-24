//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: lively
#include <stdio.h>

int main() {
    float principal, rate, time, interest, total_amount;

    printf("Welcome to the Mortgage Calculator!\n");
    printf("Please enter the principal amount: ");
    scanf("%f", &principal);

    printf("Please enter the interest rate: ");
    scanf("%f", &rate);

    printf("Please enter the time period (in years): ");
    scanf("%f", &time);

    interest = (principal * rate * time) / 100;
    total_amount = principal + interest;

    printf("\nThank you! Here are the results:\n");
    printf("Principal Amount: $%.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", rate);
    printf("Time Period: %.2f years\n", time);
    printf("Interest: $%.2f\n", interest);
    printf("Total Amount: $%.2f\n", total_amount);

    return 0;
}