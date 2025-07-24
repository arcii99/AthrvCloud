//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Alan Touring
// This is a Mortgage Calculator program written in C using Alan Touring style
// The program calculates the monthly payment for a mortgage based on user inputs

#include <stdio.h>
#include <math.h>

int main(void) {

    // declare variables
    double loanAmount, interestRate, monthlyPayment, balance, principal, interest;
    int numPayments, monthCount;

    // get user inputs
    printf("Enter the loan amount: $");
    scanf("%lf", &loanAmount);
    printf("Enter the interest rate (as decimal): ");
    scanf("%lf", &interestRate);
    printf("Enter the number of payments: ");
    scanf("%d", &numPayments);

    // calculate monthly payment
    double rate = interestRate / 12; // monthly interest rate
    double temp = pow((1 + rate), numPayments); // temporary variable for calculation
    monthlyPayment = (loanAmount * rate * temp) / (temp - 1); // formula to calculate monthly payment

    // print out monthly payment
    printf("Monthly payment: $%.2lf\n", monthlyPayment);

    // print out payment schedule
    balance = loanAmount;
    printf("\nPayment Schedule\n");
    printf("----------------\n");
    printf("Month\tBalance\t\tPayment\t\tPrincipal\tInterest\n");
    monthCount = 1;
    while(balance > 0) {
        interest = balance * rate;
        principal = monthlyPayment - interest;
        balance = balance - principal;
        if (balance < 0) {
            principal = balance + principal;
            balance = 0;
        }
        printf("%d\t$%.2lf\t$%.2lf\t$%.2lf\t\t$%.2lf\n", monthCount, balance, monthlyPayment, principal, interest);
        monthCount++;
    }

    return 0;
}