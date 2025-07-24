//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complete
#include <stdio.h>
#include <math.h>

int main()
{
    // mortgage inputs
    float loanAmt, interestRate, monthlyPayment, totalPayment;
    int loanTerm;

    // user inputs
    printf("Enter the loan amount: $");
    scanf("%f", &loanAmt);

    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interestRate);

    printf("Enter the loan term (in years): ");
    scanf("%d", &loanTerm);

    // calculations
    float monthlyInterestRate = interestRate / 1200;
    int numPayments = loanTerm * 12;

    float temp = pow((1 + monthlyInterestRate), numPayments);
    
    // monthly payment calculation
    monthlyPayment = (loanAmt * monthlyInterestRate * temp) / (temp - 1);

    // total payment calculation
    totalPayment = monthlyPayment * numPayments;

    // output
    printf("\nMORTGAGE CALCULATOR\n");
    printf("Loan Amount: $%.2f\n", loanAmt);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Loan Term: %d years\n", loanTerm);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payment: $%.2f\n", totalPayment);
    printf("Interest Paid: $%.2f\n", totalPayment - loanAmt);

    return 0;
}