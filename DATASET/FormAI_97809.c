//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: happy
#include<stdio.h>

int main(){
    printf("Welcome to the Happy Home Mortgage Calculator!! :D\n");
    float loanAmount, interestRate, monthlyPayment, totalInterest, totalAmountPaid;
    int mortgageTerm;
    
    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);
    
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &interestRate);
    interestRate /= 1200; // Converting the percentage to monthly decimal value
    
    printf("Enter the mortgage term (in years): ");
    scanf("%d", &mortgageTerm);
    int numOfMonths = mortgageTerm * 12; // Converting the years to months
    
    // Calculating the monthly payment
    float numerator = loanAmount * interestRate * pow((1 + interestRate), numOfMonths);
    float denominator = pow((1 + interestRate), numOfMonths) - 1;
    monthlyPayment = numerator / denominator;
    
    // Calculating total amount paid and total interest
    totalAmountPaid = monthlyPayment * numOfMonths;
    totalInterest = totalAmountPaid - loanAmount;
    
    printf("\n\n***********************************************************\n");
    printf("                          RESULTS\n");
    printf("***********************************************************\n");
    printf("Loan Amount:            $%.2f\n", loanAmount);
    printf("Annual Interest Rate:    %.2f%%\n", interestRate*1200);
    printf("Mortage Term:             %d years\n", mortgageTerm);
    printf("Monthly Payment:        $%.2f\n", monthlyPayment);
    printf("Total Interest:         $%.2f\n", totalInterest);
    printf("Total Amount Paid:      $%.2f\n", totalAmountPaid);
    
    printf("\n\nThank you for using the Happy Home Mortgage Calculator!! :D\n");
    return 0;
}