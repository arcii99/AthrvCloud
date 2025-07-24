//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: active
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, time, monPay, totalInterest, totalAmt;
    int numPayments;

    printf("Enter the loan amount (principal): ");
    scanf("%f", &principal);

    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &rate);

    printf("Enter the loan term (in years): ");
    scanf("%f", &time);

    // Convert annual interest rate to monthly interest rate
    rate = rate / 1200;

    // Calculate total number of payments
    numPayments = time * 12;

    // Calculate monthly payment
    monPay = (principal * rate * pow(1 + rate, numPayments)) / (pow(1 + rate, numPayments) - 1);

    // Calculate total amount paid back
    totalAmt = monPay * numPayments;

    // Calculate total interest paid
    totalInterest = totalAmt - principal;

    printf("\nMonthly Payment: $%.2f\n", monPay);
    printf("Total Amount Paid Back: $%.2f\n", totalAmt);
    printf("Total Interest Paid: $%.2f\n", totalInterest);

    return 0;
}