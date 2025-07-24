//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the monthly payment
double monthlyPayment(double principle, double interestRate, int years) {
    double monthlyInterestRate = interestRate / 1200.0; // 12 months in a year, convert percentage to decimal
    int numberOfPayments = years * 12; // convert years to months
    double monthlyPayment = (principle * monthlyInterestRate) / (1 - pow((1 + monthlyInterestRate), -numberOfPayments));
    return monthlyPayment;
}

int main() {
    printf("Welcome to the Mortgage Calculator Game!\n");
    printf("Enter the principle amount: ");
    double principle;
    scanf("%lf", &principle);
    printf("Enter the interest rate: ");
    double interestRate;
    scanf("%lf", &interestRate);
    printf("Enter the number of years for the loan: ");
    int years;
    scanf("%d", &years);
    
    double monthlyPaymentAmount = monthlyPayment(principle, interestRate, years);
    printf("Your monthly payment amount is: %.2lf\n", monthlyPaymentAmount);
    
    printf("Enter your guess for the total amount paid over the life of the loan: ");
    double guess;
    scanf("%lf", &guess);
    
    // Check if guess is correct
    double totalPaid = monthlyPaymentAmount * (years * 12);
    if (guess == totalPaid) {
        printf("Congratulations, you guessed correctly!\n");
    } else {
        printf("Sorry, your guess was incorrect. The total amount paid over the life of the loan is %.2lf\n", totalPaid);
    }
    
    return 0;
}