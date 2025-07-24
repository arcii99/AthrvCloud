//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to calculate monthly mortgage payments
double calculateMortgage(double principal, double interest, int years) {
    double monthlyInterest = interest / 1200; // convert annual interest to monthly interest
    int months = years * 12; // convert years to months
    double monthlyPayment = (principal * monthlyInterest) / (1 - pow(1 + monthlyInterest, -months));
    return monthlyPayment;
}

int main() {
    double principal, interest;
    int years;

    printf("----- Welcome to the Mortgage Calculator! -----\n\n");
    
    // take user input for variables
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the annual interest rate: ");
    scanf("%lf", &interest);
    printf("Enter the loan period (in years): ");
    scanf("%d", &years);

    // calculate monthly mortgage payment using the function
    double monthlyPayment = calculateMortgage(principal, interest, years);

    // print the monthly mortgage payment
    printf("\nYour monthly mortgage payment is: $%.2lf\n", monthlyPayment);

    return 0;
}