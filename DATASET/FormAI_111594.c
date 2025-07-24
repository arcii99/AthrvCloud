//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: optimized
#include <stdio.h>

int main() {
    double loanAmount, interestRate, monthlyPayment, balance, totalInterest;
    int numberOfYears, numberOfMonths;
    
    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmount);
    
    printf("Enter the interest rate (per year): ");
    scanf("%lf", &interestRate);
    
    printf("Enter the number of years: ");
    scanf("%d", &numberOfYears);
    
    numberOfMonths = numberOfYears * 12;
    double monthlyRate = interestRate / 1200;
    balance = loanAmount;
    totalInterest = 0;
    
    printf("\n");
    printf("Loan Amount: $%.2f\n", loanAmount);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Number of Years: %d\n", numberOfYears);
    printf("------------------------------------\n");
    printf("Monthly payment\t\t\tBalance\t\t\tInterest\n");
    printf("------------------------------------\n");
    
    for(int i = 1; i <= numberOfMonths; i++) {
        monthlyPayment = loanAmount * monthlyRate / (1 - 1 / pow(1 + monthlyRate, numberOfMonths - i + 1));
        balance -= monthlyPayment - balance * monthlyRate;
        totalInterest += monthlyPayment - balance * monthlyRate;
        printf("$%.2f\t\t\t\t$%.2f\t\t\t\t$%.2f\n", monthlyPayment, balance, totalInterest);
    }
    
    printf("------------------------------------\n");
    printf("Total interest paid: $%.2f\n", totalInterest);
    printf("Total amount paid: $%.2f\n", totalInterest + loanAmount);
    
    return 0;
}