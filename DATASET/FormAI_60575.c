//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: recursive
#include <stdio.h>
#include <math.h>

double calculateMortgage(double amount, double interest, int years, int paymentNumber) {
    if (years == 0) { // base case: no more years to calculate
        return amount; // return the remaining mortgage amount
    } else {
        double monthlyInterest = pow((1 + interest), (1.0 / 12.0)) - 1; // calculate monthly interest rate
        double paymentAmount = (amount * monthlyInterest) / (1 - pow((1 + monthlyInterest), (-1 * paymentNumber))); // calculate payment amount
        double newAmount = amount - paymentAmount + (amount * monthlyInterest); // calculate remaining mortgage amount
        printf("Year %d, month %d => Payment amount: $%.2f, Remaining amount: $%.2f\n", (int)(12 - years), paymentNumber, paymentAmount, newAmount);
        return calculateMortgage(newAmount, interest, years - 1, paymentNumber + 1); // recursive call with new remaining mortgage, decreased years, and increased payment number
    }
}

int main() {
    double mortgageAmount, interestRate;
    int mortgageYears;
    
    printf("Enter mortgage amount: ");
    scanf("%lf", &mortgageAmount);
    printf("Enter interest rate: ");
    scanf("%lf", &interestRate);
    printf("Enter number of years for mortgage: ");
    scanf("%d", &mortgageYears);
    
    printf("Monthly payments:\n");
    calculateMortgage(mortgageAmount, interestRate / 100, mortgageYears, 1);
    
    return 0;
}