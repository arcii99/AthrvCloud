//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>

int main()
{
    printf("\n----------------------------------------------------");
    printf("\n                Mortgage Calculator");
    printf("\n----------------------------------------------------\n\n");

    float principal, rate, payment;
    int years;

    printf("Enter the Loan Amount: ");
    scanf("%f", &principal);
    printf("Enter the Annual Interest Rate (in percentage): ");
    scanf("%f", &rate);
    printf("Enter the Loan Term (in years): ");
    scanf("%d", &years);

    rate = rate / 100 / 12;  // Convert annual rate to monthly rate
    int n = years * 12;  // Number of monthly payments

    // Calculate the monthly payment
    payment = (principal * rate) * pow(1 + rate, n) / (pow(1 + rate, n) - 1);

    printf("\n----------------------------------------------------");
    printf("\n                     Loan Summary");
    printf("\n----------------------------------------------------\n\n");
    printf("Loan Amount: $%.2f\n", principal);
    printf("Annual Interest Rate: %.2f %%\n", rate * 100 * 12);
    printf("Loan Term: %d Years\n", years);
    printf("Number of Monthly Payments: %d\n", n);
    printf("Monthly Payment: $%.2f\n\n", payment);

    return 0;
}