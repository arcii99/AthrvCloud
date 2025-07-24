//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>
#include <math.h>

int main() {
    float loanAmount, interestRate, monthlyPayment, totalPayment;
    int loanTermInYears;

    printf("Welcome to our Mortgage Calculator!\n");

    printf("Please enter the loan amount: ");
    scanf("%f", &loanAmount);

    printf("Please enter the interest rate: ");
    scanf("%f", &interestRate);

    printf("Please enter the loan term (in years): ");
    scanf("%d", &loanTermInYears);

    // Convert interest rate to decimal form.
    interestRate /= 100.0;

    // Convert loan term to number of monthly payments.
    int numberOfPayments = loanTermInYears * 12;

    // Calculate the monthly payment using formula:
    // M = P * ((r(1+r)^n) / ((1+r)^n - 1))
    float monthlyInterestRate = interestRate / 12.0;
    float numerator = monthlyInterestRate * pow(1.0 + monthlyInterestRate, (float)numberOfPayments);
    float denominator = pow(1.0 + monthlyInterestRate, (float)numberOfPayments) - 1.0;
    monthlyPayment = loanAmount * (numerator / denominator);

    // Calculate the total payment over the entire loan term.
    totalPayment = monthlyPayment * numberOfPayments;

    // Print the monthly payment and total payment.
    printf("\nMonthly Payment: %.2f\n", monthlyPayment);
    printf("Total Payment: %.2f\n", totalPayment);

    return 0;
}