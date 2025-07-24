//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: future-proof
#include <stdio.h>
#include <math.h>

double calculateMonthlyPayment(double principal, double interestRate, int numOfYears);

int main() {
    double principal, interestRate, monthlyPayment;
    int numOfYears;
    
    printf("*** Mortgage Calculator ***\n\n");
    
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    
    printf("Enter the interest rate (in percentage): ");
    scanf("%lf", &interestRate);
    
    printf("Enter the number of years: ");
    scanf("%d", &numOfYears);
    
    monthlyPayment = calculateMonthlyPayment(principal, interestRate/100, numOfYears);
    
    printf("\nYour monthly payment is $%.2lf\n", monthlyPayment);
    
    return 0;
}

double calculateMonthlyPayment(double principal, double interestRate, int numOfYears) {
    double monthlyRate = interestRate / 12;
    int numOfMonths = numOfYears * 12;
    
    return (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -numOfMonths));
}