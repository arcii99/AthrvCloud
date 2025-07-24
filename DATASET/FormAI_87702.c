//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
#include<stdio.h>
#include<math.h>

// This program calculates the monthly payment and total interest paid on a mortgage

int main()
{
    double loanAmt, interestRate, numYears, monthlyPayment, totalInterest;
    int numPayments;

    // prompt user for loan amount, interest rate and number of years
    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmt);
    printf("\nEnter the interest rate (as a decimal): ");
    scanf("%lf", &interestRate);
    printf("\nEnter the number of years: ");
    scanf("%lf", &numYears);

    // calculate monthly interest rate
    double monthlyRate = interestRate/12.0;

    // calculate number of payments
    numPayments = numYears * 12;

    // calculate monthly payment using formula
    monthlyPayment = (loanAmt * monthlyRate) / (1.0 - pow((1.0 + monthlyRate), -numPayments));

    // calculate total interest paid using formula
    totalInterest = (monthlyPayment * numPayments) - loanAmt;

    // print results
    printf("\n\nMonthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Interest Paid: $%.2lf\n", totalInterest);

    return 0;
}