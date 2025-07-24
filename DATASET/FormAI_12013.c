//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: relaxed
#include <stdio.h>

int main() {
    float principal, rate, time, emi, interest, totalAmount;
    int months;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate: ");
    scanf("%f", &rate);

    printf("Enter the time in years: ");
    scanf("%f", &time);

    // convert time in years to months
    months = time * 12;

    // convert rate from annual to monthly
    rate = rate / 1200;

    // calculate EMI
    emi = (principal * rate) * pow((1 + rate), months) / (pow((1 + rate), months) - 1);

    // calculate total amount
    totalAmount = emi * months;

    // calculate interest amount
    interest = totalAmount - principal;

    printf("\nMonthly EMI: $%.2f", emi);
    printf("\nTotal Amount: $%.2f", totalAmount);
    printf("\nInterest Amount: $%.2f", interest);

    return 0;
}