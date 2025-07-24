//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include<stdio.h>
#include<stdlib.h>

// Function to calculate monthly payments
double monthlyPayment(double loanAmt, double annualIntRate, int numMonths) {
    // Calculate monthly interest rate
    double monthlyIntRate = annualIntRate / 12;

    // Calculate monthly payment
    double numerator = loanAmt * monthlyIntRate;
    double denominator = 1 - pow(1 + monthlyIntRate, -numMonths);
    return numerator / denominator;
}

// Function to display payment schedule
void displayPaymentSchedule(double loanAmt, double annualIntRate, int numMonths) {
    // Calculate monthly payment
    double monthlyAmt = monthlyPayment(loanAmt, annualIntRate, numMonths);

    // Display monthly payment
    printf("Monthly Payment: $%.2lf\n\n", monthlyAmt);

    // Display payment schedule
    printf("Payment Schedule:\n");
    printf("Month\tPayment\t\tInterest\tPrincipal\tBalance\n");

    // Initialize variables
    double remainingBalance = loanAmt;
    for(int i=1; i<=numMonths; i++) {
        double interestAmt = remainingBalance * (annualIntRate / 12);
        double principalAmt = monthlyAmt - interestAmt;
        remainingBalance -= principalAmt;

        // Display payment details
        printf("%d:\t$%.2lf\t\t$%.2lf\t\t$%.2lf\t\t$%.2lf\n", i, monthlyAmt, interestAmt, principalAmt, remainingBalance);
    }
}

// Main function
int main() {
    double loanAmt, annualIntRate;
    int numMonths;

    // Get user input for loan amount, interest rate, and number of months
    printf("Enter loan amount: $");
    scanf("%lf", &loanAmt);

    printf("Enter annual interest rate (as a decimal): ");
    scanf("%lf", &annualIntRate);

    printf("Enter number of months: ");
    scanf("%d", &numMonths);

    // Display payment schedule
    displayPaymentSchedule(loanAmt, annualIntRate, numMonths);

    return 0;
}