//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: distributed
#include <stdio.h>

// function to calculate monthly mortgage payment
double calculateMonthlyPayment(double principle, double rate, int years) {
    double monthlyRate = rate/1200; // monthly interest rate
    int numPayments = years*12; // total number of payments
    double monthlyPayment = (principle*monthlyRate)/(1 - pow(1+monthlyRate, -1*numPayments)); // formula for monthly payment
    return monthlyPayment;
}

int main() {
    double principle, rate, monthlyPayment;
    int years;
    
    // get user input
    printf("Enter principle amount: ");
    scanf("%lf", &principle);
    printf("Enter interest rate (APR): ");
    scanf("%lf", &rate);
    printf("Enter number of years: ");
    scanf("%d", &years);
    
    monthlyPayment = calculateMonthlyPayment(principle, rate, years); // calculate monthly payment
    printf("Your monthly mortgage payment is: $%.2lf", monthlyPayment);
    
    return 0;
}