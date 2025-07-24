//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include <stdio.h>

// Function prototype for Mortgage calculator 
void mortgageCalculator(double loanAmount, int years, double interestRate);

int main() {
    double loanAmount, interestRate;
    int years;
    char choice;
    do {
        printf("\n Welcome to the Shape Shifting Mortgage Calculator. ");
        printf("\n\n Enter the Loan Amount($) : ");
        scanf("%lf", &loanAmount);
        printf("\n Enter the Interest Rate : ");
        scanf("%lf", &interestRate);
        printf("\n Enter the Years : ");
        scanf("%d", &years);
        
        // Function call to calculate mortgage
        mortgageCalculator(loanAmount, years, interestRate);

        printf("\n\n Do you want to exit the program ? (y/n) : ");
        scanf(" %c", &choice);
    } while(choice != 'y' && choice != 'Y');
    
    return 0;
}

// The function to calculate the monthly mortgage payment
void mortgageCalculator(double loanAmount, int years, double interestRate) {
    float monthlyPayment;
    int months;
    
    printf("\n\n Your input values :");
    printf("\n\n Loan Amount : $%lf", loanAmount);
    printf("\n Interest Rate : %.2lf%%", interestRate);
    printf("\n No. of Years : %d", years);
    
    months = years * 12;
    interestRate = interestRate/(12*100);
    monthlyPayment = (loanAmount*interestRate*pow(1+interestRate,months))/(pow(1+interestRate,months)-1);
    
    printf("\n\n Your monthly payment is : $%.2f", monthlyPayment);
}