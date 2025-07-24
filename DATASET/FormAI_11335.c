//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: unmistakable
#include<stdio.h>
#include<math.h>

int main()
{
    float loanAmount, interestRate, monthlyPayment, totalPayment, totalInterest;
    int loanTerm, months;
    
    printf("\nEnter the loan amount: ");
    scanf("%f", &loanAmount);
    
    printf("\nEnter the interest rate: ");
    scanf("%f", &interestRate);
    
    printf("\nEnter the loan term in years: ");
    scanf("%d", &loanTerm);
    
    // Calculate monthly interest rate
    float monthlyRate = interestRate / (12 * 100);
    
    // Calculate loan term in months
    months = loanTerm * 12;
    
    // Calculate the monthly payment
    monthlyPayment = (loanAmount * monthlyRate * pow(1 + monthlyRate, months)) / (pow(1 + monthlyRate, months) - 1);
    
    printf("\n-----------------------------------------\n");
    printf("Loan Amount:       %.2f\n", loanAmount);
    printf("Interest Rate:     %.2f\n", interestRate);
    printf("Loan Term:         %d years\n", loanTerm);
    printf("-----------------------------------------\n\n");

    printf("Monthly Payment:   %.2f\n", monthlyPayment);
    
    // Calculate total payment and total interest
    totalPayment = monthlyPayment * months;
    totalInterest = totalPayment - loanAmount;
    
    printf("Total Payment:     %.2f\n", totalPayment);
    printf("Total Interest:    %.2f\n", totalInterest);
    
    return 0;
}