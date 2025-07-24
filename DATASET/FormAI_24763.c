//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>

int main() {
    double loanAmount, interestRate, monthlyPayment, totalPayment, balance;
    int numMonths, i = 1;
    
    // Get user input
    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);
    
    printf("Enter interest rate: ");
    scanf("%lf", &interestRate);
    
    printf("Enter loan period in months: ");
    scanf("%d", &numMonths);
    
    // Calculate monthly payment
    double temp = pow((1 + (interestRate / 1200)), numMonths);
    monthlyPayment = (loanAmount * interestRate * temp) / (1200 * (temp - 1));
    
    // Print out payment plan
    printf("\nPayment Plan:\n");
    printf("| %5s | %10s | %10s | %10s |\n", "Month", "Payment", "Balance", "Total Payment");
    
    balance = loanAmount;
    
    while(i <= numMonths) {
        double interest = (interestRate / 1200) * balance;
        balance = balance - (monthlyPayment - interest);
        totalPayment += monthlyPayment;
        printf("| %5d | $%9.2lf | $%9.2lf | $%9.2lf |\n", i, monthlyPayment, balance, totalPayment);
        i++;
    }
    
    return 0;
}