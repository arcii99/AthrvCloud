//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: careful
#include <stdio.h>
#include <math.h>

int main() {

    double loanAmount, rate, monthlyInterest, monthlyPayment, totalPayment, balance;
    int numPayments, month;
    
    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);
    
    printf("Enter interest rate per year (percent): ");
    scanf("%lf", &rate);
    
    printf("Enter number of payments: ");
    scanf("%d", &numPayments);
    
    // Convert interest rate to monthly equivalent
    monthlyInterest = rate / (12.0 * 100);
    
    // Calculate monthly payment
    monthlyPayment = (loanAmount * monthlyInterest) / (1 - pow(1 + monthlyInterest, -numPayments));
    
    // Print monthly payment amount  
    printf("\nMonthly Payment: $%.2lf\n", monthlyPayment);
    
    // Calculate total payment and interest
    totalPayment = monthlyPayment * numPayments;
    double totalInterest = totalPayment - loanAmount;
    
    // Print total payment and interest  
    printf("Total Payment: $%.2lf\n", totalPayment);
    printf("Total Interest: $%.2lf\n\n", totalInterest);
    
    balance = loanAmount;
    
    // Print amortization table
    printf("Amortization Table:\n");
    printf("Month  Payment     Interest     Principal     Balance\n");
    
    for(month = 1; month <= numPayments; month++) {
        double interestAmount = balance * monthlyInterest;
        double principalAmount = monthlyPayment - interestAmount;
        balance -= principalAmount;
        printf("%d     $%.2lf      $%.2lf      $%.2lf      $%.2lf\n", month, monthlyPayment, interestAmount, principalAmount, balance);
    }
    
    return 0;
}