//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Loan Calculator of the Middle Ages!\n");

    double loanAmount, interestRate, monthlyPayment, balanceDue;
    int numYears;

    printf("Please enter the loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Please enter the interest rate (in percentage): ");
    scanf("%lf", &interestRate);

    printf("Please enter the number of years for the loan repayment: ");
    scanf("%d", &numYears);

    balanceDue = loanAmount;

    printf("\n");

    printf("Loan amount: %lf\n", loanAmount);
    printf("Interest rate: %lf%%\n", interestRate);
    printf("Number of years: %d\n", numYears);

    printf("\n");

    printf("YEAR    BALANCE   PAYMENT   INTEREST   PRINCIPAL\n");

    int i;
    for(i=1; i<= numYears; i++)
    {
        printf("%d      %0.2lf       ", i, balanceDue);

        // Calculate monthly payment
        double numPayments = numYears * 12;
        double monthlyInterestRate = (interestRate / 100) / 12;
        monthlyPayment = (loanAmount * (monthlyInterestRate * pow((1 + monthlyInterestRate), numPayments))) / (pow((1 + monthlyInterestRate), numPayments) - 1);
        printf("%0.2lf         ", monthlyPayment);

        // Calculate interest and principal
        double interest = balanceDue * (interestRate / 100);
        double principal = monthlyPayment - interest;

        printf("%0.2lf         %0.2lf\n", interest, principal);

        balanceDue -= principal;
    }

    return 0;
}