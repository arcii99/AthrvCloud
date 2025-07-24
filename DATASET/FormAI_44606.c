//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate monthly mortgage payment
double calculateMortgagePayment(double principal, double rate, int numOfPayments) {
    double monthlyRate = rate / (12.0 * 100.0); // Calculate monthly interest rate
    double term = pow((1.0 + monthlyRate), numOfPayments); // Calculate term value
    double monthlyPayment = (principal * monthlyRate * term) / (term - 1.0); // Calculate monthly payment
    return monthlyPayment;
}

// Function to print amortization table
void printAmortizationTable(double principal, double rate, int numOfPayments, double monthlyPayment) {
    double monthlyRate = rate / (12.0 * 100.0); // Calculate monthly interest rate
    double principalBalance = principal; // Set initial principal balance
    double totalInterestPaid = 0.0; // Set initial total interest paid

    // Print table header
    printf("%-15s %-15s %-15s %-15s\n", "Payment", "Interest", "Principal", "Balance");

    // Loop through payments and print details for each payment
    for (int i = 1; i <= numOfPayments; i++) {
        double interestPaid = principalBalance * monthlyRate; // Calculate interest paid
        double principalPaid = monthlyPayment - interestPaid; // Calculate principal paid

        // Update principal balance and total interest paid
        principalBalance -= principalPaid;
        totalInterestPaid += interestPaid;

        // Print payment details
        printf("$%-14.2f $%-14.2f $%-14.2f $%-14.2f\n", monthlyPayment, interestPaid, principalPaid, principalBalance);

        // Check if final payment has been reached and print final details
        if (i == numOfPayments) {
            double finalPayment = principalBalance + interestPaid; // Calculate final payment
            printf("$%-14.2f $%-14.2f $%-14.2f $%-14.2f\n", finalPayment, interestPaid, principalBalance, 0.0);
        }
    }

    // Print total interest paid
    printf("\nTotal interest paid: $%.2f\n", totalInterestPaid);
}

int main() {
    double principal, rate;
    int numOfYears;

    // Get input from user
    printf("Enter mortgage principal: ");
    scanf("%lf", &principal);
    printf("Enter annual interest rate: ");
    scanf("%lf", &rate);
    printf("Enter number of years for mortgage: ");
    scanf("%d", &numOfYears);

    // Calculate number of payments
    int numOfPayments = numOfYears * 12;

    // Calculate monthly mortgage payment and print
    double monthlyPayment = calculateMortgagePayment(principal, rate, numOfPayments);
    printf("\nMonthly mortgage payment: $%.2f\n", monthlyPayment);

    // Print amortization table
    printAmortizationTable(principal, rate, numOfPayments, monthlyPayment);

    return 0;
}