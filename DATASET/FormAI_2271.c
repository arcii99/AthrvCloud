//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    float amount, rate, monthly, payment, balance;

    printf("Welcome to the Happy Home Mortgage Calculator!\n\n");

    // get loan amount
    printf("Enter your loan amount: ");
    scanf("%f", &amount);

    // get interest rate
    printf("Enter your interest rate (as a decimal): ");
    scanf("%f", &rate);

    // get loan term
    int years;
    printf("Enter your loan term (in years): ");
    scanf("%d", &years);
    int months = years * 12;

    // calculate monthly payment
    rate /= 12;     // monthly interest rate
    monthly = amount * (rate * pow(1 + rate, months)) / (pow(1 + rate, months) - 1);

    printf("\nYour monthly payment is: $%.2f\n", monthly);

    // display payment schedule
    printf("\nPayment Schedule:\n");
    printf("Month\tPayment\t\tBalance\n");

    balance = amount;
    for (int i = 1; i <= months; i++) {
        payment = monthly;
        float interest = balance * rate;
        float principal = payment - interest;
        balance -= principal;
        printf("%d\t$%.2f\t$%.2f\n", i, payment, balance);
    }

    printf("\nThank you for using the Happy Home Mortgage Calculator!\n");
    return 0;
}