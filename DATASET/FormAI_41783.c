//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: modular
#include <stdio.h>
#include <math.h>

// function to calculate monthly mortgage payment
double calculateMonthlyPayment(double loanAmount, double interestRate, double loanTerm) {
    double monthlyInterestRate = interestRate / 1200.0;
    double numerator = loanAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, loanTerm);
    double denominator = pow(1 + monthlyInterestRate, loanTerm) - 1;
    double monthlyPayment = numerator / denominator;
    return monthlyPayment;
}

// function to calculate total payment over the length of the mortgage
double calculateTotalPayment(double monthlyPayment, double loanTerm) {
    double totalPayment = monthlyPayment * loanTerm;
    return totalPayment;
}

// main function
int main() {
    double loanAmount, interestRate, loanTerm;
    printf("Enter your loan amount (in dollars): ");
    scanf("%lf", &loanAmount);
    printf("Enter the interest rate (in percentage): ");
    scanf("%lf", &interestRate);
    printf("Enter the loan term (in years): ");
    scanf("%lf", &loanTerm);
    
    // calculate monthly payment and total payment
    double monthlyPayment = calculateMonthlyPayment(loanAmount, interestRate, loanTerm);
    double totalPayment = calculateTotalPayment(monthlyPayment, loanTerm);
    
    // display results
    printf("Your monthly payment is $%.2lf.\n", monthlyPayment);
    printf("Your total payment over %0.0lf years is $%.2lf.\n", loanTerm, totalPayment);
    
    return 0;
}