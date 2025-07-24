//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: romantic
#include <stdio.h>

int main() {
    double principal, rate, term, monthlyPayment, totalPayment, interest;

    printf("My love, let's plan our future together! \n"
           "Let's see how much we can borrow and the monthly payments with this mortgage calculator.\n\n");

    printf("What's the principal amount we need to borrow? (in dollars) \n");
    scanf("%lf", &principal);

    printf("\nHow many years is the mortgage? \n");
    scanf("%lf", &term);

    printf("\nWhat's the annual interest rate in percentage? \n");
    scanf("%lf", &rate);

    // Convert rate to decimal and calculate monthly rate
    rate = rate / 100.0;
    double monthlyRate = rate / 12.0;

    // Calculate monthly payment and total payment
    monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -term * 12));
    totalPayment = monthlyPayment * term * 12;

    // Calculate total interest paid
    interest = totalPayment - principal;

    printf("\nI'm so excited to share this with you! Here are the details:\n\n"
           "The monthly payment will be: $%.2lf\n"
           "The total payment over %0.0lf years will be: $%.2lf\n"
           "The total interest paid over the life of the mortgage will be: $%.2lf\n",
           monthlyPayment, term, totalPayment, interest);

    printf("\nWow! Our future looks amazing together! Let's start looking for houses!\n");

    return 0;
}