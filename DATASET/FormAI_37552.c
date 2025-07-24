//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

int main() {
    double loanAmount, interestRate, monthlyPayment, balance, totalInterest;
    int numPayments;
    
    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);
    printf("Enter interest rate: ");
    scanf("%lf", &interestRate);
    printf("Enter number of payments: ");
    scanf("%d", &numPayments);
    
    double monthlyRate = (interestRate / 12) / 100;
    monthlyPayment = (loanAmount * monthlyRate * pow(1 + monthlyRate, numPayments)) / (pow(1 + monthlyRate, numPayments) - 1);
    balance = loanAmount;
    
    printf("\n\nMonthly Payment: $%.2lf\n", monthlyPayment);
    printf("Payment Schedule\n");
    printf("Month\t Payment\t Balance\n");
    
    for (int i = 1; i <= numPayments; i++) {
        double interestPaid = balance * monthlyRate;
        double principalPaid = monthlyPayment - interestPaid;
        balance = balance - principalPaid;
        totalInterest += interestPaid;
        printf("%d\t $%.2lf\t $%.2lf\n", i, monthlyPayment, balance);
    }
    
    printf("\n\nTotal Interest Paid: $%.2lf", totalInterest);
    
    return 0;
}