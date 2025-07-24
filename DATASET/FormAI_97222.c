//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: invasive
#include <stdio.h>
#include <math.h>

int main()
{
    float loanAmount, interestRate, monthlyPayment, principal, interest, balance;
    int numberOfPayments, paymentNumber;

    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);

    printf("Enter the interest rate: ");
    scanf("%f", &interestRate);

    printf("Enter the number of payments: ");
    scanf("%d", &numberOfPayments);

    interestRate = interestRate / 1200; // monthly interest calculation

    // Calculate the monthly payment
    monthlyPayment = (loanAmount * interestRate * pow(1 + interestRate, numberOfPayments)) / (pow(1 + interestRate, numberOfPayments) - 1);

    // Print the monthly payment
    printf("Monthly payment: $%.2f\n", monthlyPayment);

    // Display the amortization table
    printf("\nAmortization Table\n");
    printf("_____________________________\n");
    printf("Payment#\t Payment\t Interest\t Principal\t Balance\n");
    printf("_____________________________\n");

    balance = loanAmount;
    for (paymentNumber = 1; paymentNumber <= numberOfPayments; paymentNumber++) {
        interest = balance * interestRate;
        principal = monthlyPayment - interest;
        balance -= principal;

        // Print the payment details
        printf("%d\t\t $%.2f\t $%.2f\t\t $%.2f\t\t $%.2f\n", paymentNumber, monthlyPayment, interest, principal, balance);
    }

    return 0;
}