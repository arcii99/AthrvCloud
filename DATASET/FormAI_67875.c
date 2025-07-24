//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    float principal, rate, time, emi, total_amount, interest_amount;
    int months;

    // Cyberpunk-themed UI
    printf("╔═══╗╔═══╗╔═══╗╔═══╗╔╗───╔═══╗\n");
    printf("║╔══╝║╔═╗║║╔═╗║║╔═╗║║║───║╔══╝\n");
    printf("║╚══╗║║─║║║║─╚╝║║─║║║║───║╚══╗\n");
    printf("║╔══╝║╚═╝║║║╔═╗║║─║║║║───║╔══╝\n");
    printf("║║───║╔═╗║║╚╩═║║╚═╝║║╚═╗─║║───\n");
    printf("╚╝───╚╝─╚╝╚═══╝╚═══╝╚══╝─╚╝───\n");
    printf("  Cyber Mortgage Calculator v1.0  \n\n");

    // Cyberpunk-themed input prompts
    printf("Enter principal amount (in dollars): ");
    scanf("%f", &principal);
    printf("\nEnter interest rate (in percentage): ");
    scanf("%f", &rate);
    printf("\nEnter time period (in months): ");
    scanf("%f", &time);

    rate /= 100;
    months = ceil(time);

    float x = pow(1 + rate, months);
    emi = (principal * x * rate) / (x - 1);
    total_amount = emi * months;
    interest_amount = total_amount - principal;

    // Cyberpunk-themed output
    printf("\nLoan summary:\n");
    printf("  Principal amount: $%.2f\n", principal);
    printf("  Interest rate: %.2f%% per annum\n", rate * 100);
    printf("  Time period: %d months\n", months);
    printf("  Monthly EMI: $%.2f\n\n", emi);
    printf("  Total amount to be paid (with interest): $%.2f\n", total_amount);
    printf("  Interest amount: $%.2f\n", interest_amount);

    return 0;
}