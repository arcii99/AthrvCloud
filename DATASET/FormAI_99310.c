//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    double loanAmount = 0.0, interestRate = 0.0, numYears = 0.0;
    double monthlyRate = 0.0, monthlyPayment = 0.0, totalPayment = 0.0, totalInterest = 0.0;

    // Get user input for loan amount, interest rate, and the number of years
    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmount);
    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);
    printf("Enter the number of years: ");
    scanf("%lf", &numYears);

    // Calculate the monthly interest rate
    monthlyRate = interestRate / 1200.0;

    // Calculate the number of monthly payments
    int numMonths = numYears * 12;

    // Calculate the monthly payment
    monthlyPayment = (loanAmount * monthlyRate) / (1 - pow(1 + monthlyRate, -numMonths));

    // Calculate the total payment
    totalPayment = monthlyPayment * numMonths;

    // Calculate the total interest
    totalInterest = totalPayment - loanAmount;

    // Print the monthly payment, total payment, and total interest
    printf("Monthly payment: $%.2lf\n", monthlyPayment);
    printf("Total payment: $%.2lf\n", totalPayment);
    printf("Total interest: $%.2lf\n", totalInterest);

    return 0;
}