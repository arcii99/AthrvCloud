//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: safe
#include <stdio.h>
#include <math.h>

int main() {
    // Declare the necessary variables
    float principal, interest, monthlyPayment, monthlyInterest, totalInterest, totalPayment;
    int term;

    // Get the input from the user
    printf("Enter the loan amount (principal): ");
    scanf("%f", &principal);

    printf("Enter the interest rate (annual): ");
    scanf("%f", &interest);

    printf("Enter the loan term (in years): ");
    scanf("%d", &term);

    // Calculate the monthly interest rate
    monthlyInterest = (interest / 100) / 12;

    // Calculate the monthly payment
    monthlyPayment = principal * (monthlyInterest / (1 - pow(1 + monthlyInterest, -term * 12)));

    // Calculate the total payment and total interest
    totalPayment = monthlyPayment * term * 12;
    totalInterest = totalPayment - principal;

    // Display the results
    printf("\n\nMortgage Payment Calculator\n\n");
    printf("Loan Amount: %.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", interest);
    printf("Loan Term: %d years\n", term);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payment: $%.2f\n", totalPayment);
    printf("Total Interest: $%.2f\n", totalInterest);

    return 0;
}