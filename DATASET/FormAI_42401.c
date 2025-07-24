//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Alan Touring
//Alan Turing Style Mortgage Calculator

#include <stdio.h>

int main() {
    float principal, rate, monthRate, payment, balance;
    int months, paymentCount;

    printf("Please enter the principal amount: ");
    scanf("%f", &principal);

    printf("\nPlease enter the interest rate (in percentage): ");
    scanf("%f", &rate);
    monthRate = rate / 1200.0;

    printf("\nPlease enter the length of the loan in months: ");
    scanf("%d", &months);

    payment = (principal * monthRate) / (1 - (pow(1 + monthRate, -months)));
    printf("\nMonthly Payment: %.2f", payment);

    paymentCount = 0;
    balance = principal;
    printf("\nPayment#\tPayment\t\tBalance\n");
    while (balance > 0) {
        paymentCount++;
        float interest = balance * monthRate;
        float principalPaid = payment - interest;
        balance = balance - principalPaid;

        if (balance < 0) {
            balance = 0;
        }

        printf("%d\t\t%.2f\t\t%.2f\n", paymentCount, payment, balance);
    }

    return 0;
}