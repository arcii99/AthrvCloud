//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: excited
#include <stdio.h>

int main() {
    printf("\t\tWELCOME TO MORTGAGE CALCULATOR!\n\n");

    float principle, rate, years;

    printf("Enter the principle amount: ");
    scanf("%f", &principle);

    printf("Enter the interest rate in percentage: ");
    scanf("%f", &rate);

    printf("Enter the number of years: ");
    scanf("%f", &years);

    float monthly_rate = rate / 1200.0;
    float months = years * 12;
    float monthly_payment = (principle * monthly_rate) / (1.0 - powf(1.0 + monthly_rate, -months));

    printf("\n\nPRINCIPLE AMOUNT: %.2f\n", principle);
    printf("INTEREST RATE: %.2f%%\n", rate);
    printf("NUMBER OF YEARS: %.2f\n", years);
    printf("MONTHLY PAYMENT: $%.2f\n", monthly_payment);
    printf("TOTAL PAYMENT: $%.2f\n", monthly_payment * months);

    printf("\nThank you for using Mortgage Calculator!\n");

    return 0;
}