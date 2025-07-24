//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    double loanAmount, interestRate, monthlyPayment, totalPayment, remainingBalance, interestPaid, principalPaid;
    int numOfYears, numOfMonths;
    
    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmount);
    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);
    printf("Enter the number of years: ");
    scanf("%d", &numOfYears);
    
    numOfMonths = numOfYears * 12;
    interestRate /= 100; // convert interest rate into decimal
    
    monthlyPayment = (loanAmount * interestRate / 12) / (1 - pow((1 + interestRate / 12), -numOfMonths));
    printf("\nMonthly Payment: $%0.2lf", monthlyPayment);
    
    totalPayment = monthlyPayment * numOfMonths;
    printf("\nTotal Payment: $%0.2lf", totalPayment);
    
    remainingBalance = loanAmount;
    printf("\n\nPayment Schedule\nMonth\t\tPayment\t\tInterest\t\tPrincipal\t\tBalance");
    
    for(int i = 1; i <= numOfMonths; i++) {
        interestPaid = remainingBalance * interestRate / 12;
        principalPaid = monthlyPayment - interestPaid;
        remainingBalance -= principalPaid;
        
        printf("\n%d\t\t$%0.2lf\t\t$%0.2lf\t\t$%0.2lf\t\t$%0.2lf", i, monthlyPayment, interestPaid, principalPaid, remainingBalance);
    }
    
    return 0;
}