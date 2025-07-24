//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: systematic
#include <stdio.h>
#include <math.h>

int main(){
    float loanAmount, yearlyInterestRate, monthlyInterestRate, numberOfMonths, monthlyPayment, totalPayment, interest;

    // Get the loan amount from the user
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);

    // Get the yearly interest rate from the user
    printf("Enter yearly interest rate: ");
    scanf("%f", &yearlyInterestRate);

    // Get the number of months from the user
    printf("Enter number of months: ");
    scanf("%f", &numberOfMonths);

    // Calculate the monthly interest rate
    monthlyInterestRate = yearlyInterestRate / 1200;
    
    // Calculate the monthly payment
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numberOfMonths));
    
    // Calculate the total payment
    totalPayment = monthlyPayment * numberOfMonths;
    
    // Calculate the total interest
    interest = totalPayment - loanAmount;
    
    // Display the results to the user
    printf("\nLoan amount: $%.2f\n", loanAmount);
    printf("Yearly interest rate: %.2f%%\n", yearlyInterestRate);
    printf("Number of months: %.0f\n", numberOfMonths);
    printf("Monthly payment: $%.2f\n", monthlyPayment);
    printf("Total payment: $%.2f\n", totalPayment);
    printf("Total interest: $%.2f\n", interest);

    return 0;
}