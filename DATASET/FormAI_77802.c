//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: modular
#include<stdio.h>
#include<math.h>

double calculateMonthlyPayment(double loanAmount, double interestRate, int term)
{
    double monthlyRate = interestRate / 1200;
    double monthlyPayment = (loanAmount * monthlyRate) / (1 - pow(1 + monthlyRate, -term));
    return monthlyPayment;
}

double calculateTotalInterest(double loanAmount, double monthlyPayment, int term)
{
    double totalInterest = (monthlyPayment * term) - loanAmount;
    return totalInterest;
}

double calculateTotalPayment(double loanAmount, double totalInterest)
{
    double totalPayment = loanAmount + totalInterest;
    return totalPayment;
}

int main()
{
    double loanAmount = 0.0;
    double interestRate = 0.0;
    int term = 0;
    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);
    printf("Enter interest rate: ");
    scanf("%lf", &interestRate);
    printf("Enter term in months: ");
    scanf("%d", &term);

    double monthlyPayment = calculateMonthlyPayment(loanAmount, interestRate, term);
    double totalInterest = calculateTotalInterest(loanAmount, monthlyPayment, term);
    double totalPayment = calculateTotalPayment(loanAmount, totalInterest);

    printf("Monthly Payment: %.2lf\n", monthlyPayment);
    printf("Total Interest: %.2lf\n", totalInterest);
    printf("Total Payment: %.2lf\n", totalPayment);

    return 0;
}